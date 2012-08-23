#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D {
	private:
		
	public:
		float x;
		float y;
		Vector2D();
		Vector2D(const Vector2D& b);
		Vector2D(int arg_x, int arg_y);
		Vector2D(float arg_x, float arg_y);
		void normalize(void);
		float getLength(void);
		float getLengthSQ(void);
		
		Vector2D& add(Vector2D& b);
		Vector2D& subtract(Vector2D& b);
		//Vector2D& subtract(Vector2D b);
		
		Vector2D& devide(float b);
		Vector2D& devide(Vector2D& b);
		
		Vector2D& scale(float b);
		
		float distanceTo(Vector2D& b);
		float distanceToSQ(Vector2D& b);
};


#endif

