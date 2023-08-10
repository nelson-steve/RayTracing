#include "vec3.h"
#include <istream>

namespace Math {
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
        vec[0] += vec2[0];
        vec[1] += vec2[1];
        vec[2] += vec2[2];
        return *this;
    }

    inline vec3& vec3::operator-=(const vec3& vec2) {
        vec[0] -= vec2[0];
        vec[1] -= vec2[1];
        vec[2] -= vec2[2];
        return *this;
    }

    inline vec3& vec3::operator*=(const vec3& vec2) {
        vec[0] *= vec2[0];
        vec[1] *= vec2[1];
        vec[2] *= vec2[2];
        return *this;
    }

    inline vec3& vec3::operator/=(const vec3& vec2) {
        vec[0] /= vec2[0];
        vec[1] /= vec2[1];
        vec[2] /= vec2[2];
        return *this;
    }

    inline vec3& vec3::operator*=(const real value) {
        vec[0] += value;
        vec[1] += value;
        vec[2] += value;
        return *this;
    }

    inline vec3& vec3::operator/=(const real value) {
        vec[0] += value;
        vec[1] += value;
        vec[2] += value;
        return *this;
    }   

    inline vec3 vec3::MakeUnitVector(vec3& v) {
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