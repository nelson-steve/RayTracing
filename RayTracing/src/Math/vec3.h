#pragma once

#include <math.h>

#define real double

namespace Math {
	class vec3 {
	public:
		vec3() {}
		vec3(real x, real y, real z) { vec[0] = x, vec[1] = y, vec[2] = z; }
		inline real x() const { return vec[0]; }
		inline real y() const { return vec[1]; }
		inline real z() const { return vec[2]; }
		inline real r() const { return vec[0]; }
		inline real g() const { return vec[1]; }
		inline real b() const { return vec[2]; }

		inline const vec3& operator+() const { return *this; }
		inline vec3 operator-() const { return vec3(-vec[0], -vec[1], -vec[2]); }
		inline real operator[](int i) const { return vec[i]; }
		inline real& operator[](int i) { return vec[i]; }

		inline vec3& operator+=(const vec3& vec2);
		inline vec3& operator-=(const vec3& vec2);
		inline vec3& operator*=(const vec3& vec2);
		inline vec3& operator/=(const vec3& vec2);
		inline vec3& operator*=(const real value);
		inline vec3& operator/=(const real value);

		inline real length() const { return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]); }
		inline real squared_length() const { return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]; }
		inline vec3 MakeUnitVector(vec3& v);

	private:
		real vec[3];
	};
}