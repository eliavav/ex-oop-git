#pragma once
#include <iostream>
#include "ImageDataStructure.h"

class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	Image(const Image& other);//copy constructor
	int getHeight() const;
	int getWidth() const;
	int getDataSteuctursize() const;

	Pixel operator[](int subscript) const;
	bool operator==(const Image&);
	bool operator!=(const Image&);
	Image& operator=(const Image&);

private:
	void setPixels(const Image&, const Image&);
	ImageDataStructure m_pixels;
	int m_height;
	int m_width;
};

Image operator+(const Image&, const Image&);
std::ostream& operator<< (std::ostream&, const Image&);
