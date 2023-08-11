#pragma once

#include "ray.h"

class camera {
public:
	camera() {
		m_lower_left_corner = vec3(-2.0, -1.0, -1.0);
		m_horizontal = vec3(4.0, 0.0, 0.0);
		m_vertical = vec3(0.0, 2.0, 0.0);
		m_origin = vec3(0.0, 0.0, 0.0);
	}
	ray get_ray(real u, real v) { 
		return ray(m_origin, 
			m_lower_left_corner + u * m_horizontal + v * m_vertical - m_origin);
	}
private:
	vec3 m_origin;
	vec3 m_lower_left_corner;
	vec3 m_horizontal;
	vec3 m_vertical;
};