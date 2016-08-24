#include "MainHeader.h"
//#include <iostream>
//#include <SDL2/SDL.h>
//#include <GL/gl.h>
//#include <GL/glew.h>

	//plane
	float plane_center[3]={0,0,0};
	point_matrix plane_center_point(plane_center);
	float plane_dimension[3]={2000,3,2000};
	float plane_colour[3]={1.0,1.0,1.0};
	cuboid plane(plane_center_point,plane_colour,plane_dimension);

	//tree
	float cube1_center[3]={100,-50,-300};
	point_matrix cube1_center_point(cube1_center);
	float cube1_dimension[3]={15,200,15};
	float cube1_colour[3]={0.5,0.2,0.0};
	cuboid cube1(cube1_center_point,cube1_colour,cube1_dimension);

	float cube2_center[3]={100,-130,-300};
	point_matrix cube2_center_point(cube2_center);
	float cube2_dimension[3]={90,100,90};
	float cube2_colour[3]={0.01,0.72,0.01};
	cuboid cube2(cube2_center_point,cube2_colour,cube2_dimension);

	float point1[3]={-200,-20,-300};
	point_matrix p1(point1);
	float dimension[3]={10,100,100};
	float colour[3]={1.0,1.0,0.0};
	cuboid first(p1, colour, dimension);
	float point2[3]={-100,-20,-300};
	point_matrix p2(point2);
	//float dimension[3]={5,40,5};
	//float Orientation[3]={1,1,1};
	cuboid first1(p2, colour, dimension);
	
	//roof

	float point3[3]={-150,-75,-300};
	point_matrix p3(point3);
	float dimension1[3]={130,10,130};
	float colour1[3]={0.01,0.01,0.8};
	cuboid first2(p3, colour1, dimension1);


	//snowman
	//base
	float pointbase[3]={-350,-20,-300};
	point_matrix pbase(pointbase);
	float dimensionbase[3]={60,60,60};
	float coloursn[3]={0.9,0.01,0.01};
	cuboid base(pbase, coloursn, dimensionbase);
	

	//head
	float pointhead[3]={-350,-50,-300};
	point_matrix phead(pointhead);
	float dimensionhead[3]={35,35,35};
	//float colour1[3]={0.0,0.0,1.0};
	cuboid head(phead, coloursn, dimensionhead);

	//nose
	/*float pointnose[3]={-350,-38,-290};
	point_matrix pnose(pointnose);
	float dimensionnose[3]={5,5,20};
	float colournose[3]={0.0,0.0,1.0};
	cuboid nose(pnose, colournose, dimensionnose);
*/
	//eyes
	/*float point3[3]={-150,-75,-300};
	point_matrix p3(point3);
	float dimension1[3]={130,10,130};
	float colour1[3]={0.0,0.0,1.0};
	cuboid first2(p3, colour1, dimension1);*/

initcl::initcl(int a, int b)
{
	window_p = NULL;
	screenWidth_p = a;
	screenHeight_p = b;
	current_state.PLAY = 1;
}

void initcl::run()
{
	// c1(ref_point,camera_pos,camera_orient);
	/*x_1=a;
	y_1=b;
	x_2=c;
	y_2=d;
	mode = e;*/



	initSystems();

	gameLoop();
}

