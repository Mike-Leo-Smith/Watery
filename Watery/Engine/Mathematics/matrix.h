//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_MATRIX_H
#define WATERY_MATRIX_H

#include <cstring>
#include "quaternion.h"

namespace watery
{
	
	class Vector;
	// Matrix stored in column index.
	class Matrix
	{
	private:
		float _entries[16];
	
	public:
		Matrix(const float *entries = nullptr);
		~Matrix(void) {}
		float entry(int row, int col) const { return _entries[col * 4 + row]; }
		void set_entry(int row, int col, float val) { _entries[col * 4 + row] = val; }
		const float *entries(void) const { return (float *)_entries; }
		void set_entries(const float *entries);
		const Matrix transpose(void) const;
		// 矩阵内部运算
		const Matrix operator+(const Matrix &rhs) const;
		const Matrix operator-(const Matrix &rhs) const;
		const Matrix operator*(const Matrix &rhs) const;
		const Matrix operator*(float rhs) const;
		const Matrix operator/(float rhs) const;
		// 友元为了把标量放在前面
		friend const Matrix operator*(float lhs, const Matrix &rhs) { return rhs * lhs; }
		// 形如+=
		Matrix &operator+=(const Matrix &rhs);
		Matrix &operator-=(const Matrix &rhs);
		Matrix &operator*=(const Matrix &rhs);
		Matrix &operator*=(float rhs);
		Matrix &operator/=(float rhs);
		// 简化正负
		const Matrix operator+(void) const { return *this; }
		const Matrix operator-(void) const { return (*this) * (-1); }
		// 矩阵与向量之间的运算
		const Vector operator*(const Vector &rhs) const;
	};
}

#endif  // WATERY_MATRIX_H
