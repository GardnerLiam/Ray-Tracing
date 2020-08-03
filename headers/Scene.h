#ifndef Scene_H
#define Scene_H

#include "Vec3.h"
#include "SceneObject.h"
#include "Light.h"
class Scene{
public:
	Vec3 camera;
	SceneObject* objects;
	Light* lights;
	int nLights;
	int nObjects;
	int width;
	int height;

	int reflectionDepth;

	Scene();
	Scene(Vec3 cam, SceneObject objs[], int nObjs, Light lgts[], int nLghts, int w, int h, int refDepth);
};

#endif
