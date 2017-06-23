/*************************************************
名称 : BitmapObjects.h
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 声明了BitmapObject类及其派生出的SceneBitmapObject类，TempBitmapObject类，CreatureObject类，
           及独立的Bullet类，分别用于显示固定图片，背景图片（可匀速滚动），可平移旋转的图片，作为玩家
		   或敌人的图片。而Bullet类用于生成子弹，子弹用TempBitmapObject类保存。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/

#ifndef BITMAP_OBJECT_H
#define BITMAP_OBJECT_H

#include "DemoApp.h"

extern class Stage;

class BitmapObject
{
protected:
	float midX;
	float midY;
	float Width;
	float Height;
	bool Enabled;
	int BitmapPTR; //位图存储在主类的一个vector成员中，BitmapPTR用于保存该位图在主类的vector成员中的位置
public:
	BitmapObject(DemoApp& target, PCWSTR BitmapToSave, float l, float t, float r, float b);

	BitmapObject(int ptr, float l, float t, float r, float b) :
		BitmapPTR(ptr), midX((l + r) / 2), midY((t + b) / 2), Width(r - l), Height(b - t), Enabled(true) {}

	D2D1_RECT_F getRect(D2D1_RECT_F RealSize);
	inline void Disable(void) { Enabled = false; }
	inline void Enable(void) { Enabled = true; }
	inline bool isEnabled(void) { return Enabled; }
	virtual void Show(DemoApp& target, D2D1_RECT_F RealSize);
};

struct point
{
	double x;
	double y;
	double z;
};

class SceneBitmapObject : public BitmapObject
{
	double Length;
	float Velocity;
	void Move(void);
public:
	SceneBitmapObject(DemoApp& target, PCWSTR BitmapToSave, float length, float v) :
		BitmapObject(target, BitmapToSave, 0.0, 0.0, length, 1.0), Length(length), Velocity(v) {}

	SceneBitmapObject(const SceneBitmapObject& src) :
		BitmapObject(src), Length(src.Length), Velocity(src.Velocity) {}
	void Show(DemoApp& target, D2D1_RECT_F RealSize);
};

class TempBitmapObject : public BitmapObject
{
protected:
	double angle;
	double VelocityX;
	double VelocityY;
	double VelocityA;
	double ExistTime;
	point (*KeyboardEvent)(double t);
	bool GoOut; //是否允许出界
	void Move();
public:
	
	TempBitmapObject(DemoApp& target, PCWSTR BitmapToSave, float l, float t, float r, float b, point(*ke)(double t) = NULL):
		BitmapObject(target, BitmapToSave, l, t, r, b),  KeyboardEvent(ke), angle(0), ExistTime(0), VelocityX(0), VelocityY(0), VelocityA(0), GoOut(false){}

	TempBitmapObject(const TempBitmapObject& src):
		BitmapObject(src), angle(src.angle), KeyboardEvent(src.KeyboardEvent), ExistTime(src.ExistTime), VelocityX(src.VelocityX), VelocityY(src.VelocityY), VelocityA(src.VelocityA), GoOut(src.GoOut){}

	TempBitmapObject(int ptr, float l, float t, float r, float b, double vx, double vy, double a, point(*func)(double t) = NULL) :
		BitmapObject(ptr, l, t, r, b), VelocityX(vx), VelocityY(vy), VelocityA(a), KeyboardEvent(func), angle(0), GoOut(true) {} //该构造函数专门用于创建表示子弹的对象

	void Set3Velocities(double x, double y, double a);

	inline float GetAngle(void){return angle;}
	inline float GetMidX(D2D1_RECT_F RealSize){return midX * (RealSize.right - RealSize.left) + RealSize.left;}
	inline float GetMidY(D2D1_RECT_F RealSize){return midY * (RealSize.bottom - RealSize.top) + RealSize.top;}

	inline void SetGoOut(bool b) { GoOut = b; }

	void Show(DemoApp& target, D2D1_RECT_F RealSize);
};

class Bullet
{
	double Attack;
	int BitmapPTR;
	double Width;
	double Height;
	double VelocityX;
	double VelocityY;
	double VelocityA;
	point(*Track)(double t);
public:
	Bullet(DemoApp& target, double Attack, double Width, double Height, LPWSTR str, double vx, double vy = 0, double a = 0, point(*func)(double t) = NULL);
	Bullet(const Bullet& src) : Attack(src.Attack), BitmapPTR(src.BitmapPTR), Width(src.Width), Height(src.Height), VelocityX(src.VelocityX), VelocityY(src.VelocityY), VelocityA(src.VelocityA), Track(src.Track){};
	void Fire(DemoApp& target, std::vector<TempBitmapObject>& arr, double MidX, double MidY);
};

class CreatureObject : public TempBitmapObject
{
	double Health;
	double MaxHealth;
	double Attack;
	Bullet ShootBullet; //射击子弹类型，若为NULL则无法开火
	bool(*ShouldFire)(double t); //控制开火，若为NULL则无法开火
	bool isGhost; //表示正在播放死亡动画，尚未消失的状态
public:
	CreatureObject(DemoApp& target, PCWSTR BitmapToSave, float l, float t, float r, float b, point(*ke)(double t), float health, float attack, Bullet bullet, bool (*func)(double t) = NULL):
		TempBitmapObject(target, BitmapToSave, l, t, r, b, ke), Health(health), MaxHealth(health), Attack(attack), ShootBullet(bullet), ShouldFire(func), isGhost(false) {};
	void Fire(DemoApp& target, std::vector<TempBitmapObject>& arr);
	void Show(DemoApp& target, D2D1_RECT_F RealSize, std::vector<TempBitmapObject>& arr);
	inline double GetAttack(void) { return Attack; }
	inline void TakeDamage(double damage) { Health -= damage; }
	inline bool isDead(void) { return isGhost; }
};

#endif