#include <nds.h>
#include <vector>

#include "Boid.h"

#include "Application.h"
#include "Graphics.h"


using namespace std;

Application::Application(void) {
	// Graphics object, used to draw on (and with)
	graphics = new Graphics();

	//Boid* foo1 = new Boid((Application*)this, 10, 100);
	//Boid* foo2 = new Boid((Application*)this, 200, 120);
	//Boid* foo3 = new Boid((Application*)this, 40, 140);
		
	//foo2->getVelocity()->x = -1;
	
	//boids.push_back(foo1);
	//boids.push_back(foo2);
	//boids.push_back(foo3);

	for(int i = 0; i < 20; ++i) {
		// Create new boids in our flocking application:
		boids.push_back(new Boid((Application*)this, 10, 10+i*10));
	}
	
	lcdSwap();
	consoleDemoInit();
}
		
void Application::startMainLoop(void) {
	
	for(;;) {
		
		for(unsigned int i = 0; i < boids.size(); ++i) {
			boids.at(i)->update();
			boids.at(i)->draw(graphics);
		}
		
		swiWaitForVBlank();
	}
}


deque<Boid*>& Application::getBoids() {
	return boids;
}