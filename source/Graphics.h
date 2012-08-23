
#ifndef GRAPHICS_H
#define GRAPHICS_H

#define PI 3.14159265
#define DEG2RAD 0.01745329

#include <nds.h>

class Graphics {
	private:
		u16* videoRam;
		u16* memClone;
		u16 color;
		
	public:
		Graphics(void);
		void setColor(u16 argColor);
		void blankScreen(void);
		void drawPixel(int x, int y);
		void drawCircle(int x, int y, int radius, int precision);

};


#endif