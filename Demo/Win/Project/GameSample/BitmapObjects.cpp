/*************************************************
名称 : BitmapObjects.cpp
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 定义了BitmapObject类及其派生类的类方法。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/

#include "stdafx.h"

BitmapObject::BitmapObject(DemoApp& target, PCWSTR BitmapToSave, float l, float t, float r, float b):
	midX((l + r) / 2), midY((t + b) / 2), Width(r - l), Height(b - t), Enabled(true)
{
	for(int i = 0; i < target.Bitmaps.size(); i++) //在主类中寻找已保存的位图
		if(target.Bitmaps[i].BitmapName == BitmapToSave)
		{
			BitmapPTR = i;
			return;
		}

	target.Bitmaps.push_back(BitmapAndItsName()); //若找不到则创建
	target.LoadResourceBitmap(
	target.m_pRenderTarget,
	target.m_pWICFactory,
	BitmapToSave,
	L"Image",
	0,
	0,
	&target.Bitmaps[target.Bitmaps.size() - 1].pBitmap
	);
	BitmapPTR = target.Bitmaps.size() - 1;
}

D2D1_RECT_F BitmapObject::getRect(D2D1_RECT_F RealSize)
{
	D2D1_RECT_F Rect;
	Rect.left = (midX - Width / 2) * (RealSize.right - RealSize.left) + RealSize.left;
	Rect.top = (midY - Height / 2) * (RealSize.bottom - RealSize.top) + RealSize.top;
	Rect.right = (midX + Width / 2) * (RealSize.right - RealSize.left) + RealSize.left;
	Rect.bottom = (midY + Height / 2) * (RealSize.bottom - RealSize.top) + RealSize.top;
	return Rect;
}

void BitmapObject::Show(DemoApp& target, D2D1_RECT_F RealSize)
{
	if(isEnabled())
		target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
}

void SceneBitmapObject::Move(void) //只允许背景匀速向左滚动
{ 
	if(midX + Width / 2 > 1.0)
		midX -= Velocity; 
}

void SceneBitmapObject::Show(DemoApp& target, D2D1_RECT_F RealSize)
{
	if (isEnabled())
	{
		Move();
		target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
	}
}

void TempBitmapObject::Set3Velocities(double x, double y, double a)
{
	VelocityX = x;
	VelocityY = y;
	VelocityA = a;
}

void TempBitmapObject::Move()
{
	if (KeyboardEvent != NULL)
	{
		point velocity = (*KeyboardEvent)(ExistTime);
		VelocityX = velocity.x;
		VelocityY = velocity.y;
		VelocityA = velocity.z;
	}
	if (GoOut)
	{
		midX += VelocityX;
		midY += VelocityY;
		angle += VelocityA;
	}
	else
	{
		if (midX + VelocityX + Width / 2 < 1.0 && midX + VelocityX - Width / 2 > 0.0)
			midX += VelocityX;
		if (midY + VelocityY + Height / 2 < 1.0 && midY + VelocityY - Height / 2 > 0.0)
			midY += VelocityY;
		angle += VelocityA;
	}
	angle = int(angle) % 360;

	if (GoOut && (midX < -0.5 || midX > 1.5 || midY < -0.5 || midY > 1.5))
		Enabled = false;

}

void TempBitmapObject::Show(DemoApp& target, D2D1_RECT_F RealSize)
{
	if (isEnabled())
	{
		Move();
		if(angle < 2 && angle > -2)
			target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
		else
		{
			target.m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(angle, D2D1::Point2F(midX * (RealSize.right - RealSize.left) + RealSize.left, midY * (RealSize.bottom - RealSize.top) + RealSize.top)));
			target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
			target.m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		}
		ExistTime += double(INTERVAL) / 1000.0;
	}

}

void CreatureObject::Fire(DemoApp& target, std::vector<TempBitmapObject>& arr)
{
	if (ShouldFire != NULL && (*ShouldFire)(ExistTime))
		ShootBullet.Fire(target, arr, midX, midY);
}

void CreatureObject::Show(DemoApp& target, D2D1_RECT_F RealSize, std::vector<TempBitmapObject>& arr)
{
	if (isEnabled())
	{
		if (Health <= 0)
			isGhost = true;
		if (isGhost)
		{
			Width *= 0.9;
			Height *= 0.9;
			target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
			if (Width < 0.01 || Height < 0.01)
				Enabled = false;
			return;
		}
		Move();
		Fire(target, arr);
		if (angle < 2 && angle > -2)
			target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
		else
		{
			target.m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(angle, D2D1::Point2F(midX * (RealSize.right - RealSize.left) + RealSize.left, midY * (RealSize.bottom - RealSize.top) + RealSize.top)));
			target.m_pRenderTarget->DrawBitmap(target.Bitmaps[BitmapPTR].pBitmap, getRect(RealSize));
			target.m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		}
		ExistTime += double(INTERVAL) / 1000.0;
	}
}