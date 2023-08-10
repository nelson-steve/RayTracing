#include <iostream>
#include <fstream>

int main(int argc, char** argv[]) {
	int nx = 200;
	int ny = 100;
	std::ofstream img("picture.ppm");
	if (img.is_open()) {
		img << "P3" << std::endl << nx << " " << ny << std::endl << "255" << std::endl;
		for (int j = ny - 1; j >= 0; j--) {
			for (int i = 0; i < nx; i++) {
				float r = float(i) / float(nx);
				float g = float(j) / float(ny);
				float b = 0.2f;
				int ir = int(255.99 * r);
				int ig = int(255.99 * g);
				int ib = int(255.99 * b);
				img << ir << " " << ig << " " << ib << std::endl;
			}
		}
	}
	img.close();
}