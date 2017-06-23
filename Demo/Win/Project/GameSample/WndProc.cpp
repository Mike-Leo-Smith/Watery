/*************************************************
名称: WndProc.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : Windows消息循环。
版权 : 部分来自微软MSDN上的Direct2D教程：
       https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
*************************************************/

#include "stdafx.h"

extern int GameState;
extern int ChosenInMenu;

extern void Game_Start(DemoApp& target);

LRESULT CALLBACK DemoApp::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    if (message == WM_CREATE)
    {
        LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
        DemoApp *pDemoApp = (DemoApp *)pcs->lpCreateParams;

        ::SetWindowLongPtrW(
            hwnd,
            GWLP_USERDATA,
            PtrToUlong(pDemoApp)
            );

        result = 1;
    }
    else
    {
        DemoApp *pDemoApp = reinterpret_cast<DemoApp *>(static_cast<LONG_PTR>(
            ::GetWindowLongPtrW(
                hwnd,
                GWLP_USERDATA
                )));

        bool wasHandled = false;

        if (pDemoApp)
        {
            switch (message)
            {
            case WM_SIZE:
                {
                    UINT width = LOWORD(lParam);
                    UINT height = HIWORD(lParam);
                    pDemoApp->OnResize(width, height);
                }
                result = 0;
                wasHandled = true;
                break;

            case WM_DISPLAYCHANGE:
                {
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                result = 0;
                wasHandled = true;
                break;

            case WM_PAINT:
                {
                    pDemoApp->OnRender();
                }
                result = 0;
                wasHandled = true;
                break;
            case WM_DESTROY:
                {
                    PostQuitMessage(0);
                }
                result = 1;
                wasHandled = true;
                break;
			case WM_KEYDOWN:
				{
					if(GameState == GAME_MENU)
					{
						if(wParam == VK_RETURN)
						{
							if (ChosenInMenu == GAME_START)
							{
								GameState = GAME_PLAYING;
								Game_Start(*pDemoApp);
							}
							if(ChosenInMenu == GAME_EXIT)
								PostQuitMessage(0);
						}
					}
				}
				result = 1;
				wasHandled = true;
				break;
            }
        }

        if (!wasHandled)
            result = DefWindowProc(hwnd, message, wParam, lParam);
    }

    return result;
}