#pragma once

#include "hitable.h"

class sphere : public hitable {
public:
	sphere() {}
	sphere(vec3 center, real radius) : m_center(center), m_radius(radius) {}
	virtual bool hit(const ray& r, real t_min, real t_max, hit_record& rec) const;
private:
	vec3 m_center;
	real m_radius;
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
			return true;
		}
		temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - m_center) / m_radius;
			return true;
		}
	}
	return false;
}