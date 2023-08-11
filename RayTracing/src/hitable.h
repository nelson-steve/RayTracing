#pragma once

#include "ray.h"

struct hit_record {
	real t;
	vec3 p;
	vec3 normal;
};

class hitable {
public:
	virtual bool hit(const ray& r, real t_min, real t_max, hit_record& rec) const = 0;
};