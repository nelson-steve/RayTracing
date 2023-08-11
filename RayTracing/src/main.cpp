//-----------------------------------------------------------------------//
#include "Math/vec3.h"
#include "ray.h"
#include "hitable_list.h"
#include "sphere.h"

#include <iostream>
#include <fstream>
#include <cfloat>

Math::vec3 color(const ray& r, hitable* world) {
	hit_record rec;
	if (world->hit(r, 0.0, FLT_MAX, rec)) {
		return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else {
		vec3 unit_direction = unit_vector(r.direction());
		real t = 0.5f * (unit_direction.y() + 1.0f);
		return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);

	}
}

int main(int argc, char** argv[]) {
	int nx = 200;
	int ny = 100;
	std::ofstream img("picture.ppm");
	vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	vec3 horizontal(4.0f, 0.0f, 0.0f);
	vec3 vertical(0.0f, 2.0f, 0.0f);
	vec3 origin(0.0f, 0.0f, 0.0f);
	hitable* list[2];
	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable* world = new hitable_list(list, 2);
	if (img.is_open()) {
		img << "P3" << std::endl << nx << " " << ny << std::endl << "255" << std::endl;
		for (int j = ny - 1; j >= 0; j--) {
			for (int i = 0; i < nx; i++) {
				real u = real(i) / real(nx);
				real v = real(j) / real(ny);
				ray r(origin, lower_left_corner + u * horizontal + v * vertical);
				
				vec3 p = r.point_at_parameter(2.0);
				vec3 col = color(r, world);
				int ir = int(255.99 * col[0]);
				int ig = int(255.99 * col[1]);
				int ib = int(255.99 * col[2]);

				img << ir << " " << ig << " " << ib << std::endl;
			}
		}
	}
	img.close();
}