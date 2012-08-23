#include <deque>

#ifndef APPLICATION_H
#define APPLICATION_H

class Boid;
class Graphics;

using namespace std;

class Application {
	private:
		deque<Boid*> boids;
		Graphics* graphics;
	
	public:
		Application(void);
		void startMainLoop(void);
		deque<Boid*>& getBoids();
};


#endif
