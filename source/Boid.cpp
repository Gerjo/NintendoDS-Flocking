#include <nds.h>
#include <vector>

#include "Application.h"

#include "Boid.h"
#include "Graphics.h"


Boid::Boid(Application* argOwner, int argX, int argY) :
	lastPosition(argX, argY),
	position(argX, argY),
	velocity(1, 0)
 {

	owner 	= argOwner;
	
	setColor(RGB15(31,31,31) | (1<<15));
}


void Boid::update(void) {

	cohesion(owner->getBoids());
	seperation(owner->getBoids());
	alignment(owner->getBoids());

	// Store the current position so we can use verlet integration lateron:
	lastPosition.x = position.x;
	lastPosition.y = position.y;
	
	// Basic motion:
	position.add(velocity);
	
	// Flip the velocity if the screenbounds are reached (yet to impletement resolveLocation)
	if(position.x >= SCREEN_WIDTH  || position.x <= 0) velocity.x *= -1; 
	if(position.y >= SCREEN_HEIGHT || position.y <= 0) velocity.y *= -1; 
}

void Boid::draw(Graphics* g) {
	// Erase the old pixel (draw a black one on top)
	g->setColor(RGB15(0,0,0) | (1<<15));
	g->drawPixel(lastPosition.x, lastPosition.y);
	
	// Draw the new pixel!
	g->setColor(color);
	g->drawPixel(position.x, position.y);
}

void Boid::cohesion(deque<Boid*>& neighbours) {
	Vector2D vForce;
	float neighborCount = 0;
	Vector2D vCenterOfMass;
	deque<Boid*>::iterator itBoid;
	
	for(itBoid = neighbours.begin(); itBoid != neighbours.end(); ++itBoid) {
		if(*itBoid == this) continue;	
		
		vCenterOfMass.add((*itBoid)->getVelocity());
		++neighborCount;
	}
	
	if(neighborCount > 0) {
		vCenterOfMass.devide(neighborCount);
		
		if(vCenterOfMass.distanceToSQ(getVelocity()) > 5.0f * 5.0f) {
			Vector2D vel = vCenterOfMass;
			Vector2D pos = position;
			pos.normalize();
			
			vel.subtract(pos);
			vel.subtract(getVelocity());
			vel.scale(0.1);
			
			velocity.add(vel);
		}
	}
	
	
}

void Boid::seperation(deque<Boid*>& neighbours) {
	Vector2D steeringForce(0, 0);
	Vector2D vDisplacement(0, 0);
	
	deque<Boid*>::iterator itBoid;
	
	for(itBoid = neighbours.begin(); itBoid != neighbours.end(); ++itBoid) {
		if(*itBoid == this) continue;
		
		vDisplacement = position;
		vDisplacement.subtract((*itBoid)->getPosition());
 
		steeringForce = vDisplacement;
		steeringForce.devide(vDisplacement.getLength());
	}
	
	steeringForce.normalize();
	
	steeringForce.scale(0.1f);
	
	velocity.add(steeringForce);
	
}

void Boid::alignment(deque<Boid*>& neighbours) {
	
}

