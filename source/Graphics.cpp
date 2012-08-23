#include <iostream>
#include <string>
#include <stdio.h>
#include <nds.h>
#include <math.h>

#include "Graphics.h"

#define PI 3.14159265
#define DEG2RAD 0.01745329



Graphics::Graphics(void) {
	//irqInit(); 
	//irqSet(IRQ_VBLANK, 0); 
	setColor(RGB15(20,31,10) | (1<<15));
			 
	videoSetMode(MODE_5_2D | DISPLAY_BG3_ACTIVE);
	//videoSetModeSub(MODE_2_2D | DISPLAY_BG3_ACTIVE);
			
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankB(VRAM_B_MAIN_BG);
	//vramSetBankC(VRAM_C_SUB_BG);
			
			
	REG_BG3CNT = BG_BMP16_256x256 | BG_BMP_BASE(0);
	REG_BG3PA  = 1 << 8;
	REG_BG3PB  = 0;
	REG_BG3PC  = 0;
	REG_BG3PD  = 1 << 8;
	videoRam   = BG_BMP_RAM(0);
			
			
	//REG_BG3CNT_SUB = BG_BMP16_256x256 | BG_BMP_BASE(0);
	//REG_BG3PA_SUB = 1<< 8;
	//REG_BG3PB_SUB = 0;
	//REG_BG3PC_SUB = 0;
	//REG_BG3PD_SUB = 1 << 8;
	//memClone   = BG_BMP_RAM_SUB(2);
}

void Graphics::setColor(u16 argColor) {
	color = argColor;
}

void Graphics::blankScreen(void) {
	
}

void Graphics::drawPixel(int x, int y) {
	videoRam[y * SCREEN_WIDTH + x] = color;
	//memClone[y * SCREEN_WIDTH + x] = color;
}

// Extremely basic and inefficient implementation to draw a circle:
void Graphics::drawCircle(int x, int y, int radius, int precision = 360) {
	float factor = (360/precision) * DEG2RAD;

	for(int i = 0; i < precision; ++i) {
		int tmpX = x + round(cos(factor * i) * radius);
		int tmpY = y + round(sin(factor * i) * radius);
		
		drawPixel(tmpX, tmpY);
	}
}
