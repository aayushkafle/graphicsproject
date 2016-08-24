#ifndef MainHeader
#define MainHeader
#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <cmath>
#include "matrix.h"
#include "transformation.h"
#include "object.h"
#include "camera.h"

class initcl
{
    public:
       	initcl(int a, int b);
	
	
	//void drawLineDDA(float a, float b, float c, float d);
	//void drawLinebsh(float a, float b, float c, float d);
	//void drawCmid(float a, float b, float c, float d);        
	//void drawEmid(float a, float b, float c, float d);


	void run();
	class GameState 
		{	
			public:
				bool PLAY;
			
		};
	//void passPoints(x,y);
	//SDL_Window *window_p;
    private:
    	//void plotEllipse(float x,float y, float a, float b );
    	//void plotCircle(float x,float y, float a, float b );
		//void plotPoint(float a, float b);
		int mode;
		//float x_1,y_1,x_2,y_2;
    	SDL_Window *window_p;
        int screenWidth_p;
        int screenHeight_p;

		void initSystems();
	
		void gameLoop();
		void processInput();

		void drawScreen();

		GameState current_state;


};

#endif
