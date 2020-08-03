#ifndef Ray_H
#define Ray_H

#include "Vec3.h"

class Ray{
public:
	Vec3 origin;
	Vec3 direction;
	Ray(Vec3 orig, Vec3 dir);
};

#endif
