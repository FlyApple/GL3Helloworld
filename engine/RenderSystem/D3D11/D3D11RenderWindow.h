#ifndef __MXE_D3D11RenderWindow_H__
#define __MXE_D3D11RenderWindow_H__

#pragma once


#include "RenderWindow.h"

//
class D3D11RenderWindow	: public RenderWindow
{
public:
	D3D11RenderWindow(void);
	virtual ~D3D11RenderWindow(void);

	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

protected:
	virtual BOOL	InitializeD3D11();
	virtual VOID	ReleaseD3D11();

	virtual	BOOL	onRenderBegin(RenderSystem* pRenderSystem);
	virtual BOOL	onRenderEnd(RenderSystem* pRenderSystem);
	
protected:
	//
	HWND					m_hWnd;

	//
	float					m_fX;
	float					m_fY;
	
	//
	int						m_nColorBits;
	int						m_nDepthBits;
	int						m_nStencilBits;

	//
	IDXGIFactory*			m_pFactory;
	IDXGISwapChain*			m_pSwapChain;

	D3D_FEATURE_LEVEL		m_nFeatureLevel;

	ID3D11Device*			m_pD3D11Device;
	ID3D11DeviceContext*	m_pD3D11DeviceContext;

	ID3D11RenderTargetView*	m_pRenderTargetView;

	ID3D11Texture2D*        m_pDepthStencil;
	ID3D11DepthStencilView* m_pDepthStencilView;
};


//
#endif //__MXE_D3D11RenderWindow_H__