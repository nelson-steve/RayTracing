#pragma once

#include "ray.h"
#define _USE_MATH_DEFINES
#include <math.h>

class camera {
public:
	camera(vec3 lookfrom, vec3 lookat, vec3 vup, real vfov, real aspect) {
		vec3 u, v, w;
		real theta = vfov * M_PI / 180;
		real half_height = tan(theta / 2);
		real half_width = aspect * half_height;
		m_origin = lookfrom;
		w = unit_vector(lookfrom - lookat);
		u = unit_vector(cross(vup, w));
		v = cross(w, u);
		m_lower_left_corner = vec3(-half_width, -half_height, -1.0);
		m_lower_left_corner = m_origin - half_width * u - half_height * v - w;
		m_horizontal = 2 * half_width * u;
		m_vertical = 2 * half_height * v;
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