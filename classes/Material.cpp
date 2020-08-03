#include "../headers/Material.h"

Material::Material(){
	type = 0;

}
Material::Material(Vec3 col, float amb, float diff, float spec, float refl){
	color = col.copy();
	ambient = amb;
	diffuse = diff;
	specular = spec;
	reflection = refl;
	type = 0;
}

Vec3 Material::colorAt(Vec3 pos){
	if (type == 1){
		int xpos = (pos.x + 5) * 3;
		int zpos = (pos.z) * 3;

	
		if (xpos%2 == zpos%2){
			return color1;
		}
		return color2;
	}

	return color;
}

ChequeredMaterial::ChequeredMaterial(){
	type = 1;
}

ChequeredMaterial::ChequeredMaterial(Vec3 c1, Vec3 c2, float amb, float diff, float spec, float refl){
	color1 = c1.copy();
	color2 = c2.copy();
	ambient = amb;
	diffuse = diff;
	specular = spec;
	reflection = refl;
	
	type = 1;
}
