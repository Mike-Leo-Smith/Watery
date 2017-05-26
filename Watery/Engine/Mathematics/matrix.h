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
		// �����ڲ�����
		const Matrix operator+(const Matrix &rhs) const;
		const Matrix operator-(const Matrix &rhs) const;
		const Matrix operator*(const Matrix &rhs) const;
		const Matrix operator*(float rhs) const;
		const Matrix operator/(float rhs) const;
		// ��ԪΪ�˰ѱ�������ǰ��
		friend const Matrix operator*(float lhs, const Matrix &rhs) { return rhs * lhs; }
		// ����+=
		Matrix &operator+=(const Matrix &rhs);
		Matrix &operator-=(const Matrix &rhs);
		Matrix &operator*=(const Matrix &rhs);
		Matrix &operator*=(float rhs);
		Matrix &operator/=(float rhs);
		// ������
		const Matrix operator+(void) const { return *this; }
		const Matrix operator-(void) const { return (*this) * (-1); }
		// ����������֮�������
		const Vector operator*(const Vector &rhs) const;
	};
}

#endif  // WATERY_MATRIX_H
