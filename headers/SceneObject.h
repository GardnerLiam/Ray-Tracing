#ifndef SceneObject_H
#define SceneObject_H

#include "Sphere.h"


class SceneObject {
public:
	Sphere sphere;
	int type;
	void setSphere(Sphere s);
};

#endif
