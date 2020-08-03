#include "../headers/Light.h"

Light::Light() {

}

Light::Light(Vec3 position, Vec3 color){
	pos = position.copy();
	col = color.copy();
}