void initcl::initSystems()
{
	//Initialize window
	SDL_Init(SDL_INIT_EVERYTHING);

	window_p = SDL_CreateWindow("ALPHA_PROJECT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth_p, screenHeight_p, SDL_WINDOW_OPENGL );
	if (window_p == NULL)
	{
		SDL_QUIT;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window_p);
	if (glContext == NULL)
	{
		SDL_QUIT;
	}
    glewExperimental=true;
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		SDL_QUIT;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	/*while(1)
	{
		for(float i=0.00;i<=0.00;i=i+0.01)
		{
			for(float j=0.00;j<=0.00;j=j+0.01)
			{
				for(float k=0.00;k<=0.00;k=k+0.01)
				{
					glClearColor(i,j,k,1.0f);
				}
			}
		}*/
	//glClearColor(1,1,1,1.0f);
	//}
	glClearColor(0,0,0,.0f);
	//glClearColor(1,1,0,1.0f);
}

void initcl::gameLoop()
{
	while(current_state.PLAY)
	{
		//drawLineDDA(x_1, y_1, x_2, y_2);
		processInput();

		drawScreen();
	}

}
void initcl::processInput()
{
	SDL_Event event1;
	event keypress;

	while(SDL_PollEvent(&event1))
	{
		switch(event1.type)
		{
			case SDL_QUIT:
			current_state.PLAY=0;
			break;

			case SDL_KEYUP:
			switch(event1.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				current_state.PLAY=0;
				break;
				case SDLK_w:
				//glClearColor(1,0,0,1.0f);
				keypress.EVENT_W();
				break;
			/*case SDL_MOUSEMOTION:
                glClearColor(0,1,0,1.0f);
                break;*/
				case SDLK_s:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_S();
				break;
				case SDLK_a:
				//glClearColor(1,0,0,1.0f);
				keypress.EVENT_A();
				break;
			/*case SDL_MOUSEMOTION:
                glClearColor(0,1,0,1.0f);
                break;*/
				case SDLK_d:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_D();
				break;

				case SDLK_LSHIFT:
				//glClearColor(1,0,0,1.0f);
				keypress.EVENT_SHIFT();
				break;
			/*case SDL_MOUSEMOTION:
                glClearColor(0,1,0,1.0f);
                break;*/
				case SDLK_SPACE:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_SPACE();
				break;

				case SDLK_UP:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_UP();
				break;

				case SDLK_DOWN:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_DOWN();
				break;

				case SDLK_LEFT:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_LEFT();
				break;

				case SDLK_RIGHT:
				//glClearColor(0,0,0,1.0f);
				keypress.EVENT_RIGHT();
				break;



			}break;
			/*case SDL_MOUSEBUTTONDOWN:
			glClearColor(1,0,0,1.0f);
			keypress.EVENT_W();
			break;*/
			/*case SDL_MOUSEMOTION:
                glClearColor(0,1,0,1.0f);
                break;*/
			/*case SDL_MOUSEBUTTONUP:
			glClearColor(0,0,0,1.0f);
			keypress.EVENT_S();
			break;
			/*case SDL_MOUSEBUTTONDOWN:
                glClearColor(1,0,0,1.0f);
                break;
            case SDL_MOUSEBUTTONUP:
                glClearColor(1,1,1,1.0f);
                break;
            case SDL_MOUSEMOTION:
                glClearColor(1,1,1,1.0f);
                break;
            case SDL_MOUSEWHEEL:
                glClearColor(0,1,0,1.0f);
                break;*/
			/*case SDL_MOUSEMOTION:
			event1.motion.x
			event1.motion.y

			break;*/
		}
	}
	//camera_control c1;
}
void initcl::drawScreen()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	plane.drawCuboid();


	cube1.drawCuboid();
	cube2.drawCuboid();

	first.drawCuboid();
	first1.drawCuboid();
	first2.drawCuboid();

	//nose.drawCuboid();
	base.drawCuboid();
	head.drawCuboid();
	
	/*float _center[3]={0,0,0};
	point_matrix plane_center_point(plane_center);
	float plane_dimension[3]={1000,5,1000};
	float plane_orientation[3]={0,0,0};
	cuboid plane(plane_center_point,plane_orientation,plane_dimension);
	plane.drawCuboid();*/
	/*if (mode==1)
		drawLineDDA(x_1, y_1, x_2, y_2);
				//break;
	if (mode==2)
		drawLinebsh(x_1, y_1, x_2, y_2);
			//break;
	if (mode==3)
		drawCmid(x_1, y_1, x_2, y_2);
		//drawCmid(0, 0, 50, 0);
				//break;
	if (mode==4)
		drawEmid(x_1, y_1, x_2, y_2);
				//break;
	if (mode==5)
		{
			drawLineDDA(-110,250,-85,300);
			drawLineDDA(-60,250,-85,300);
			drawLinebsh(-98,275,-73,275);
			drawLinebsh(-55,250,-55,300);
			drawLinebsh(-3,250,-3,300);
			drawLineDDA(-55,300,-3,250);
			drawLinebsh(3,250,3,300);
			drawLinebsh(55,250,55,300);
			drawLineDDA(3,250,55,250);
			drawLinebsh(60,250,60,260);
			drawLinebsh(60,250,110,250);
			drawLineDDA(110,300,110,250);
			drawLinebsh(100,300,120,300);




			drawCmid(0, 0, 200,0 );
			drawCmid(-100, 50, 30,0 );
			drawCmid(-100, 50, 4,0 );
			drawCmid(-100, 50, 3,0 );
			drawCmid(-100, 50, 2,0 );
			drawCmid(-100, 50, 1,0 );
			drawCmid(0, 0, 20,0 );
			drawCmid( 100, 50, 30,0 );
			drawCmid(100, 50, 4,0 );
			drawCmid(100, 50, 3,0 );
			drawCmid(100, 50, 2,0 );
			drawCmid(100, 50, 1,0 );
			drawEmid(0,0,5,10);
			drawEmid(0,-100,100,40);
		}
	//glEnd();*/

	SDL_GL_SwapWindow(window_p);

}

