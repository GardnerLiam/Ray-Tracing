#include "../headers/Scene.h"

Scene::Scene() {

}

Scene::Scene(Vec3 cam, SceneObject objs[], int nObjs, Light lgts[], int nLgts, int w, int h, int refDepth){
	camera = cam.copy();
	objects = objs;
	width = w;
	height = h;
	nObjects = nObjs;

	lights = lgts;
	nLights = nLgts;

	reflectionDepth = refDepth;
}
