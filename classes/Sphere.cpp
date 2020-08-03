#include "../headers/Sphere.h"

Sphere::Sphere() {
}

Sphere::Sphere(Vec3 p, double r, Material* m){
	pos = p.copy();
	radius = r;
	material = m;
}

float Sphere::intersects(Ray ray){
	Vec3 sphere_to_ray = ray.origin.sub(pos);
	float b = 2 * ray.direction.dot_product(sphere_to_ray);
	float c = sphere_to_ray.dot_product(sphere_to_ray) - (radius * radius);
	float discriminant = b * b - 4 * c;
	if (discriminant >= 0){
		float dist = (-b - sqrt(discriminant)) / 2;
		if (dist > 0){
			return dist;
		}
	}
	return -1;
}

double Sphere::getDist(Vec3 p){
	return pos.sub(p).magnitude() - radius;
}

Vec3 Sphere::normal(Vec3 surfacePoint){
	return surfacePoint.sub(pos).normalize();
}
