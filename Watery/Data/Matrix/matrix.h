//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_MATRIX_H
#define WATERY_MATRIX_H

#include <cstring>

namespace watery
{
	// Matrix stored in column index.
	class Matrix
	{
	private:
		float _entries[4][4];
	
	public:
		Matrix(const float *data = nullptr);
		~Matrix(void) {}
		float entry(int row, int col) const { return _entries[col][row]; }
		void set_entry(int row, int col, float val) { _entries[col][row] = val; }
		const float *entries(void) const { return (float *)_entries; }
		void set_entries(const float *entries) { memmove(_entries, entries, 16); }
	};
}

#endif  // WATERY_MATRIX_H
