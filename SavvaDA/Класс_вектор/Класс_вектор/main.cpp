#include <iostream>
#include "Vector.h"

int main() {
	float x1, y1, z1, x2, y2, z2, cos;
	std::cin >> x1 >> y1 >> z1;
	std::cin >> x2 >> y2 >> z2;
	Vector v1(x1, y1, z1), v2(x2, y2, z2), v3;
	v3 = v1 + v2;
	v3.print();
	std::cout << "\n";
	cos = v1.cos(v2);
	std::cout << "cos = " << cos << "\n";
	float len = v1.len(); std::cout << "len = " << len;
	return 0;
}