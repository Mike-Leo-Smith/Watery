/// @file vector.h
/// @brief Header for class Matrix.
/// @author ZYF
/// @date May 1, 2017

#ifndef WATERY_VECTOR_H
#define WATERY_VECTOR_H

#include <cstring>
#include <string>

namespace watery
{
	/// @brief Vector in 3 dimensions.
	class Vector
	{
	private:
		/// @brief 3 coordinates in vector.
		float _xyz[3];
	
	public:
		/// @brief Constructor
		/// @param x Initial x coordinate. Default value is 0.
		/// @param y Initial y coordinate. Default value is 0.
		/// @param z Initial z coordinate. Default value is 0.
		Vector(float x = 0, float y = 0, float z = 0) : _xyz { x, y, z } {}
		
		/// @brief Construct vector by array pointer.
		/// @param xyz Array pointer which points at 3 coordinates.
		Vector(float *xyz) { set_xyz(xyz); }
		
		/// @brief Get length of the vector.
		/// @return Length.
		float length(void) const;
		
		/// @brief Get longitude of the vector.
		/// @return Longitude.
		float longitude(void) const;
		
		/// @brief Get latitude of the vector.
		/// @return Latitude.
		float latitude(void) const;
		
		/// @brief Normalize the vector.
		/// @note Keep the direction and change its length to 1.
		void normalize(void);
		
		/// @brief Calc cross product with another given vector.
		/// @param rhs Given vector.
		/// @return Cross product.
		const Vector cross(const Vector &rhs) const;
		
		/// @brief Calc dot product with another given vector.
		/// @param rhs Given vector.
		/// @return Dot product.
		float dot(const Vector &rhs) const;
		
		/// @brief Get x coordinate.
		/// @return x coordinate.
		float x(void) const { return _xyz[0]; }
		
		/// @brief Get y coordinate.
		/// @return y coordinate.
		float y(void) const { return _xyz[1]; }
		
		/// @brief Get z coordinate.
		/// @return z coordinate.
		float z(void) const { return _xyz[2]; }
		
		/// @brief Get all three coordinates.
		/// @return Array pointer which points at 3 coordinates.
		const float *xyz(void) const { return _xyz; }
		
		/// @brief Set x coordinate.
		/// @param x X coordinate to set.
		void set_x(float x) { _xyz[0] = x; }
		
		/// @brief Set y coordinate.
		/// @param y Y coordinate to set.
		void set_y(float y) { _xyz[1] = y; }
		
		/// @brief Set z coordinate.
		/// @param z Z coordinate to set.
		void set_z(float z) { _xyz[2] = z; }
		
		/// @brief Set some coordinate.
		/// @param pos Which coordinate to set.
		/// @note Pos must be greater than -1 and less than 3;
		/// @param val Coordinate value to set.
		void set(int pos, float val) { _xyz[pos] = val; }
		
		/// @brief Set all coordinates by array.
		/// @param xyz Array pointer which points at 3 coordinates.
		void set_xyz(const float *xyz);
		
		/// @brief Scalar multiplication
		/// @param rhs Multiply rhs.
		Vector &operator*=(float rhs);
		
		/// @brief Scalar multiplication
		/// @param rhs Divide rhs.
		Vector &operator/=(float rhs);
		
		/// @brief Vector add.
		/// @param rhs Vector to add.
		Vector &operator+=(const Vector &rhs);
		
		/// @brief Vector subtract.
		/// @param rhs Vector to subtract.
		Vector &operator-=(const Vector &rhs);
		
		/// @brief  Vector add.
		/// @param rhs Vector to add.
		/// @return Sum.
		const Vector operator+(const Vector &rhs) const;
		
		/// @brief  Vector subtract.
		/// @param rhs Vector to subtract..
		/// @return Difference.
		const Vector operator-(const Vector &rhs) const;
		
		/// @brief Calc dot product with another given vector.
		/// @param rhs Given vector.
		/// @return Dot product.
		float operator*(const Vector &rhs) const;
		
		/// @brief Scalar multiplication
		/// @param rhs Multiply rhs.
		/// @return Result.
		const Vector operator*(float rhs) const;
		
		/// @brief Scalar multiplication
		/// @param lhs Scalar.
		/// @param rhs Vector.
		/// @return lhs*rhs.
		friend const Vector operator*(float lhs, const Vector rhs) { return rhs * lhs; }
		
		/// @brief Scalar multiplication
		/// @param rhs Divide rhs.
		/// @return Result.
		const Vector operator/(float rhs) const;
		
		/// @brief Positive vector.
		/// @return Original vector.
		const Vector operator+(void) const { return *this; }
		
		/// @brief Negative vector.
		/// @return Original vector multiply -1.
		const Vector operator-(void) const { return Vector(-_xyz[0], -_xyz[1], -_xyz[2]); }
		
		/// @brief Destructor
		/// @note Nothing need to do
		~Vector(void) {}
	};
}

#endif  // WATERY_VECTOR_H
