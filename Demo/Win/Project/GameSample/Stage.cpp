/*************************************************
名称: Bullets.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 定义了Stage类的类方法。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/

#include "stdafx.h"

extern int GameState;

bool Stage::Crash(TempBitmapObject* obj1, TempBitmapObject* obj2)
{
	static D2D1_RECT_F TempSize = D2D1::RectF(0, 0, 160, 90);
	D2D1_RECT_F Rect1 = obj1->getRect(TempSize);
	D2D1_RECT_F Rect2 = obj2->getRect(TempSize);
	if (abs(obj1->GetMidX(TempSize) - obj2->GetMidX(TempSize)) > (Rect1.bottom - Rect1.top + Rect2.bottom - Rect2.top) / 2)
		return false;
	if (abs(obj1->GetMidY(TempSize) - obj2->GetMidY(TempSize)) > (Rect1.right - Rect1.left + Rect2.right - Rect2.left) / 2)
		return false;
	double DistanceX = obj1->GetMidX(TempSize) - obj2->GetMidX(TempSize);
	double DistanceY = obj1->GetMidY(TempSize) - obj2->GetMidY(TempSize);
	double Radius1 = (Rect1.bottom - Rect1.top) / 2;
	double Radius2 = (Rect2.bottom - Rect2.top) / 2;
	if (DistanceX * DistanceX + DistanceY * DistanceY > (Radius1 + Radius2) * (Radius1 + Radius2))
		return false;
	return true;
}

void Stage::AddEnemy(double time, CreatureObject enemy)
{
	WhenToSummonEnemies.push_back(EnemyAppearance{ enemy, time });
}

void Stage::Process(DemoApp& app, D2D1_RECT_F RealSize)
{
	ExistTime += double(INTERVAL) / 1000.0;
	if (!Player[0].isEnabled())
		GameState = GAME_MENU;

	for (auto& object : PlayingFixedObjects)
		object.Show(app, RealSize);
	for (auto& object : Scene)
		object.Show(app, RealSize);
	for (auto& object : Player)
		object.Show(app, RealSize, PlayerBullet);
	for (auto& object : Enemies)
		object.Show(app, RealSize, EnemyBullet);
	for (auto& object : PlayerBullet)
		object.Show(app, RealSize);
	for (auto& object : EnemyBullet)
		object.Show(app, RealSize);

	for (auto& unit : Player)
		for (auto& object : Enemies)
			if (unit.isEnabled() && object.isEnabled() && !unit.isDead() && !object.isDead() && Crash(&unit, &object))
			{
				unit.TakeDamage(object.GetAttack());
				object.TakeDamage(unit.GetAttack());
			}
	for(auto& unit : Player)
		for(auto& object : EnemyBullet)
			if (unit.isEnabled() && object.isEnabled() && !unit.isDead() && Crash(&unit, &object))
			{
				unit.TakeDamage(1);
				object.Disable();
			}
	for (auto& unit : Enemies)
		for (auto& object : PlayerBullet)
			if (unit.isEnabled() && object.isEnabled() && !unit.isDead() && Crash(&unit, &object))
			{
				unit.TakeDamage(1);
				object.Disable();
			}

	for (auto& object : WhenToSummonEnemies)
		if (ExistTime <= object.AppearTime && ExistTime + double(INTERVAL) / 1000.0 > object.AppearTime)
			Enemies.push_back(object.Enemy);
}

void Stage::Reset()
{
	ExistTime = 0;
	PlayingFixedObjects.clear();
	Scene.clear();
	Player.clear();
	Enemies.clear();
	PlayerBullet.clear();
	EnemyBullet.clear();
}