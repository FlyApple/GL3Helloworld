
#include "Precompile.h"
#include "D3D11Precompile.h"
#include "D3D11RenderWindow.h"
#include "D3D11RenderSystem.h"

#include "LogManager.h"

//
D3D11RenderWindow::D3D11RenderWindow(void)
{
	//
	m_fX			= 0.0f;
	m_fY			= 0.0f;
	
	m_nColorBits	= 32;
	m_nDepthBits	= 16;
	m_nStencilBits	= 1;

	//
	m_pFactory		= NULL;
	if( CreateDXGIFactory( __uuidof(IDXGIFactory), (void**)(&m_pFactory) ) != S_OK )
	{ 
		throw _T("<CreateDXGIFactory> Initialize error.");
		return;
	}

	//
	m_nFeatureLevel	= D3D_FEATURE_LEVEL_9_1;

	m_pD3D11Device			= NULL;
	m_pD3D11DeviceContext	= NULL;

	m_pSwapChain			= NULL;

	m_pRenderTargetView		= NULL;

	m_pDepthStencil			= NULL;
	m_pDepthStencilView		= NULL;
}

D3D11RenderWindow::~D3D11RenderWindow(void)
{
	if(m_pFactory)
	{
		m_pFactory->Release();
		m_pFactory = NULL;
	}
}

BOOL	D3D11RenderWindow::DestroyRenderWindow()
{
	this->ReleaseD3D11();

	//
	return RenderWindow::DestroyRenderWindow();
}

BOOL	D3D11RenderWindow::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	if(!RenderWindow::LoadRenderWindow(option_values)){ return FALSE; }


	//
	for(StringDictionaryT<ULONG_PTR>::const_iterator i = option_values.begin(); i != option_values.end(); i ++)
	{
		if(_tcsicmp(i->first.c_str(), _T("HANDLE")) == 0)
		{
			m_hWnd	= (HWND)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("X")) == 0)
		{
			m_fX	= (float)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("Y")) == 0)
		{
			m_fY	= (float)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("ColorBits")) == 0)
		{
			m_nColorBits	= (int)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("DepthBits")) == 0)
		{
			m_nDepthBits	= (int)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("StencilBits")) == 0)
		{
			m_nStencilBits	= (int)i->second;
		}
	}

	if(!this->InitializeD3D11())
	{
		return FALSE;
	}
	return TRUE;
}

VOID	D3D11RenderWindow::ReleaseD3D11()
{
	if(m_pDepthStencilView)
	{
		m_pDepthStencilView->Release();
		m_pDepthStencilView = NULL;
	}

	if(m_pDepthStencil)
	{
		m_pDepthStencil->Release();
		m_pDepthStencil = NULL;
	}

	if(m_pRenderTargetView)
	{
		m_pRenderTargetView->Release();
		m_pRenderTargetView = NULL;
	}

	if(m_pSwapChain)
	{
		m_pSwapChain->Release();
		m_pSwapChain = NULL;
	}

	if(m_pD3D11Device)
	{
		m_pD3D11Device->Release();
		m_pD3D11Device = NULL;
	}

	if(m_pD3D11DeviceContext)
	{
		m_pD3D11DeviceContext->Release();
		m_pD3D11DeviceContext = NULL;
	}
}

