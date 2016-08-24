#ifndef MATRIX
#define MATRIX
#pragma once
//#include <SDL2/SDL.h>
//#include <GL/glew.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class transformation;
class matrix4;
class point_matrix
{
public:

	friend point_matrix multiply(matrix4 m1, point_matrix p1);
	friend class transformation;
	friend transformation composite_transform(transformation TRNS1, transformation TRNS2); //TRNS1 is the first followed by //TRNS2

	friend point_matrix result_transformed(transformation TRNS, point_matrix p1);
	point_matrix();
	point_matrix(float *points);
	void makepoint(float *points);
	~point_matrix();
	void drawPoint();

	point_matrix equalsto();

//private:
	float coor[4];

};

class matrix4
{
public:
	matrix4();
	matrix4(float *m1);
	~matrix4();


	friend class transformation;
	friend transformation composite_transform(transformation TRNS1, transformation TRNS2); //TRNS1 is the first followed by //TRNS2

	friend point_matrix result_transformed(transformation TRNS, point_matrix p1);


	matrix4 transpose(matrix4 m1);
	matrix4 inverse(matrix4 m1);

	matrix4 multiply(matrix4 m1, matrix4 m2);
	matrix4 add(matrix4 m1, matrix4 m2);
	matrix4 substract(matrix4 m1, matrix4 m2);

	void drawMatrix();
	
	friend point_matrix multiply(matrix4 m1, point_matrix p1);

	matrix4 operator +(const matrix4 &m1);
	matrix4 operator -(const matrix4 &m1);
	matrix4 operator *(const matrix4 &m1);

//private:
	float element[4][4];

};


#endif
