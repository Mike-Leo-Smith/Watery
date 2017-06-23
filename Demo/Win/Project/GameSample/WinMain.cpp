/*************************************************
����: WinMain.cpp
���� : ��־�� ��65 2016011363
�޸�ʱ�� : 2017-06-23
�������� : ��������
��Ȩ : ��������΢��MSDN�ϵ�Direct2D�̳̣�
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