//
// Created by Mike Smith on 2017/5/7.
//

#include "matrix.h"

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
			_entries[0] = _entries[5] = _entries[10] = _entries[15] = 1;
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
		
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				float e = 0;
				
				for (int i = 0; i < 4; i++)
				{
					e += entry(row, i) * rhs.entry(i, col);
				}
				temp.set_entry(row, col, e);
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
			
			for (int j = 0; j < 4; j++)
			{
				sum += entry(i, j) * (j == 3 ? 1 : rhs.xyz()[j]);
			}
			temp.set(i, sum);
		}
		return temp;
	}
	
	const Matrix Matrix::transpose(void) const
	{
		Matrix matrix;
		
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				matrix.set_entry(col, row, entry(row, col));
			}
		}
		return matrix;
	}
}
