#pragma once
#include "Macros.h"
#include <iosfwd>

class Pixel
{
public:
	Pixel(unsigned char Pixel = WHITE);
	unsigned char getColor() const;
	void setColor(char color);

private:
	unsigned char m_color;
};

bool operator==(const Pixel& l, const Pixel& r);
bool operator!=(const Pixel& l, const Pixel& r);
std::ostream& operator<< (std::ostream&, const Pixel&);
Pixel operator|(const Pixel& l, const Pixel& r);
Pixel& operator|=(Pixel& l, const Pixel& r);
Pixel operator&(const Pixel& l, const Pixel& r);
Pixel& operator&=(Pixel& l, const Pixel& r);