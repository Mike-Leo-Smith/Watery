//
// Created by Mike Smith on 2017/5/7.
//

#include "matrix.h"
#include "../Vector/vector.h"

namespace watery
{
	Matrix::Matrix(const float *entries)
	{
		if (entries != nullptr)
		{
			set_entries(entries);
		}
		else
		{
			for (int i = 0; i < 16; i++)
			{
				_entries[i] = 0;
			}
		}
	}
	
	void Matrix::set_entries(const float *entries)
	{
		for (int i = 0; i < 16; i++)
		{
			_entries[i] = entries[i];
		}
	}
	//
	const Matrix Matrix::operator+(const Matrix &rhs) const
	{
		Matrix temp;
		
		for (int i = 0; i < 16; i++)
		{
			temp._entries[i] = _entries[i] + rhs._entries[i];
		}
		return temp;
	}
	
	const Matrix Matrix::operator-(const Matrix &rhs) const
	{
		Matrix temp = *this;
		
		temp += rhs;
		return temp;
	}
	
	const Matrix Matrix::operator*(const Matrix &rhs) const
	{
		Matrix temp;
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					temp.set_entry(i, j, temp.entry(i, j) + entry(i, k) * rhs.entry(k, j));
				}
			}
		}
		return temp;
	}
	
	const Matrix Matrix::operator*(float rhs) const
	{
		Matrix temp;
		
		for (int i = 0; i < 16; i++)
		{
			temp._entries[i] = _entries[i] * rhs;
		}
		return temp;
	}
	
	const Matrix Matrix::operator/(float rhs) const
	{
		Matrix temp;
		
		for (int i = 0; i < 16; i++)
		{
			temp._entries[i] = _entries[i] / rhs;
		}
		return temp;
	}
	
	Matrix &Matrix::operator+=(const Matrix &rhs)
	{
		for (int i = 0; i < 16; i++)
		{
			_entries[i] += rhs._entries[i];
		}
		return *this;
	}
	
	Matrix &Matrix::operator-=(const Matrix &rhs)
	{
		for (int i = 0; i < 16; i++)
		{
			_entries[i] -= rhs._entries[i];
		}
		return *this;
	}
	
	Matrix &Matrix::operator*=(const Matrix &rhs)
	{
		Matrix temp = (*this) * rhs;
		set_entries(temp._entries);
		return *this;
	}
	
	Matrix &Matrix::operator*=(float rhs)
	{
		Matrix temp = (*this) * rhs;
		set_entries(temp._entries);
		return *this;
	}
	
	Matrix &Matrix::operator/=(float rhs)
	{
		Matrix temp = (*this) / rhs;
		set_entries(temp._entries);
		return *this;
	}
	
	const Vector Matrix::operator*(const Vector &rhs) const
	{
		Vector temp;
		for (int i = 0; i < 3; i++)
		{
			float sum = 0;
			for (int j = 0; j < 4; j++)sum += entry(i, j) * (j == 3 ? 1 : rhs.xyz()[j]);
			temp.set(i, sum);
		}
		return temp;
	}
}
