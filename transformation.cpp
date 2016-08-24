#include "transformation.h"

using namespace std;

transformation::transformation()
{

}
transformation::~transformation()
{

}
rotation::rotation()
{

}

rotation::~rotation()
{
	
}
rotation::rotation(float angle, char axis)
{
	angle=angle*PI/180;
	trans_matrix.element[0][0]=1;	trans_matrix.element[0][1]=0;	trans_matrix.element[0][2]=0;	trans_matrix.element[0][3]=0;
	trans_matrix.element[1][0]=0;	trans_matrix.element[1][1]=1;	trans_matrix.element[1][2]=0;	trans_matrix.element[1][3]=0;
	trans_matrix.element[2][0]=0;	trans_matrix.element[2][1]=0;	trans_matrix.element[2][2]=1;	trans_matrix.element[2][3]=0;
	trans_matrix.element[3][0]=0;	trans_matrix.element[3][1]=0;	trans_matrix.element[3][2]=0;	trans_matrix.element[3][3]=1;
	

	if (axis=='z' || axis=='Z')
	{
		trans_matrix.element[0][0]=cos(angle);	trans_matrix.element[0][1]= -sin(angle);	
		trans_matrix.element[1][0]=sin(angle);	trans_matrix.element[1][1]=  cos(angle);
	}	

	if (axis=='x' || axis=='X')
	{
		trans_matrix.element[1][1]=cos(angle);	trans_matrix.element[1][2]= -sin(angle);	
		trans_matrix.element[2][1]=sin(angle);	trans_matrix.element[2][2]=  cos(angle);
	}	
	
	if (axis=='y' || axis=='Y')
	{
		trans_matrix.element[0][0]= cos(angle);	trans_matrix.element[0][2]=  sin(angle);	
		trans_matrix.element[2][0]=-sin(angle);	trans_matrix.element[2][2]=  cos(angle);
	}	
	
	
}
translation::translation()
{

}
translation::~translation()
{
	
}
translation::translation(float * tvector)
{
	//angle=angle*PI/180;
	trans_matrix.element[0][0]=1;	trans_matrix.element[0][1]=0;	trans_matrix.element[0][2]=0;	trans_matrix.element[0][3]=tvector[0];
	trans_matrix.element[1][0]=0;	trans_matrix.element[1][1]=1;	trans_matrix.element[1][2]=0;	trans_matrix.element[1][3]=tvector[1];
	trans_matrix.element[2][0]=0;	trans_matrix.element[2][1]=0;	trans_matrix.element[2][2]=1;	trans_matrix.element[2][3]=tvector[2];
	trans_matrix.element[3][0]=0;	trans_matrix.element[3][1]=0;	trans_matrix.element[3][2]=0;	trans_matrix.element[3][3]=1;
}

scaling::scaling(float sx, float sy, float sz)
{
	//angle=angle*PI/180;
	trans_matrix.element[0][0]=sx;	trans_matrix.element[0][1]=0;	trans_matrix.element[0][2]=0;	trans_matrix.element[0][3]=0;
	trans_matrix.element[1][0]=0;	trans_matrix.element[1][1]=sy;	trans_matrix.element[1][2]=0;	trans_matrix.element[1][3]=0;
	trans_matrix.element[2][0]=0;	trans_matrix.element[2][1]=0;	trans_matrix.element[2][2]=sz;	trans_matrix.element[2][3]=0;
	trans_matrix.element[3][0]=0;	trans_matrix.element[3][1]=0;	trans_matrix.element[3][2]=0;	trans_matrix.element[3][3]=1;
}

scaling::scaling()
{

}
scaling::~scaling()
{

}
transformation composite_transform(transformation TRNS1, transformation TRNS2) //TRNS1 is the first followed by //TRNS2
{
	transformation temp;
	temp.trans_matrix = TRNS2.trans_matrix * TRNS1.trans_matrix;
	return temp;
}
point_matrix result_transformed(transformation TRNS, point_matrix p1)
{	
	//cout<<"point nikaldai chhu"<<endl;
	point_matrix temp;
	temp = multiply(TRNS.trans_matrix, p1);
	return temp;
}
