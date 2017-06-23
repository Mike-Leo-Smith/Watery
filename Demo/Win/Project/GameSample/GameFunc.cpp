/*************************************************
名称: GameFunc.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 定义游戏逻辑中需要调用的函数。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/
#include "stdafx.h"

//定义标题画面中需要使用的元素
std::vector<BitmapObject> MenuBitmapObjects;
std::vector<TextObject> MenuTextObjects;
std::vector<TempBitmapObject> MenuHuaji;

//定义关卡
Stage Stage1;

//以下定义生物的移动方式
point HuajiKeyboardEvent(double t)
{
	point velocity;
	velocity.x = 0;
	velocity.y = 0;
	if (GetKeyState(VK_DOWN) < 0)
		velocity.y = 0.01;
	if (GetKeyState(VK_UP) < 0)
		velocity.y = -0.01;
	if (GetKeyState(VK_LEFT) < 0)
		velocity.x = -0.0075;
	if (GetKeyState(VK_RIGHT) < 0)
		velocity.x = 0.0075;
	velocity.z = velocity.x * 1000;
	return velocity;
}

point GamePlayerEvent(double t)
{
	point velocity;
	velocity.x = 0;
	velocity.y = 0;
	if (GetKeyState(VK_DOWN) < 0)
		velocity.y = 0.01;
	if (GetKeyState(VK_UP) < 0)
		velocity.y = -0.01;
	if (GetKeyState(VK_LEFT) < 0)
		velocity.x = -0.0075;
	if (GetKeyState(VK_RIGHT) < 0)
		velocity.x = 0.0075;
	velocity.z = 0;
	return velocity;
}

point CryerEvent(double t)
{
	point velocity;
	if (t < 1.000)
	{
		velocity.x = -0.01;
		velocity.y = 0;
		velocity.z = 0;
		return velocity;
	}
	velocity.x = -cos(t - 1) / 100;
	velocity.y = sin(t - 1) / 75;
	velocity.z = 0;
	return velocity;
}

point GhostEvent(double t)
{
	point velocity;
	velocity.x = -cos(t) / 100.0;
	velocity.y = 0;
	velocity.z = 0;
	return velocity;
}

//以下定义生物的开火方式
bool GhostFire(double t)
{
	return (int(t * 100) % 10 < 1);
}

bool PlayerFire(double t)
{
	static double LastFire = 0;
	LastFire += double(INTERVAL) / 1000.0;
	if (LastFire > 0.3 && (GetKeyState(65) < 0 || GetKeyState(97) < 0))
	{
		LastFire = 0;
		return true;
	}
	return false;
}

bool CryerFire(double t)
{
	return (rand() % 150 < 1);
}

//程序运行时调用，主要为填充标题画面
void Game_Init(DemoApp& target) 
{
	MenuBitmapObjects.push_back(BitmapObject(target, L"MenuImage", 0.0, 0.0, 1.0, 1.0));
	MenuTextObjects.push_back(TextObject(target, L"开始游戏", 0.1, D2D1::ColorF(0x000000), 0.35, 0.6, 0.65, 0.7));
	MenuTextObjects.push_back(TextObject(target, L"结束游戏", 0.1, D2D1::ColorF(0x000000), 0.35, 0.75, 0.65, 0.85));
	MenuTextObjects.push_back(TextObject(target, L"开始游戏", 0.1, D2D1::ColorF(0x0000ff), 0.35, 0.6, 0.65, 0.7));
	MenuTextObjects[MenuTextObjects.size() - 1].SetEnabled(false);
	MenuTextObjects.push_back(TextObject(target, L"结束游戏", 0.1, D2D1::ColorF(0x0000ff), 0.35, 0.75, 0.65, 0.85));
	MenuTextObjects[MenuTextObjects.size() - 1].SetEnabled(false);
	MenuHuaji.push_back(TempBitmapObject(target, L"Huaji", 0.0, 0.0, 0.1, 0.168, HuajiKeyboardEvent));
}

//游戏开始时调用，初始化关卡信息
void Game_Start(DemoApp& target) 
{
	Stage1.Reset();

	//填充第一关的背景，玩家，敌人信息
	Stage1.SetScene(SceneBitmapObject(target, L"GameScene", 5.711, 0.005));
	Stage1.SetPlayer(CreatureObject(target, L"Huaji", 0.0, 0.4, 0.08, 0.5344, GamePlayerEvent, 10, 10, Bullet(target, 1, 0.02, 0.0336, L"Huaji", 0.01), PlayerFire));
	CreatureObject Laughter(target, L"Laughter", 0.90, 0.0, 1.0, 0.168, CryerEvent, 3, 3, Bullet(target, 1, 0.02, 0.0336, L"Laughter", -0.01), CryerFire);
	Laughter.SetGoOut(true);
	CreatureObject Cryer1(target, L"Cryer", 0.90, 0.0, 1.0, 0.168, GhostEvent, 5, 5, Bullet(target, 1, 0.03, 0.0512, L"Cryer", -0.01, 0.01), GhostFire);
	CreatureObject Cryer2(target, L"Cryer", 0.90, 0.832, 1.0, 1.00, GhostEvent, 5, 5, Bullet(target, 1, 0.03, 0.0512, L"Cryer", -0.01, -0.01), GhostFire);
	Stage1.AddEnemy(1.000, Laughter);
	Stage1.AddEnemy(1.500, Laughter);
	Stage1.AddEnemy(2.000, Laughter);
	Stage1.AddEnemy(2.500, Laughter);
	Stage1.AddEnemy(3.000, Laughter);
	Stage1.AddEnemy(3.500, Laughter);
	Stage1.AddEnemy(6.000, Cryer1);
	Stage1.AddEnemy(6.000, Cryer2);
}

