/*************************************************
名称 :TextObject.h
作者 : 孙志航 计65 2016011363
修改时间 : 2017-06-23
内容描述 : 声明了TextObject类，用于显示文字。
版权 : 这是我们⾃行完成的程序，没有使⽤用其余来源代码。
*************************************************/

#include "DemoApp.h"

class TextObject
{
	bool Enabled;
	float midX;
	float midY;
	float Width;
	float Height;
	D2D1::ColorF Color;
public:
	ID2D1SolidColorBrush* pBrush;
	wchar_t* str;
	int Length;
	float FontSize;
	int BrushPTR;

	TextObject(DemoApp& target, std::wstring s, float fs, D2D1::ColorF color, float l, float t, float r, float b):
	midX((l + r) / 2), midY((t + b) / 2), Width(r - l), Height(b - t), FontSize(fs), Color(color), Enabled(true)
	{
		Length = s.length();
		str = new wchar_t[Length];
		for(int i = 0; i < Length; i++)
			str[i] = s[i];
		for(int i = 0; i < target.Brushes.size(); i++)
			if(Color.r == target.Brushes[i].Color.r && Color.g == target.Brushes[i].Color.g && Color.b == target.Brushes[i].Color.b)
			{
				BrushPTR = i;
				return;
			}
		target.Brushes.push_back(BrushAndItsColor());
		target.m_pRenderTarget->CreateSolidColorBrush(Color, &(target.Brushes[target.Brushes.size() - 1].pBrush));
		BrushPTR = target.Brushes.size() - 1;
	}

	TextObject(const TextObject& src):
	midX(src.midX), midY(src.midY), Width(src.Width), Height(src.Height), Color(src.Color), FontSize(src.FontSize), BrushPTR(src.BrushPTR), Enabled(src.Enabled)
	{
		Length = src.Length;
		str = new wchar_t[Length];
		for(int i = 0; i < Length; i++)
			str[i] = src.str[i];
	}

	~TextObject()
	{
		delete[] str;
	}

	inline void SetEnabled(bool change){Enabled = change;}

	inline bool GetEnabled(void){return Enabled;}

	D2D1_RECT_F getRect(D2D1_RECT_F RealSize)
	{
		D2D1_RECT_F Rect;
		Rect.left = (midX - Width / 2) * (RealSize.right - RealSize.left) + RealSize.left;
		Rect.top = (midY - Height / 2) * (RealSize.bottom - RealSize.top) + RealSize.top;
		Rect.right = (midX + Width / 2) * (RealSize.right - RealSize.left) + RealSize.left;
		Rect.bottom = (midY + Height / 2) * (RealSize.bottom - RealSize.top) + RealSize.top;
		return Rect;
	}
};