BOOL	D3D11RenderWindow::InitializeD3D11()
{
	IDXGIAdapter		*pAdapter	= NULL;
	for( int n = 0; ; n ++ )
	{
		IDXGIAdapter	*adapter	= NULL;
		if( m_pFactory->EnumAdapters( n, &adapter ) == DXGI_ERROR_NOT_FOUND )
		{ break; }

		pAdapter	= adapter;
	}

	DXGI_ADAPTER_DESC adapterdesc;
	pAdapter->GetDesc( &adapterdesc );

	//
	D3D_FEATURE_LEVEL	featurelevel[]	= 
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};

	HRESULT hResult = D3D11CreateDevice( pAdapter, D3D_DRIVER_TYPE_UNKNOWN, NULL, 
		0/*D3D11_CREATE_DEVICE_DEBUG*/, featurelevel, 6, D3D11_SDK_VERSION, 
		&m_pD3D11Device, &m_nFeatureLevel, &m_pD3D11DeviceContext ); 
	if( FAILED( hResult ) )
	{ 
		LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("<%s> D3D11CreateDevice() is fail."), __T_FUNCTION__);
		return FALSE; 
	}

	DXGI_SWAP_CHAIN_DESC	desc;
	memset( &desc, 0, sizeof(DXGI_SWAP_CHAIN_DESC) );
	desc.BufferDesc.Width					= (UINT)m_fWidth;
	desc.BufferDesc.Height					= (UINT)m_fHeight;
	desc.BufferDesc.RefreshRate.Numerator	= 60;
	desc.BufferDesc.RefreshRate.Denominator	= 1;
	desc.BufferDesc.Format					= DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count					= 1;
	desc.SampleDesc.Quality					= 0;
	desc.BufferUsage						= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.BufferCount						= 1;
	desc.OutputWindow						= m_hWnd;
	desc.Windowed							= TRUE;
	if( m_pFactory->CreateSwapChain( m_pD3D11Device, &desc, &m_pSwapChain ) != S_OK )
	{
		LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("<%s> m_pFactory->CreateSwapChain() is fail."), __T_FUNCTION__);
		return FALSE;
	}

	// 初始化视图
	ID3D11Texture2D *pTexture2D;
	if( FAILED( m_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&pTexture2D ) ) )
	{
		return FALSE;
	}
	if( FAILED( m_pD3D11Device->CreateRenderTargetView( pTexture2D, NULL, &m_pRenderTargetView ) ) )
	{
		pTexture2D->Release( );
		return FALSE;
	}
	pTexture2D->Release( );

	// Create depth stencil texture
	D3D11_TEXTURE2D_DESC depth_desc;
	ZeroMemory( &depth_desc, sizeof(depth_desc) );
	depth_desc.Width				= desc.BufferDesc.Width;
	depth_desc.Height				= desc.BufferDesc.Height;
	depth_desc.MipLevels			= 1;
	depth_desc.ArraySize			= 1;
	depth_desc.Format				= DXGI_FORMAT_D24_UNORM_S8_UINT;
	depth_desc.SampleDesc.Count		= 1;
	depth_desc.SampleDesc.Quality	= 0;
	depth_desc.Usage				= D3D11_USAGE_DEFAULT;
	depth_desc.BindFlags			= D3D11_BIND_DEPTH_STENCIL;
	depth_desc.CPUAccessFlags		= 0;
	depth_desc.MiscFlags			= 0;
	hResult = m_pD3D11Device->CreateTexture2D( &depth_desc, NULL, &m_pDepthStencil );
	if( FAILED( hResult ) )
	{ 
		return FALSE; 
	}

	// Create the depth stencil view
	D3D11_DEPTH_STENCIL_VIEW_DESC depth_view_desc;
	ZeroMemory( &depth_view_desc, sizeof(depth_view_desc) );
	depth_view_desc.Format					= depth_desc.Format;
	depth_view_desc.ViewDimension			= D3D11_DSV_DIMENSION_TEXTURE2D;
	depth_view_desc.Texture2D.MipSlice		= 0;
	hResult = m_pD3D11Device->CreateDepthStencilView( m_pDepthStencil, &depth_view_desc, &m_pDepthStencilView );
	if( FAILED( hResult ) )
	{ 
		return FALSE; 
	}

	//
	m_pD3D11DeviceContext->OMSetRenderTargets( 1, &m_pRenderTargetView, m_pDepthStencilView );
	return TRUE;
}

BOOL	D3D11RenderWindow::onRenderBegin(RenderSystem* pRenderSystem)
{ 
	if(!RenderWindow::onRenderBegin(pRenderSystem))
	{ return FALSE; }

	// 初始化视口:
	D3D11_VIEWPORT viewport;
	viewport.Width			= m_fWidth;
	viewport.Height			= m_fHeight;
	viewport.MinDepth		= 0.0f;
	viewport.MaxDepth		= 1.0f;
	viewport.TopLeftX		= m_fX;
	viewport.TopLeftY		= m_fY;
	m_pD3D11DeviceContext->RSSetViewports( 1, &viewport );

	//
	return TRUE; 
}

BOOL	D3D11RenderWindow::onRenderEnd(RenderSystem* pRenderSystem)
{
	if(m_pSwapChain)
	{
		m_pSwapChain->Present(NULL, NULL);
	}

	//
	return RenderWindow::onRenderEnd(pRenderSystem);
}