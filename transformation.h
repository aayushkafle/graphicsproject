#ifndef TRANSFORMATION
#define TRANSFORMATION
#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include "matrix.h"
#include "camera.h"

#define PI 3.142857

class transformation
{
public:
	transformation();
	~transformation();
	friend class matrix4;
	friend class point_matrix;

	friend transformation composite_transform(transformation TRNS1, transformation TRNS2); //TRNS1 is the first followed by //TRNS2

	friend point_matrix result_transformed(transformation TRNS, point_matrix p1);

//protected:
	matrix4 trans_matrix;
};

class rotation: public transformation
{
public:
	rotation();

	rotation(float angle, char axis);
	~rotation();

private:
	float angle;
	char axis;
};
class translation: public transformation
{
public:
	translation();

	translation(float *tvector);
	~translation();

private:
	float tvector[3];
	
};
class scaling: public transformation
{
public:
	scaling();

	scaling(float sx, float sy, float sz);
	~scaling();

private:
	float factor;
	char axis;
};
#endif