/*void initcl::drawLineDDA(float a, float b, float c, float d)
{
	//glClearDepth(1.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//glBegin(GL_POINTS);


	float k=fabs(d-b);
	float dx=c-a;
	float dy=d-b;
	//float dx = c-a;
	//float dy = d-b;
	/*if ((c-a)>0 & (d-b)>0 || (c-a)<0 & (d-b)<0)
	{
		k=1;
	}
	else
	{
		k=-1;
	}
	if(fabs(c-a)>fabs(d-b))
	{
		k=fabs(c-a);
	}
	for(int i=0;i<k;i++)
	{

		plotPoint(a,b);
		a = a+dx / k;
		b = b+dy / k;

	}

	//glEnd();
//	SDL_GL_SwapWindow(window_p);
}

void initcl::drawLinebsh(float a, float b, float c, float d)
{
//	glClearDepth(1.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//glBegin(GL_POINTS);
	float x=a,y=b;
	float k=-1;
	float dx=fabs(c-a);
	float dy=fabs(d-b);
	float p;
	if (((d-b)*(c-a))>0 )
	{
		k=1;
	}
	if(dx>dy)
	{
		p=2*dy-dx;
		if(a>c)
		{
			x=c;
			y=d;
		}
		plotPoint(x,y);
		for(int i=0;i<dx;i++)
		{
			if(p>0)
			{
				x=x+1;
				y=y+k;
				p=p+2*dy-2*dx;
			}
			else
			{
				x=x+1;
				y=y;
				p=p+2*dy;
			}
			plotPoint(x,y);
		}
	}
	else
	{
		x=c;
		y=d;
		k=-1;
		p=2*dx-dy;
		if(b>d)
		{
			x=a;
			y=b;
			k=1;
		}
		plotPoint(x,y);
		for(int i=0;i<dy;i++)
		{
			if(p>0)
			{
				x=x+1;
				y=y+k;
				p=p-2*dy+2*dx;
			}
			else
			{
				x=x;
				y=y+k;
				p=p+2*dx;
			}
			plotPoint(x,y);
		}
	}//glEnd();
//	SDL_GL_SwapWindow(window_p);
}
void initcl::drawCmid(float a, float b, float r, float d)
{
	//glClearColor(1,1,1,1.0f);
//	glClearDepth(1.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	float xct=a;
	float yct=b;
	float x=0;
	float y=r;
	float radu=r;
	float p=5/4-radu;
	plotCircle(x,y,xct,yct);
	do
	{
	    x=x+1;

		if(p>0)
		{
			y=y-1;
			p=p+2*x-2*y+1;
		}
		else
		{
			p=p+2*x+1;
		}

		plotCircle(x,y,xct,yct);
	}while(x<=y);

//	SDL_GL_SwapWindow(window_p);

}
void initcl::plotPoint(float a, float b)
{
	glBegin(GL_POINTS);
	float x_temp=a/400;
	float y_temp=b/400;
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x_temp,y_temp);
	glEnd();
}

void initcl::plotCircle(float x,float y, float a, float b )
{
	plotPoint(x+a,y+b);
	plotPoint(-x+a,y+b);
	plotPoint(x+a,-y+b);
	plotPoint(-x+a,-y+b);
	plotPoint(y+a,x+b);
	plotPoint(-y+a,x+b);
	plotPoint(-y+a,-x+b);
	plotPoint(y+a,-x+b);
}
void initcl::drawEmid(float a, float b, float rx, float ry)
{
//	glClearDepth(1.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	float xct=a;
	float yct=b;
	float x=0;
	float y=ry;
	float p1=ry*ry-rx*rx*ry+rx*rx/4;
	plotEllipse(x,y,xct,yct);

	do
	{
	    x=x+1;

		if(p1>0)
		{
			y=y-1;
			p1=p1+2*ry*ry*x+ry*ry-2*rx*rx*y+ry*ry;
		}
		else
		{
			p1=p1+2*ry*ry*x+ry*ry;
		}

		plotEllipse(x,y,xct,yct);
	}while((2*rx*rx*y)>(2*ry*ry*x));
	float p2=ry*ry*(x+1/2)*(x+1/2)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
	do
	{
	    y=y-1;

		if(p2>0)
		{
			p2=p2-2*rx*rx*y+rx*rx;
		}
		else
		{
			x=x+1;
			p2=p2-2*rx*rx*y+rx*rx+2*ry*ry*x;

		}

		plotEllipse(x,y,xct,yct);
	}while((2*rx*rx*y>0));


//	SDL_GL_SwapWindow(window_p);

}
void initcl::plotEllipse(float x,float y, float a, float b )
{
	plotPoint(x+a,y+b);
	plotPoint(-x+a,y+b);
	plotPoint(x+a,-y+b);
	plotPoint(-x+a,-y+b);
}*/




















