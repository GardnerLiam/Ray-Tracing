#ifndef RenderEngine_H
#define RenderEngine_H

#include "Ray.h"
#include "Vec3.h"
#include "Scene.h"
#include "Image.h"
#include "Sphere.h"
#include "Material.h"

#include <cmath>
#include <iostream>

class RenderEngine {
public:
	Scene scene;

	int width;
	int height;

	int reflectionDepth;

	float aspectRatio;

	float x0;
	float x1;
	float y0;
	float y1;

	float minDisplacement;

	float xstep;
	float ystep;

	RenderEngine(Scene scene);

	Vec3 camera;
	Image image;

	void render();
	Vec3 rayTrace(Ray ray, int depth);

	Vec3 find_nearest(Ray ray);
	Vec3 colorAt(int objectIndex, Vec3 hitPos, Vec3 hitNormal);


};

#endif
