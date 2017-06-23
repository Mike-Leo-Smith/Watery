/*************************************************
名称: WinMain.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 主函数。
版权 : 部分来自微软MSDN上的Direct2D教程：
       https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
*************************************************/
#include "stdafx.h"

DemoApp app;
void Game_Init(DemoApp& target);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
	
    if (SUCCEEDED(CoInitialize(NULL)))
	{
		if (SUCCEEDED(app.Initialize()))
		{
			Game_Init(app);
			app.RunMessageLoop();
		}
		CoUninitialize();
	}

	return 0;
}