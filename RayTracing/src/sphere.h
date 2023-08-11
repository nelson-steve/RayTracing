#pragma once

#include "hitable.h"

vec3 random_in_unit_sphere() {
	vec3 p;
	do {
		real random_number_x = ((real)rand() / (RAND_MAX));
		real random_number_y = ((real)rand() / (RAND_MAX));
		real random_number_z = ((real)rand() / (RAND_MAX));
		//std::cout << "x: " << random_number_x << " y: " << random_number_y << " z: " << random_number_z << std::endl;
		p = 2.0 * vec3(random_number_x, random_number_y, random_number_z) - vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}

class sphere : public hitable {
public:
	sphere() {}
	sphere(vec3 center, real radius, material* mat) : m_center(center), m_radius(radius), m_material(mat) {}
	virtual bool hit(const ray& r, real t_min, real t_max, hit_record& rec) const;
private:
	vec3 m_center;
	real m_radius;
	material* m_material;
};

bool sphere::hit(const ray& r, real t_min, real t_max, hit_record& rec) const {
	vec3 oc = r.origin() - m_center;
	real a = dot(r.direction(), r.direction());
	real b = dot(oc, r.direction());
	real c = dot(oc, oc) - m_radius * m_radius;
	real discriminant = b * b - a * c;
	if (discriminant > 0) {
		real temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - m_center) / m_radius;
			rec.mtr_ptr = m_material;
			return true;
		}
		temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - m_center) / m_radius;
			rec.mtr_ptr = m_material;
			return true;
		}
	}
	return false;
}