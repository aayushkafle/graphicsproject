#ifndef OBJECT
#define OBJECT
#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include "matrix.h"
#include "transformation.h"
#include "camera.h"
#include <SDL2/SDL.h>

#define PI 3.142857

/*class camera_control
{
public:
	camera_control();
};*/

class line
{
public:
	line();
	line(point_matrix *end_pointss);
	line(point_matrix one, point_matrix two);
	void makeline(point_matrix one, point_matrix two);
	void drawLine();

	~line();

	line equalsto();

	point_matrix end_points[2];	
};

class rectangle
{
public:
	rectangle();
	rectangle(line *edgess);
	rectangle(line one, line two, line three, line four);
	void makerectangle(line one, line two, line three, line four, float *colours);
	void drawRectangle();

	~rectangle();

	rectangle equalsto();

	float normal[4];
	float lightvector[5];

	float colour[3];
	point_matrix its_points[4];
	line edges[4];


};

class cuboid
{
public:

	cuboid();
	cuboid(point_matrix p1,float *colours, float *dimensions);

	void drawCuboid();

	~cuboid();

	point_matrix center;
	float colour[3];
	float dimension[3];


	point_matrix vertices[8];
	line edges_c[12];
	rectangle faces[6];


};

class cylinder
{

};
class sphere
{

};
class event
{	
public:
	void EVENT_W();
	void EVENT_S();
	void EVENT_A();
	void EVENT_D();
	void EVENT_SHIFT();
	void EVENT_SPACE();
	void EVENT_UP();
	void EVENT_DOWN();
	void EVENT_LEFT();
	void EVENT_RIGHT();



};









#endif