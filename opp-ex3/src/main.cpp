#include "Pixel.h"
#include "ImageDataStructure.h"
#include "Image.h"
#include <iostream>
int main()
{
	ImageDataStructure p1(20, BLACK), p2(20, GRAY), p3(10, BLACK);
	ImageDataStructure p4(p3);
	ImageDataStructure p5;

	Image im1(20, 20, BLACK), im3(20, 20, GRAY);
	Image im2(im1);

	im3 = im2;

	std::cout << im3;

}