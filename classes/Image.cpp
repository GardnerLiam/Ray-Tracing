#include "../headers/Image.h"

Image::Image(){
	
}

Image::Image(int widthV, int heightV){
	width = widthV;
	height = heightV;
	for (int h = 0; h < height; h++){
		std::vector<std::vector<float>> a;
		for (int w = 0; w < width; w++){
			std::vector<float> col;
			for (int i = 0; i < 3; i++){
				col.push_back(i);
			}
			a.push_back(col);
		}
		pixels.push_back(a);
	}
}
void Image::setPixel(int x, int y, float r, float g, float b){
	pixels[y][x][0] = r;
	pixels[y][x][1] = g;
	pixels[y][x][2] = b;
}

void Image::writePPM(char* name){
	std::ofstream writer(name);
	writer << "P3 " << width << " " << height << "\n255\n";
	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			float r = pixels[row][col][0];
			float g = pixels[row][col][1];
			float b = pixels[row][col][2];

			int rByte = round(std::max(std::min(r * 255, 255.f), 0.f));
			int gByte = round(std::max(std::min(g * 255, 255.f), 0.f));
			int bByte = round(std::max(std::min(b * 255, 255.f), 0.f));

			writer << rByte << " " << gByte << " " << bByte << " ";
		}
		writer << "\n";
	}
	writer.close();
}
