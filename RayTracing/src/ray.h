#pragma once

#include "Math/vec3.h"
using namespace Math;

vec3 unit_vector(const vec3& vec) {
	return vec / vec.length();
}

class ray {
public:
	ray() {}
	ray(const vec3& posA, const vec3& posB) { m_posA = posA; m_posB = posB; }

	vec3 origin() const { return m_posA; }
	vec3 direction() const { return m_posB; }
	vec3 point_at_paramter(float t) { return m_posA + t * m_posB; }
private:
	vec3 m_posA, m_posB;
};