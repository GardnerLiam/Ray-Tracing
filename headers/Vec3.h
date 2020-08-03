#ifndef Vec3_H
#define Vec3_H

#include <math.h>
#include <iostream>
class Vec3 {
	
public:
	float x;
	float y;
	float z;


	Vec3(float x, float y, float z);
	Vec3();

	float dot_product(Vec3 other);
	float magnitude();
	Vec3 normalize();
	Vec3 add(Vec3 other);
	Vec3 sub(Vec3 other);
	Vec3 mul(Vec3 other);
	Vec3 div(Vec3 other);
	Vec3 scale(float scalar);

	Vec3 copy();

	void print();
};

#endif
