/*************************************************
名称 : Stage.h
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 声明了Stage类，用于保存关卡信息，包括关卡当前状态，何时出现敌人等信息。
其中Process类方法对关卡当前存在的全部单位进行操作，将关卡状态从上一帧转到下一帧。
Process类方法在Windows消息循环中每帧调用一次，完成关卡信息的更新。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/

#ifndef STAGE_H
#define STAGE_H

#include "BitmapObjects.h"
#include <vector>

extern class BitmapObject;

struct EnemyAppearance //出现的敌人以及对应时间
{
	CreatureObject Enemy;
	double AppearTime;
};

class Stage
{
	double ExistTime; //从关卡开始到当前的时间
	bool Crash(TempBitmapObject* obj1, TempBitmapObject* obj2); //碰撞判定
	std::vector<EnemyAppearance> WhenToSummonEnemies;

	std::vector<BitmapObject> PlayingFixedObjects; //保存屏幕上的固定物体
	std::vector<SceneBitmapObject> Scene; //保存背景
	std::vector<CreatureObject> Player; //保存玩家
	std::vector<CreatureObject> Enemies; //保存敌人
	std::vector<TempBitmapObject> PlayerBullet; //保存玩家子弹
	std::vector<TempBitmapObject> EnemyBullet; //保存敌人子弹
public:

	Stage() :ExistTime(0) {}

	void AddEnemy(double time, CreatureObject enemy); //添加敌人出现时间

	inline void SetScene(SceneBitmapObject scene) { Scene.push_back(scene); } //设置背景

	inline void SetPlayer(CreatureObject player) { Player.push_back(player); } //设置玩家

	void Process(DemoApp& app, D2D1_RECT_F RealSize);

	void Reset(); //重置关卡，重新开始游戏时调用
};

#endif