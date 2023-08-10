#include <iostream>
#include <fstream>

#include "Math/vec3.h"
#include "ray.h"

Math::vec3 color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5f * (unit_direction.y() + 1.0f);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main(int argc, char** argv[]) {
	int nx = 200;
	int ny = 100;
	std::ofstream img("picture.ppm");
	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);
	if (img.is_open()) {
		img << "P3" << std::endl << nx << " " << ny << std::endl << "255" << std::endl;
		for (int j = ny - 1; j >= 0; j--) {
			for (int i = 0; i < nx; i++) {
				real u = real(i) / real(nx);
				real v = real(j) / real(ny);
				ray r(origin, lower_left_corner + u * horizontal + v * vertical);
				Math::vec3 col = color(r);
				int ir = int(255.99 * col[0]);
				int ig = int(255.99 * col[1]);
				int ib = int(255.99 * col[2]);
				img << ir << " " << ig << " " << ib << std::endl;
			}
		}
	}
	img.close();
}