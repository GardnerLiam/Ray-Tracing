#ifndef Sphere_H
#define Sphere_H

#include "Vec3.h"
#include "Ray.h"
#include "Material.h"
#include <cmath>

class Sphere {
public:
	Vec3 pos;
	double radius;
	Material* material;
	
	Sphere();
	Sphere(Vec3 p, double r, Material* c);
	double getDist(Vec3 position);
	float intersects(Ray ray);

	Vec3 normal(Vec3 surfacePoint);
};

#endif
