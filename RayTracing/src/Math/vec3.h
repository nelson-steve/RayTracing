#pragma once

#include <math.h>

#define real double

namespace Math {
	class vec3 {
	public:
		vec3() {}
		vec3(real x, real y, real z) { e[0] = x, e[1] = y, e[2] = z; }
		inline real x() const { return e[0]; }
		inline real y() const { return e[1]; }
		inline real z() const { return e[2]; }
		inline real r() const { return e[0]; }
		inline real g() const { return e[1]; }
		inline real b() const { return e[2]; }

		inline const vec3& operator+() const { return *this; }
		inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		inline real operator[](int i) const { return e[i]; }
		inline real& operator[](int i) { return e[i]; }

		inline vec3& operator+=(const vec3& v2);
		inline vec3& operator-=(const vec3& v2);
		inline vec3& operator*=(const vec3& v2);
		inline vec3& operator/=(const vec3& v2);
		inline vec3& operator*=(const real v2);
		inline vec3& operator/=(const real v2);

		inline real length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
		inline real squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
		inline void MakeUnitVector();

	private:
		real e[3];
	};
}