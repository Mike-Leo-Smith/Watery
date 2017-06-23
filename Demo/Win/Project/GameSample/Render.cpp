/*************************************************
名称: Render.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 定义主类的OnRender类方法，它用于绘图，被Windows消息循环每帧调用一次。
版权 : 部分来自微软MSDN上的Direct2D教程：
       https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
*************************************************/
#include "stdafx.h"

int GameState = GAME_MENU;
int ChosenInMenu = NULL;

extern std::vector<BitmapObject> MenuBitmapObjects;
extern std::vector<TextObject> MenuTextObjects;
extern std::vector<TempBitmapObject> MenuHuaji;

extern Stage Stage1;

bool PointInRect(D2D1_RECT_F Rect, int x, int y)
{
	if(x >= Rect.left && x <= Rect.right && y >= Rect.top && y <= Rect.bottom)
		return true;
	else
		return false;
}

HRESULT DemoApp::OnRender()
{
    HRESULT hr = S_OK;
    hr = CreateDeviceResources();
    if (SUCCEEDED(hr))
    {
        m_pRenderTarget->BeginDraw();

        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

		//根据窗口尺寸调整绘图区域尺寸，控制绘图区域尺寸始终为16:9
		D2D1_SIZE_F rtSize = m_pRenderTarget->GetSize();
		int width = static_cast<int>(rtSize.width);
        int height = static_cast<int>(rtSize.height);
		int RealWidth, RealHeight;
		if(width == 0 && height == 0)
		{
			hr = m_pRenderTarget->EndDraw();
			return hr;
		}
		if(width/16 > height/9)
		{
			RealHeight = height;
			RealWidth = RealHeight / 9 * 16;
		}
		else
		{
			RealWidth = width;
			RealHeight = RealWidth / 16 * 9;
		}
		D2D1_RECT_F	RealSize = D2D1::RectF((width - RealWidth)/2,(height - RealHeight)/2,(width + RealWidth)/2,(height + RealHeight)/2);

		switch(GameState)
		{
		case GAME_MENU:
		{
			if(MenuTextObjects.size() >= 4 && MenuHuaji.size() >= 1)
			{
				//判断标题画面的两个选项是否被选中，若选中则变为蓝色显示
				bool onStart = PointInRect(MenuTextObjects[0].getRect(RealSize),MenuHuaji[0].GetMidX(RealSize), MenuHuaji[0].GetMidY(RealSize));
				bool onExit = PointInRect(MenuTextObjects[1].getRect(RealSize),MenuHuaji[0].GetMidX(RealSize), MenuHuaji[0].GetMidY(RealSize));
				if(onStart)
				{
					ChosenInMenu = GAME_START;
					MenuTextObjects[0].SetEnabled(false);
					MenuTextObjects[2].SetEnabled(true);
				}
				else if(onExit)
				{
					ChosenInMenu = GAME_EXIT;
					MenuTextObjects[1].SetEnabled(false);
					MenuTextObjects[3].SetEnabled(true);
				}
				else
				{
					ChosenInMenu = NULL;
					MenuTextObjects[0].SetEnabled(true);
					MenuTextObjects[1].SetEnabled(true);
					MenuTextObjects[2].SetEnabled(false);
					MenuTextObjects[3].SetEnabled(false);
				}
			}

			for (auto& object : MenuBitmapObjects)
				object.Show(*this, RealSize);

			for(auto& object : MenuTextObjects)
				if(object.GetEnabled())
				{
					pDWriteFactory->CreateTextFormat(
					L"黑体",
					NULL,
					DWRITE_FONT_WEIGHT_REGULAR,
					DWRITE_FONT_STYLE_NORMAL,
					DWRITE_FONT_STRETCH_NORMAL,
					double(RealHeight) * object.FontSize,
					L"zh-cn",
					&pTextFormat
					);
					pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
					pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

					m_pRenderTarget -> DrawText(object.str, object.Length, pTextFormat, &(object.getRect(RealSize)), Brushes[object.BrushPTR].pBrush);
				}
			for (auto& object : MenuHuaji)
				object.Show(*this, RealSize);

			break;
		}
		case GAME_PLAYING:
			Stage1.Process(*this, RealSize);
		}

		//用底色填充非绘图区域
		if (RealHeight < height)
		{
			m_pRenderTarget->FillRectangle(D2D1::RectF(0.0, 0.0, width, (height - RealHeight) / 2), pBlackBrush);
			m_pRenderTarget->FillRectangle(D2D1::RectF(0.0, (height + RealHeight) / 2, width, height), pBlackBrush);
		}
		if (RealWidth < width)
		{
			m_pRenderTarget->FillRectangle(D2D1::RectF(0.0, 0.0, (width - RealWidth) / 2, height), pBlackBrush);
			m_pRenderTarget->FillRectangle(D2D1::RectF((width + RealWidth) / 2, 0.0, width, height), pBlackBrush);
		}

		 hr = m_pRenderTarget->EndDraw();
    }
	if (hr == D2DERR_RECREATE_TARGET)
    {
        hr = S_OK;
        DiscardDeviceResources();
    }
	return hr;
}
