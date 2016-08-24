#ifndef CAMERA
#define CAMERA

#include "matrix.h"
#include "transformation.h"
#include "object.h"
#include <iostream>
#include <iomanip>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <cmath>

class camera
{
public:
	camera();
	camera(float *ref_points, float *camera_poss, float *camera_orients);

	float ref_point[3];
	float camera_pos[3];
	float camera_translate[3];
	float camera_orient[2];

	~camera();
	void PLOTPOINT(float a, float b);

	void DRAWTHEFACE(point_matrix *temp, float *colour, float *normal, float *lightvector);
	void dda(float a, float b, float c, float d);


};
#endif