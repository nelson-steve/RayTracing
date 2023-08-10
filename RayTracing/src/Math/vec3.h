#pragma once

#include <math.h>
#include <iostream>

#define real double

namespace Math {
	class vec3 {
	public:
		vec3() {}
		vec3(real x, real y, real z) { m_vec[0] = x, m_vec[1] = y, m_vec[2] = z; }
		inline real x() const { return m_vec[0]; }
		inline real y() const { return m_vec[1]; }
		inline real z() const { return m_vec[2]; }
		inline real r() const { return m_vec[0]; }
		inline real g() const { return m_vec[1]; }
		inline real b() const { return m_vec[2]; }

		inline const vec3& operator+() const { return *this; }
		inline vec3 operator-() const { return vec3(-m_vec[0], -m_vec[1], -m_vec[2]); }
		inline real operator[](int i) const { return m_vec[i]; }
		inline real& operator[](int i) { return m_vec[i]; }

		inline vec3& operator+=(const vec3& vec2);
		inline vec3& operator-=(const vec3& vec2);
		inline vec3& operator*=(const vec3& vec2);
		inline vec3& operator/=(const vec3& vec2);
		inline vec3& operator*=(const real value);
		inline vec3& operator/=(const real value);

		inline real length() const { return sqrt(m_vec[0] * m_vec[0] + m_vec[1] * m_vec[1] + m_vec[2] * m_vec[2]); }
		inline real squared_length() const { return m_vec[0] * m_vec[0] + m_vec[1] * m_vec[1] + m_vec[2] * m_vec[2]; }
		inline vec3 make_unit_vector(vec3& v);
	private:
		real m_vec[3];
	};

    inline std::istream& operator>>(std::istream& is, vec3& t) {
        is >> t[0] >> t[1] >> t[2];
        return is;
    }

    inline std::ostream& operator<<(std::ostream& os, const vec3& t) {
        os << t[0] << " " << t[1] << " " << t[2];
        return os;
    }

    inline vec3& operator+(const vec3& vec1, const vec3& vec2) {
        vec3(vec1[0] + vec2[0], vec1[1] + vec2[1], vec1[2] + vec2[2]);
    }

    inline vec3& operator-(const vec3& vec1, const vec3& vec2) {
        vec3(vec1[0] - vec2[0], vec1[1] - vec2[1], vec1[2] - vec2[2]);
    }

    inline vec3& operator*(const vec3& vec1, const vec3& vec2) {
        vec3(vec1[0] * vec2[0], vec1[1] * vec2[1], vec1[2] * vec2[2]);
    }

    inline vec3& operator/(const vec3& vec1, const vec3& vec2) {
        vec3(vec1[0] / vec2[0], vec1[1] / vec2[1], vec1[2] / vec2[2]);
    }

    inline vec3 operator*(float value, const vec3& vec) {
        return vec3(value * vec[0], value * vec[1], value * vec[2]);
    }

    inline vec3 operator*(const vec3& vec, float value) {
        return vec3(value * vec[0], value * vec[1], value * vec[2]);
    }

    inline vec3 operator/(const vec3& vec, float value) {
        return vec3(vec[0] / value, vec[1] / value, vec[2] / value);
    }

    inline vec3& vec3::operator+=(const vec3& vec2) {
        m_vec[0] += vec2[0];
        m_vec[1] += vec2[1];
        m_vec[2] += vec2[2];
        return *this;
    }

    inline vec3& vec3::operator-=(const vec3& vec2) {
        m_vec[0] -= vec2[0];
        m_vec[1] -= vec2[1];
        m_vec[2] -= vec2[2];
        return *this;
    }

    inline vec3& vec3::operator*=(const vec3& vec2) {
        m_vec[0] *= vec2[0];
        m_vec[1] *= vec2[1];
        m_vec[2] *= vec2[2];
        return *this;
    }

    inline vec3& vec3::operator/=(const vec3& vec2) {
        m_vec[0] /= vec2[0];
        m_vec[1] /= vec2[1];
        m_vec[2] /= vec2[2];
        return *this;
    }

    inline vec3& vec3::operator*=(const real value) {
        m_vec[0] += value;
        m_vec[1] += value;
        m_vec[2] += value;
        return *this;
    }

    inline vec3& vec3::operator/=(const real value) {
        m_vec[0] += value;
        m_vec[1] += value;
        m_vec[2] += value;
        return *this;
    }

    inline vec3 vec3::make_unit_vector(vec3& v) {
        return v / v.length();
    }

    inline float dot(const vec3& vec1, const vec3& vec2) {
        return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
    }

    inline vec3 cross(const vec3& vec1, const vec3& vec2) {
        return vec3((vec1[1] * vec2[2] - vec1[2] * vec2[1]),
            (-(vec1[0] * vec2[2] - vec1[2] * vec2[0])),
            (vec1[0] * vec2[1] - vec1[1] * vec2[0]));
    }
}