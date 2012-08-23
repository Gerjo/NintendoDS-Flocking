#ifndef BOID_H
#define BOID_H

#include <deque>
#include "Vector2D.h"

class Application;
class Graphics;

using namespace std;

class Boid {
	private:
		Vector2D lastPosition;
		Vector2D position;
		Vector2D velocity;
		unsigned int color;
		Application* owner;
		
	public:
		Boid(Application* argOwner, int argX, int argY);
		void update(void);
		void draw(Graphics* g);
		
		
		void setColor(unsigned int argColor) { color = argColor; }
		Vector2D& getPosition() { return position; }	
		Vector2D& getVelocity() { return velocity; }	
		
		Vector2D getDirection(void) { 
			Vector2D direction = velocity; 
			direction.normalize();
			return direction; 
		}
		
		void cohesion(deque<Boid*>& neighbours);
		void seperation(deque<Boid*>& neighbours);
		void alignment(deque<Boid*>& neighbours);
};


#endif

