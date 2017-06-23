/*************************************************
名称: Bullets.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 定义了Bullet类的类方法。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/

#include "stdafx.h"

Bullet::Bullet(DemoApp& target, double attack, double width, double height, LPWSTR str, double vx, double vy, double a, point(*func)(double t)):
	Attack(attack), Width(width), Height(height), VelocityX(vx), VelocityY(vy), VelocityA(a), Track(func)
{
	for (int i = 0; i < target.Bitmaps.size(); i++) //在主类中寻找已保存的位图
		if (target.Bitmaps[i].BitmapName == str)
		{
			BitmapPTR = i;
			return;
		}

	target.Bitmaps.push_back(BitmapAndItsName()); //若找不到则创建
	target.LoadResourceBitmap(
		target.m_pRenderTarget,
		target.m_pWICFactory,
		str,
		L"Image",
		0,
		0,
		&target.Bitmaps[target.Bitmaps.size() - 1].pBitmap
	);
	BitmapPTR = target.Bitmaps.size() - 1;
}

void Bullet::Fire(DemoApp& target, std::vector<TempBitmapObject>& arr, double MidX, double MidY)
{
	for(auto& i : arr) //寻找已失效的子弹并覆盖
		if (!i.isEnabled())
		{
			i = TempBitmapObject(BitmapPTR, MidX - Width / 2, MidY - Height / 2, MidX + Width / 2, MidY + Height / 2, VelocityX, VelocityY, VelocityA, Track);
			return;
		}
	//若找不到则创建
	arr.push_back(TempBitmapObject(BitmapPTR, MidX - Width / 2, MidY - Height / 2, MidX + Width / 2, MidY + Height / 2, VelocityX, VelocityY, VelocityA, Track));
}