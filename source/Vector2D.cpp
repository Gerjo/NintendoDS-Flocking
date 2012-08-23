#include "Vector2D.h"


Vector2D::Vector2D() { 
	x = 0; 
	y = 0;
}

Vector2D::Vector2D(const Vector2D& b) {
	x = b.x;
	y = b.y;
}

Vector2D::Vector2D(int arg_x, int arg_y) {
	x = static_cast<float>(arg_x);
	y = static_cast<float>(arg_y);
}

Vector2D::Vector2D(float arg_x, float arg_y) {
	x = arg_x;
	y = arg_y;
}

void Vector2D::normalize(void) {
	float length = getLength();
	//if(length == 1) return;
	x /= length;
	y /= length;
}

float Vector2D::getLength(void) {
	return sqrt(getLengthSQ());
}

float Vector2D::getLengthSQ(void) {
	return y*y + x*x;
}

float Vector2D::distanceTo(Vector2D& b) {

	return sqrt(distanceToSQ(b));
}

float Vector2D::distanceToSQ(Vector2D& b) {
	float cX = x - b.x;
	float cY = y - b.y;
	
	return cX * cX + cY * cY;
}

Vector2D& Vector2D::add(Vector2D& b) {
	x += b.x;
	y += b.y;
	return *this;
}

Vector2D& Vector2D::subtract(Vector2D& b) {
	x -= b.x;
	y -= b.y;
	return *this;
}

Vector2D& Vector2D::devide(float b) {
	y /= b;
	x /= b;
	return *this;
}

Vector2D& Vector2D::devide(Vector2D& b) {
	y /= b.y;
	x /= b.x;
	return *this;
}

Vector2D& Vector2D::scale(float b) {
	x += b;
	y *= b;
	return *this;
}



