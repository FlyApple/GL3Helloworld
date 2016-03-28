// GL3Helloworld.cpp : ����Ӧ�ó������ڵ㡣
//

#include "resource.h"

#include "Precompile.h"
#include "GL3Precompile.h"

#include "win/GL3Win32RenderWindow.h"
#include "GL3RenderSystem.h"

//#include "D3D11Precompile.h"
//#include "D3D11RenderWindow.h"
//#include "D3D11RenderSystem.h"

#include "../GL3Helloworld.h"



//
#define MAX_LOADSTRING						100

// ȫ�ֱ���:
HINSTANCE	g_hInstance						= NULL;			// ��ǰʵ��
TCHAR		g_szWindowTitle[MAX_LOADSTRING]	= {0};			// �������ı�
TCHAR		g_szWindowClass[MAX_LOADSTRING]	= {0};			// ����������
HWND		g_hWnd							= NULL;

LONG		g_lWidth						= 800;
LONG		g_lHeight						= 600;
BOOL		g_bActive						= FALSE;


GL3Helloworld		g_Helloworld;

// �˴���ģ���а����ĺ�����ǰ������:
BOOL				InitInstance(HINSTANCE);
BOOL				ExitInstance();

ATOM				MainRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK	MainWindowProc(HWND, UINT, WPARAM, LPARAM);
VOID				MainRender();

//
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	CoInitialize( NULL );

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	g_Helloworld.ActiveRenderWindow(new GL3Win32RenderWindow());
	g_Helloworld.ActiveRenderSystem(new GL3RenderSystem());
	//g_Helloworld.ActiveRenderWindow(new D3D11RenderWindow());
	//g_Helloworld.ActiveRenderSystem(new D3D11RenderSystem());
	g_Helloworld.Initialize();

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, g_szWindowTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GL3HELLOWORLD, g_szWindowClass, MAX_LOADSTRING);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance))
	{ return FALSE; }

	// ����Ϣѭ��:
	MSG		msg = {0};
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE) || !g_bActive)
		{
			if(GetMessage(&msg, NULL, 0U, 0U))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				break;
			}
		}
		else
		{
			MainRender();
		}
	}

	ExitInstance( );

	g_Helloworld.Release();

	CoUninitialize( );
	return (int) msg.wParam;
}

BOOL	ExitInstance( )
{
	//
	g_Helloworld.ExitInstance();

	//
	return TRUE;
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL	InitInstance(HINSTANCE hInstance)
{
	g_hInstance = hInstance; // ��ʵ������洢��ȫ�ֱ�����

	//
	if(!MainRegisterClass(hInstance)){ return FALSE; }

	RECT	rect = {0, 0, g_lWidth, g_lHeight};
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//
	g_hWnd = CreateWindow(g_szWindowClass, g_szWindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL);
	if (!g_hWnd){ return FALSE; }


	//
	StringDictionaryT<ULONG_PTR>	option_values;
	option_values[_T("Handle")]			= (ULONG_PTR)g_hWnd;	
	option_values[_T("X")]				= 0;
	option_values[_T("Y")]				= 0;
	option_values[_T("Width")]			= g_lWidth;
	option_values[_T("Height")]			= g_lHeight;

	option_values[_T("ColorBits")]		= 32;
	option_values[_T("DepthBits")]		= 16;
	option_values[_T("StencilBits")]	= 1;

	if(!g_Helloworld.ActiveRenderWindow<GL3Win32RenderWindow>()->LoadRenderWindow(option_values))
	{
		return FALSE;
	}


	//
	if(!g_Helloworld.InitInstance())
	{
		return FALSE;
	}

	//
	ShowWindow(g_hWnd, SW_SHOWNORMAL);
	UpdateWindow(g_hWnd);

	return TRUE;
}


//
//  ����: MainRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
//
ATOM	MainRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= MainWindowProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GL3HELLOWORLD));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//MAKEINTRESOURCE(IDC_GL3HELLOWORLD);
	wcex.lpszClassName	= g_szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}


//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		{	
			PAINTSTRUCT ps;
			HDC hdc;
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		}
	case WM_ACTIVATE:
		{
			if(LOWORD(wParam) == WA_INACTIVE)
			{
				g_bActive	= FALSE;
			}
			else
			{
				g_bActive	= TRUE;
			}
			break;
		}
	case WM_SIZE:
		{
			g_Helloworld.ActiveRenderWindow<GL3RenderWindow>()->Resize(LOWORD(lParam), HIWORD(lParam));
			break;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	default:
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	return 0;
}

//
VOID	MainRender()
{
	g_Helloworld.Rendering();
}