/*************************************************
名称 : DemoApp.h
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 声明了本游戏引擎的主类DemoApp，用于实现资源分配，工厂创建等底层功能。
版权 : 部分来自微软MSDN上的Direct2D教程：
       https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
*************************************************/

#ifndef DEMO_APP_H
#define DEMO_APP_H

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <math.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <atlstr.h>
#include <wincodec.h>
#include <wincodecsdk.h>
#include <vector>
#pragma comment(lib, "WindowsCodecs.lib")

//游戏状况
#define GAME_MENU 0
#define GAME_PLAYING 1

//菜单中选中的物体
#define GAME_START 1
#define GAME_EXIT 2

#define INTERVAL 33

template<class Interface> inline void SafeRelease(Interface **ppInterfaceToRelease)
{
    if (*ppInterfaceToRelease != NULL)
    {
        (*ppInterfaceToRelease)->Release();
        (*ppInterfaceToRelease) = NULL;
    }
}

#ifndef Assert
#if defined( DEBUG ) || defined( _DEBUG )
#define Assert(b) do {if (!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
#else
#define Assert(b)
#endif //DEBUG || _DEBUG
#endif

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

struct BitmapAndItsName
{
	ID2D1Bitmap* pBitmap;
	LPTSTR BitmapName;
	BitmapAndItsName() : pBitmap(NULL), BitmapName(L""){}
};

struct BrushAndItsColor
{
	ID2D1SolidColorBrush* pBrush;
	D2D1::ColorF Color;
	BrushAndItsColor() : pBrush(NULL), Color(D2D1::ColorF(000000)){}
};

extern class BitmapObject;
extern class TempBitmapObject;
extern class SceneBitmapObject;
extern class CreatureObject;
extern class TextObject;
extern class Bullet;
class DemoApp
{
	friend class BitmapObject;
	friend class TempBitmapObject;
	friend class SceneBitmapObject;
	friend class CreatureObject;
	friend class TextObject;
	friend class Bullet;

	std::vector<BitmapAndItsName> Bitmaps;
	std::vector<BrushAndItsColor> Brushes;

	HWND m_hwnd;
	ID2D1Factory* m_pDirect2dFactory;
	IDWriteTextFormat* pTextFormat;
	ID2D1SolidColorBrush* pBlackBrush;
	ID2D1HwndRenderTarget* m_pRenderTarget;
	IWICImagingFactory* m_pWICFactory;
	IDWriteFactory* pDWriteFactory;

	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceResources();
	void DiscardDeviceResources();
	HRESULT OnRender();
	void OnResize(UINT width, UINT height);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
    DemoApp();
    ~DemoApp();
    HRESULT Initialize();
	void RunMessageLoop();
	HRESULT LoadResourceBitmap(
    ID2D1RenderTarget *pRenderTarget,
    IWICImagingFactory *pIWICFactory,
    PCWSTR resourceName,
    PCWSTR resourceType,
    UINT destinationWidth,
    UINT destinationHeight,
    ID2D1Bitmap **ppBitmap
    );
};

#endif //DEMO_APP_H