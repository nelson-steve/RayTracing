#pragma once

#include "ray.h"
#define _USE_MATH_DEFINES
#include <math.h>

vec3 random_in_unit_disk() {
	vec3 p;
	do {
		real random_number1 = ((real)rand() / (RAND_MAX));
		real random_number2 = ((real)rand() / (RAND_MAX));
		p = 2.0 * vec3(random_number1, random_number2, 0) - vec3(1, 1, 0);
	} while (dot(p, p) >= 1.0);
	return p;
}

class camera {
public:
	camera(vec3 lookfrom, vec3 lookat, vec3 vup, real vfov, real aspect, real aperture, real focus_dist) {
		m_lens_radius = aperture / 2;
		real theta = vfov * M_PI / 180;
		real half_height = tan(theta / 2);
		real half_width = aspect * half_height;
		m_origin = lookfrom;
		w = unit_vector(lookfrom - lookat);
		u = unit_vector(cross(vup, w));
		v = cross(w, u);
		m_lower_left_corner = m_origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
		m_horizontal = 2 * half_width * focus_dist * u;
		m_vertical = 2 * half_height * focus_dist * v;
	}
	ray get_ray(real s, real t) { 
		vec3 rd = m_lens_radius * random_in_unit_disk();
		vec3 offset = u * rd.x() + v * rd.y();
		return ray(m_origin + offset,
			m_lower_left_corner + s * m_horizontal + t * m_vertical - m_origin - offset);
	}
private:
	vec3 u, v, w;
	vec3 m_origin;
	vec3 m_lower_left_corner;
	vec3 m_horizontal;
	vec3 m_vertical;
	real m_lens_radius;
};