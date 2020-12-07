#pragma once
#include "Pixel.h"
#include <cstddef> //for NULL using
#include <cstring>
#include <iostream>
#include <new>

class ImageDataStructure
{
public:
	ImageDataStructure();//constructor
	ImageDataStructure(const int size);
	ImageDataStructure(const int size, unsigned char pixel);
	ImageDataStructure(const ImageDataStructure& other);//copy constructor
	int getSize() const;
	void setPixels(char color);//initiate all the pixels in the structure at the same color
	void setPixel(const Pixel& pixel, int subscript);
	Pixel operator[](int subscript) const;
	ImageDataStructure& operator=(const ImageDataStructure&);
	Pixel operator()(int, int, int width) const; 

private:
	void copyptr(const Pixel* ptr2);
	int m_size;
	Pixel* m_ptr;
};
bool operator==(const ImageDataStructure&, const ImageDataStructure&);
bool operator!=(const ImageDataStructure&, const ImageDataStructure&);
ImageDataStructure& operator+=(ImageDataStructure&, const ImageDataStructure&);
std::ostream& operator<< (std::ostream&, const ImageDataStructure&);