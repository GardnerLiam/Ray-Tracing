#ifndef Image_H
#define Image_H

#include <fstream>
#include <math.h>
#include <vector>

class Image {
public:
	int width;
	int height;
	std::vector<std::vector<std::vector<float>>> pixels;

	Image();

	Image(int widthV, int heightV);
	void setPixel(int x, int y, float r, float g, float b);
	void writePPM(char* name);
};

#endif
