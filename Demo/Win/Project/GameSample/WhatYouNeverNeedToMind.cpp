/*************************************************
名称: WhatYouNeverNeedToMind.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 定义主类的部分类方法，多为极其繁琐的底层操作，已封装好，不需再考虑。
版权 : 部分来自微软MSDN上的Direct2D教程：
       https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
*************************************************/
#include "stdafx.h"

DemoApp::DemoApp() :
    m_hwnd(NULL),
    m_pDirect2dFactory(NULL),
    m_pRenderTarget(NULL)
{
}

DemoApp::~DemoApp()
{
	Bitmaps.clear();
	Brushes.clear();
    SafeRelease(&m_pDirect2dFactory);
    SafeRelease(&m_pRenderTarget);

}

void DemoApp::RunMessageLoop()
{
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

HRESULT DemoApp::LoadResourceBitmap(
    ID2D1RenderTarget *pRenderTarget,
    IWICImagingFactory *pIWICFactory,
    PCWSTR resourceName,
    PCWSTR resourceType,
    UINT destinationWidth,
    UINT destinationHeight,
    ID2D1Bitmap **ppBitmap
    )
{
    IWICBitmapDecoder *pDecoder = NULL;
    IWICBitmapFrameDecode *pSource = NULL;
    IWICStream *pStream = NULL;
    IWICFormatConverter *pConverter = NULL;
    IWICBitmapScaler *pScaler = NULL;

    HRSRC imageResHandle = NULL;
    HGLOBAL imageResDataHandle = NULL;
    void *pImageFile = NULL;
    DWORD imageFileSize = 0;

    imageResHandle = FindResourceW(HINST_THISCOMPONENT, resourceName, resourceType);
    HRESULT hr = imageResHandle ? S_OK : E_FAIL;
    if (SUCCEEDED(hr))
    {
        imageResDataHandle = LoadResource(HINST_THISCOMPONENT, imageResHandle);
        hr = imageResDataHandle ? S_OK : E_FAIL;
    }

    if (SUCCEEDED(hr))
    {
		pImageFile = LockResource(imageResDataHandle);
		hr = pImageFile ? S_OK : E_FAIL;
    }

    if (SUCCEEDED(hr))
    {
        imageFileSize = SizeofResource(HINST_THISCOMPONENT, imageResHandle);
        hr = imageFileSize ? S_OK : E_FAIL;
    }

    if (SUCCEEDED(hr))
		hr = pIWICFactory->CreateStream(&pStream);

    if (SUCCEEDED(hr))
        hr = pStream->InitializeFromMemory(
            reinterpret_cast<BYTE*>(pImageFile),
            imageFileSize
            );

    if (SUCCEEDED(hr))
        hr = pIWICFactory->CreateDecoderFromStream(
            pStream,
            NULL,
            WICDecodeMetadataCacheOnLoad,
            &pDecoder
            );

    if (SUCCEEDED(hr))
        hr = pDecoder->GetFrame(0, &pSource);

    if (SUCCEEDED(hr))
        hr = pIWICFactory->CreateFormatConverter(&pConverter);

    if (SUCCEEDED(hr))   
		hr = pConverter->Initialize(
			pSource,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL,
			0.f,
			WICBitmapPaletteTypeMedianCut
			);

    if (SUCCEEDED(hr))
        hr = pRenderTarget->CreateBitmapFromWicBitmap(
            pConverter,
            NULL,
            ppBitmap
            );
    

    SafeRelease(&pDecoder);
    SafeRelease(&pSource);
    SafeRelease(&pStream);
    SafeRelease(&pConverter);
    SafeRelease(&pScaler);

    return hr;
}


HRESULT DemoApp::Initialize()
{
    HRESULT hr;
    hr = CreateDeviceIndependentResources();

    if (SUCCEEDED(hr))
    {
        WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
        wcex.style         = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc   = DemoApp::WndProc;
        wcex.cbClsExtra    = 0;
        wcex.cbWndExtra    = sizeof(LONG_PTR);
        wcex.hInstance     = HINST_THISCOMPONENT;
        wcex.hbrBackground = NULL;
        wcex.lpszMenuName  = NULL;
        wcex.hCursor       = LoadCursor(NULL, IDI_APPLICATION);
        wcex.lpszClassName = L"D2DDemoApp";

        RegisterClassEx(&wcex);

        FLOAT dpiX, dpiY;

        m_pDirect2dFactory->GetDesktopDpi(&dpiX, &dpiY);

        m_hwnd = CreateWindow(
            L"D2DDemoApp",
            L"GameSample",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            static_cast<UINT>(ceil(640.f * dpiX / 96.f)),
            static_cast<UINT>(ceil(480.f * dpiY / 96.f)),
            NULL,
            NULL,
            HINST_THISCOMPONENT,
            this
            );
        hr = m_hwnd ? S_OK : E_FAIL;
        if (SUCCEEDED(hr))
        {
            ShowWindow(m_hwnd, SW_SHOWNORMAL);
            UpdateWindow(m_hwnd);
        }
    }

    return hr;
}

HRESULT DemoApp::CreateDeviceIndependentResources()
{
    HRESULT hr = S_OK;

    hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pDirect2dFactory);

	if (SUCCEEDED(hr))
		hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,__uuidof(IDWriteFactory),reinterpret_cast<IUnknown**>(&pDWriteFactory));

	if (SUCCEEDED(hr))
		hr = CoCreateInstance(CLSID_WICImagingFactory,NULL,CLSCTX_INPROC_SERVER,IID_IWICImagingFactory,(LPVOID*)&m_pWICFactory);

	if (SUCCEEDED(hr))
		hr = pDWriteFactory->CreateTextFormat(
			L"黑体", 
			NULL, 
			DWRITE_FONT_WEIGHT_REGULAR,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			72.0f,
			L"zh-cn",
			&pTextFormat
			);

	if (SUCCEEDED(hr))
		hr = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);

	if (SUCCEEDED(hr))
		hr = pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

    return hr;
}

HRESULT DemoApp::CreateDeviceResources()
{
    HRESULT hr = S_OK;

    if (!m_pRenderTarget)
    {
        RECT rc;
        GetClientRect(m_hwnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(
            rc.right - rc.left,
            rc.bottom - rc.top
            );

        hr = m_pDirect2dFactory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(m_hwnd, size),
            &m_pRenderTarget
            );

		if (SUCCEEDED(hr))
			hr = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(000000), &pBlackBrush);
	}
	return hr;
}

void DemoApp::DiscardDeviceResources()
{
	SafeRelease(&m_pRenderTarget);
}

void DemoApp::OnResize(UINT width, UINT height)
{
	if (m_pRenderTarget)
		m_pRenderTarget->Resize(D2D1::SizeU(width, height));
}