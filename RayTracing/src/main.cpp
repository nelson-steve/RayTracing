#include <iostream>
#include <fstream>

#include "Math/vec3.h"

int main(int argc, char** argv[]) {
	int nx = 200;
	int ny = 100;
	std::ofstream img("picture.ppm");
	if (img.is_open()) {
		img << "P3" << std::endl << nx << " " << ny << std::endl << "255" << std::endl;
		for (int j = ny - 1; j >= 0; j--) {
			for (int i = 0; i < nx; i++) {
				Math::vec3 col(real(i) / real(nx), real(j) / real(ny), 0.2f);
				int ir = int(255.99 * col[0]);
				int ig = int(255.99 * col[1]);
				int ib = int(255.99 * col[2]);
				img << ir << " " << ig << " " << ib << std::endl;
			}
		}
	}
	img.close();
}