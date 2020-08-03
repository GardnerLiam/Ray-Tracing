#include "../headers/Vec3.h"

Vec3::Vec3(){
	x=0;
	y=0;
	z=0;
}

Vec3::Vec3(float xv, float yv, float zv){
	x = xv;
	y = yv;
	z = zv;
}


Vec3 Vec3::copy(){
	return Vec3(x, y, z);
}

float Vec3::dot_product(Vec3 other){
	return x*other.x + y*other.y + z*other.z;
}

float Vec3::magnitude(){
	return sqrt(this->dot_product(*this));
}

Vec3 Vec3::scale(float scalar){
	return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::normalize(){
	float mag = this->magnitude();
	return Vec3(x / mag, y / mag, z / mag);
}

Vec3 Vec3::add(Vec3 other){
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::sub(Vec3 other){
	return this->add(other.scale(-1));
}

Vec3 Vec3::mul(Vec3 other){
	return Vec3(x * other.x, y * other.y, z  * other.z);
}

Vec3 Vec3::div(Vec3 other){
	return Vec3(x / other.x, y / other.y, z / other.z);
}

void Vec3::print(){
	std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}
