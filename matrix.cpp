#include "matrix.h"


point_matrix::point_matrix()
{
	coor[0]=0;
	coor[1]=0;
	coor[2]=0;
	coor[3]=1;
}
point_matrix::point_matrix(float *points)
{
	coor[0]=points[0];
	coor[1]=points[1];
	coor[2]=points[2];
	coor[3]=1;
}
void point_matrix::makepoint(float *points)
{
	coor[0]=points[0];
	coor[1]=points[1];
	coor[2]=points[2];
	coor[3]=1;
}

point_matrix::~point_matrix()
{

}
void point_matrix::drawPoint()
{
	for (int i=0;i<4;i++)
	{
		std::cout<<this->coor[i]<<endl;
	}
}

matrix4::matrix4()
{
	element[0][0]=0;	element[0][1]=0;	element[0][2]=0;	element[0][3]=0;
	element[1][0]=0;	element[1][1]=0;	element[1][2]=0;	element[1][3]=0;
	element[2][0]=0;	element[2][1]=0;	element[2][2]=0;	element[2][3]=0;
	element[3][0]=0;	element[3][1]=0;	element[3][2]=0;	element[3][3]=1;
}
matrix4::matrix4(float *m1)
{
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			element[i][j]=m1[i*4+j];
		}
	}
}
matrix4::~matrix4()
{

}

matrix4 matrix4::transpose(matrix4 m1)
{
	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			temp.element[i][j]=m1.element[j][i];
		}
	}
	return temp;
}
matrix4 matrix4::inverse(matrix4 m1)
{

}

matrix4 matrix4::multiply(matrix4 m1, matrix4 m2)
{
	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			float sum=0;
			for(int k=0; k<4 ; k++)
			{
				sum = sum +  m1.element[i][k]*m2.element[k][j];
			}
			temp.element[i][j]= sum;
		}
	}
	return temp;
}
matrix4 matrix4::add(matrix4 m1, matrix4 m2)
{
	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			temp.element[i][j]=m1.element[i][j]+m2.element[1][j];
		}
	}
	return temp;
}
matrix4 matrix4::substract(matrix4 m1, matrix4 m2)
{

	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			temp.element[i][j]=m1.element[i][j]-m2.element[1][j];
		}
	}
	return temp;
}
void matrix4::drawMatrix()
{
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			cout<<this->element[i][j]<<",";
		}
		cout<<endl;
	}
}

matrix4 matrix4::operator +(const matrix4 &m1)
{

	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			temp.element[i][j]=this->element[i][j]+m1.element[i][j];
		}
	}
	return temp;
}
matrix4 matrix4::operator -(const matrix4 &m1)
{

	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			temp.element[i][j]=element[i][j]-m1.element[i][j];
		}
	}
	return temp;
}
matrix4 matrix4::operator *(const matrix4 &m1)
{

	matrix4 temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			float sum=0;
			for(int k=0; k<4 ; k++)
			{
				sum = sum +  element[i][k]*m1.element[k][j];
			}
			temp.element[i][j]= sum;
		}
	}
	return temp;
}

point_matrix multiply(matrix4 m1, point_matrix p1)
{
	point_matrix temp;
	
	
	for (int j=0; j<4; j++)
	{
		float sum=0;
		for(int k=0; k<4 ; k++)
		{
			sum = sum +  m1.element[j][k]*p1.coor[k];
		}
		temp.coor[j]= sum;
	}
	
	return temp;
}
point_matrix point_matrix::equalsto()
{
	//return *this;
	point_matrix temp;
	for(int i=0;i<4;i++)
	{
		temp.coor[i]=coor[i];
	}
	return temp;
}


