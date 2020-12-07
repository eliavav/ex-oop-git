#include "Pixel.h"
#include <ostream>


Pixel::Pixel(unsigned char Pixel) : m_color(Pixel)
{

}

unsigned char Pixel::getColor() const
{
	return m_color;
}

void Pixel::setColor(char color)
{
	m_color = color;
}

bool operator==(const Pixel& l, const Pixel& r)
{
	return (l.getColor() == r.getColor());
}

bool operator!=(const Pixel& l, const Pixel& r)
{
	return !(l == r);
}

std::ostream& operator<<(std::ostream& output, const Pixel& p1)
{
	output << p1.getColor();
	return output;
}

Pixel operator|(const Pixel& l, const Pixel& r)
{
	if (l == r)
		return Pixel(l.getColor());
	if (l.getColor() == BLACK || r.getColor() == BLACK)
		return Pixel(BLACK);
	if (l.getColor() == GRAY || r.getColor() == GRAY)
		return Pixel(GRAY);
}

Pixel& operator|=(Pixel& l, const Pixel& r)
{
	l = l | r;
	return l;
}

Pixel operator&(const Pixel& l, const Pixel& r)
{
	if (l == r)
		return Pixel(l.getColor());
	if (l.getColor() == WHITE || r.getColor() == WHITE)
		return Pixel(BLACK);
	if (l.getColor() == GRAY || r.getColor() == GRAY)
		return Pixel(GRAY);
}

Pixel& operator&=(Pixel& l, const Pixel& r)
{
	l = l & r;
	return l;
}


