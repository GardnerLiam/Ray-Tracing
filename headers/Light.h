#ifndef Light_H
#define Light_H

#include "Vec3.h"

class Light {
public:
	Vec3 pos;
	Vec3 col;
	
	Light();
	Light(Vec3 position, Vec3 color);
};
#endif
