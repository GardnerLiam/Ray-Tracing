#include "../headers/Ray.h"

Ray::Ray(Vec3 orig, Vec3 dir){
	origin = Vec3(orig.x, orig.y, orig.z);
	direction = dir.normalize();
}
