#include "../headers/RenderEngine.h"

RenderEngine::RenderEngine(Scene s){

	scene = s;
	width = s.width;
	height = s.height;

	reflectionDepth = s.reflectionDepth;

	aspectRatio = (float)width / height;


	x0 = -1;
	x1 = 1;
	
	y0 = -1.0 / aspectRatio;
	y1 = 1.0 / aspectRatio;

	xstep = (x1 - x0) / (width - 1);
	ystep = (y1 - y0) / (height - 1);

	camera = scene.camera;
	image = Image(width,height);

	minDisplacement = 0.0001;

}

void RenderEngine::render(){
	
	for (int j = 0; j < height; j++){
		float y = y0 + j*ystep;
		for (int i = 0; i < width; i++){
			float x = x0 + i*xstep;
			Vec3 point(x,y,0);
			point = point.sub(camera);
			Ray ray(camera,point);
			Vec3 color = this->rayTrace(ray, 0);
			image.setPixel(i,j,color.x,color.y,color.z);
		}
		int percentage = (int)((float)j/height * 100);
		std::cout << percentage << "%" << "\r";
	}
}

Vec3 RenderEngine::rayTrace(Ray ray, int depth){
	Vec3 col(0,0,0);
	//find nearest object hit by the ray
	Vec3 result = this->find_nearest(ray); //it makes no sense to use a Vec3 for this. It just amuses me
	float distance = result.x;
	int index = (int) result.y;
	
	if (index == -1){
		return col;
	}

	Vec3 hitPos = ray.origin.add(ray.direction.scale(distance));

	Vec3 hitNormal(0,0,0);

	if (scene.objects[index].type == 0){
		hitNormal = scene.objects[index].sphere.normal(hitPos);
	}
	col = col.add(this->colorAt(index, hitPos, hitNormal));
	if (depth < reflectionDepth){
		Vec3 newRayPos = hitPos.add(hitNormal.scale(minDisplacement));


		Vec3 scaledHitNormal = hitNormal.scale(ray.direction.dot_product(hitNormal) * 2);

		Vec3 newRayDir = ray.direction.sub(scaledHitNormal);


		Ray newRay(newRayPos, newRayDir);

		/*
		 * Attenuation is the process of a lightray losing energy
		 * as it bounces off objects --> light gets dimmer --> reflection coefficient
		 */

		col = col.add(this->rayTrace(newRay, depth+1).scale(scene.objects[index].sphere.material->reflection));
	}


	return col;
}

Vec3 RenderEngine::find_nearest(Ray ray){

	float dist_min = 0.001;

	Vec3 toReturn(0,-1,0);
	for (int i = 0; i < scene.nObjects; i++){
		if (scene.objects[i].type == 0){
			float dist = scene.objects[i].sphere.intersects(ray);
			if (dist != -1 && (toReturn.y == -1 || dist < dist_min)){
				toReturn.x = dist;
				toReturn.y = i;
			}
		}
	}
	return toReturn;
}

Vec3 RenderEngine::colorAt(int objectIndex, Vec3 hitPos, Vec3 hitNormal){

	Vec3 color(0,0,0);
	if (scene.objects[objectIndex].type == 0){
		Sphere object = scene.objects[objectIndex].sphere;
		
		Vec3 obj_color = object.material->colorAt(hitPos);

		Vec3 toCam = camera.sub(hitPos);
		color = Vec3(0,0,0).scale(object.material->ambient);

		float specular_k = 50;

		for (int i = 0; i < scene.nLights; i++){
			Ray toLight(hitPos, scene.lights[i].pos.sub(hitPos));
			//diffuse shading
			
			float diffusionScalar = object.material->diffuse * std::max(hitNormal.dot_product(toLight.direction), 0.f);
			Vec3 colorScalar = obj_color.scale(diffusionScalar);
			color = color.add(colorScalar);
			color = color.add(obj_color.scale(object.material->diffuse * std::max(hitNormal.dot_product(toLight.direction), 0.f)));
			//specular shading
			Vec3 halfVector = toLight.direction.add(toCam).normalize();
			color = color.add(scene.lights[i].col.scale(object.material->specular * pow(std::max(hitNormal.dot_product(halfVector), 0.f), specular_k)));

		}


	}

	return color;
}
