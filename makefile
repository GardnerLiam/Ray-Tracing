output: main.o Vec3.o Image.o SceneObject.o Scene.o Sphere.o Ray.o RenderEngine.o Light.o Material.o 
	g++ main.o Vec3.o Image.o Ray.o Sphere.o SceneObject.o Scene.o RenderEngine.o Light.o Material.o -o output
	./output
	rm *.o
main.o: main.cpp
	g++ -c -Wwrite-strings main.cpp
Vec3.o: classes/Vec3.cpp headers/Vec3.h
	g++ -c classes/Vec3.cpp
Image.o: classes/Image.cpp headers/Image.h
	g++ -c classes/Image.cpp
Ray.o: classes/Ray.cpp headers/Ray.h
	g++ -c classes/Ray.cpp
Sphere.o: classes/Sphere.cpp headers/Sphere.h
	g++ -c classes/Sphere.cpp
SceneObject.o: classes/SceneObject.cpp headers/SceneObject.h
	g++ -c classes/SceneObject.cpp
Scene.o: classes/Scene.cpp headers/Scene.h
	g++ -c classes/Scene.cpp
RenderEngine.o: classes/RenderEngine.cpp headers/RenderEngine.h
	g++ -c classes/RenderEngine.cpp
Light.o: classes/Light.cpp headers/Light.h
	g++ -c classes/Light.cpp
Material.o: classes/Material.cpp headers/Material.h
	g++ -c classes/Material.cpp
clean:
	rm *.o output
