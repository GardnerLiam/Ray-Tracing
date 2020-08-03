#include "headers/Image.h"
#include "headers/Vec3.h"
#include "headers/Sphere.h"
#include "headers/Scene.h"
#include "headers/Material.h"
#include "headers/SceneObject.h"
#include "headers/RenderEngine.h"

#include <string.h>
#include <iostream>

#define nObjects 4
#define nLights 2
#define width 1920
#define height 1080

#define pi 3.14159265

void drawScene(char* title){
	Vec3 camera = Vec3(0,-0.35,-1);

	Material cyan(Vec3(0.25,0,0), 0.05, 0.70, 1.0, 0.5);
	Material blue(Vec3(0.227,0.039,0.639), 0.05, 0.70, 1.0, 0.5);
	Material green(Vec3(0.02, 0.18, 0), 0.05, 0.70, 1.0, 0.5);
	ChequeredMaterial cm(Vec3(0.145, 0.078, 0.588), Vec3(0.541,0.035,0.671), 0.2, 0.5, 1.0, 0.5);

	
	SceneObject BlueBall;
	BlueBall.setSphere(Sphere(Vec3(0.5,-0.1,3), 0.6, &blue));
	
	SceneObject CyanBall;
	CyanBall.setSphere(Sphere(Vec3(-0.75,-0.1,1), 0.6, &cyan));

	SceneObject GreenBall;
	GreenBall.setSphere(Sphere(Vec3(1.5, -0.1, 1.5), 0.6, &green));

	SceneObject GroundPlane;
	GroundPlane.setSphere(Sphere(Vec3(0,10000.5,1), 10000.0, &cm));


	SceneObject objects[nObjects];
	objects[0] = CyanBall;
	objects[1] = BlueBall;
	objects[2] = GreenBall;
	objects[3] = GroundPlane;

	Light light1(Vec3(1.5,-0.5,-10), Vec3(1,1,1));
	Light light2(Vec3(-0.5, -10.5, 0), Vec3(0.9,0.9,0.9));
	Light lights[nLights];
	lights[0] = light1;
	lights[1] = light2;
	
	Scene scene(camera, objects, nObjects, lights, nLights, width, height, 10);

	RenderEngine engine(scene);

	engine.render();

	engine.image.writePPM(title);

}

int main(int argc, char** argv){
	drawScene("out.ppm");
	return 0;
}
