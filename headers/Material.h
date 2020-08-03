#ifndef Material_H
#define Material_H

#include "Vec3.h"
#include <iostream>

class Material {
public:
	Vec3 color;

	Vec3 color1;
	Vec3 color2;

	int type;

	float ambient;
	float diffuse;
	float specular;
	float reflection;
	Material();
	Material(Vec3 color, float ambient, float diffuse, float specular, float reflection);

	Vec3 colorAt(Vec3 pos);


};

class ChequeredMaterial : public Material{
public:

	/*
	Vec3 color1;
	Vec3 color2;

	float ambient;
	float diffuse;
	float specular;
	float reflection;
	
	*/

	ChequeredMaterial();
	ChequeredMaterial(Vec3 c1, Vec3 c2, float ambient, float diffuse, float specular, float reflection);

	//Vec3 colorAt(Vec3 pos);

};

#endif
