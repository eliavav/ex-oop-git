#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure() : m_ptr(NULL), m_size(0)//#1
{
}

ImageDataStructure::ImageDataStructure(const int size)//#2
{//build dynamic structure at a given size with default color - white 
	m_ptr = new Pixel[size];
	m_size = size;
}

ImageDataStructure::ImageDataStructure(const int size, unsigned char pixel)//#3
	: ImageDataStructure(size)
	//uses #2 constructor to build structure and initialized all pixels to a given color
{
	setPixels(pixel);
}

ImageDataStructure::ImageDataStructure(const ImageDataStructure& other)
	:ImageDataStructure()
{//copy constructor - uses "operator =" functionality 
	*this = other;
}

int ImageDataStructure::getSize() const
{
	return m_size;
}

void ImageDataStructure::setPixels(char color)
{
	for (int i = 0; i < m_size; ++i)
	{
		m_ptr[i].setColor(color);
	}
}

void ImageDataStructure::setPixel(const Pixel& pixel, int subscript)
{
	m_ptr[subscript].setColor(pixel.getColor());
}


Pixel ImageDataStructure::operator[](int subscript) const
{
	if (subscript < 0 || subscript >= m_size)
	{
		std::cout << "Eror: subscript " << subscript << "out of range" << std::endl;
		exit(EXIT_FAILURE);
	}
	return m_ptr[subscript];
}

ImageDataStructure& ImageDataStructure::operator=(const ImageDataStructure& right)
{
	if (&right != this)//
	{
		if (getSize())
			delete[] m_ptr;
		m_size = right.getSize();
		if (m_size)
			copyptr(right.m_ptr);
		else
			m_ptr = NULL;
	}
	return *this;
}

Pixel ImageDataStructure::operator()(int x, int y, int width) const
{
	return m_ptr[x + y * width];
}


void ImageDataStructure::copyptr(const Pixel* ptr2)
{
	m_ptr = new Pixel[m_size];
	for (int i = 0; i < m_size; ++i)
	{
		setPixel(ptr2[i], i);
	}
}

bool operator==(const ImageDataStructure& left, const ImageDataStructure& right)
{
	if (left.getSize() != right.getSize())
		return false;
	for (int i = 0; i < left.getSize(); i++)
	{
		if (left[i] != right[i])
			return false;
	}
	return true;
}

bool operator!=(const ImageDataStructure& l, const ImageDataStructure& r)
{
	return !(l == r);
}


std::ostream& operator<<(std::ostream& output, const ImageDataStructure& r)
{
	for (int i = 0; i < r.getSize(); ++i)
	{
		output << r[i];
	}
	return output;
}
