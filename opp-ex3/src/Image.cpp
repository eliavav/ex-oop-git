#include "Image.h"

Image::Image() 
	: m_pixels(), m_height(0), m_width(0)
{
}

Image::Image(int height, int width)
	: m_pixels(height * width), m_height(height), m_width(width)
{
}

Image::Image(int height, int width, unsigned char pixel)
	: m_pixels(height* width, pixel), m_height(height), m_width(width)
{
}

Image::Image(const Image& other)
	: m_pixels()
{
	*this = other;
}

Image& Image::operator=(const Image& right)
{
	m_height = right.getHeight();
	m_width = right.getWidth();
	m_pixels = right.m_pixels;
	return *this;
}

void Image::setPixels(const Image& left, const Image& right)
{
	int MaxHeight;
	(left.getHeight() > right.getHeight()) ? MaxHeight = left.getHeight() : MaxHeight = right.getHeight();
	for (int height = 0; height < MaxHeight; ++height)
	{
		for (int width = 0; width < right.getWidth() + left.getWidth(); ++width)
		{
			if(height < left.getHeight() && width < left.getHeight())
				m_pixels()
		}
	}
}

int Image::getHeight() const
{
	return m_height;
}

int Image::getWidth() const
{
	return m_width;
}

int Image::getDataSteuctursize() const
{
	return m_height * m_width;
}

Pixel Image::operator[](int subscript) const
{
	if (subscript < 0 || subscript >= m_height*m_width)
	{
		std::cout << "Eror: subscript " << subscript << "out of range" << std::endl;
		exit(EXIT_FAILURE);
	}
	return m_pixels[subscript];
}

bool Image::operator==(const Image& right)
{
	return (m_pixels == right.m_pixels && m_height == right.getHeight() && m_width == right.getWidth());
}

bool Image::operator!=(const Image& right)
{
	return !(*this == right);
}

Image operator+(const Image& left, const Image& right)
{
	int height;
	(left.getHeight() > right.getHeight()) ? height = left.getHeight() : height = right.getHeight();
	int width = left.getWidth() + right.getWidth();
	Image temp(height, width);


	return Image();
}

std::ostream& operator<<(std::ostream& output, const Image& right)
{
	for (int i = 0; i < right.getDataSteuctursize(); ++i)
	{
		if (i && i % right.getWidth() == 0)
			output << std::endl;
		output << right[i];
	}
	return output;
}




