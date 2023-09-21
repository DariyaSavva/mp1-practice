#include "Vector.h"
#include <iostream>
#include <cmath>

Vector Vector::operator+(const Vector& v) const{
	Vector res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

Vector Vector::operator-(const Vector& v) const{
	Vector res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}

Vector Vector::operator*(float n) const{
	Vector res;
	res.x = x * n;
	res.y = y * n;
	res.z = z * n;
	return res;
}

float Vector::operator*(const Vector& v) const {
	return x * v.x + y * v.y + z * v.z;
}

float Vector::cos(const Vector& v) const {
	return ((*this) * v) / (len() * v.len());
}

float Vector::len(void) const {
	return sqrt(x * x + y * y + z * z);
}

void Vector::print(void) const {
	std::cout << x << " " << y << " " << z;
}