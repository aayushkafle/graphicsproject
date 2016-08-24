#include "camera.h"

camera::camera()
{

}
camera::~camera()
{

}
camera::camera(float *ref_points, float *camera_poss, float *camera_orients)
{
	for(int i=0; i<3;i++)
	{
		ref_point[i]=ref_points[i];
		camera_pos[i]=camera_poss[i];
		camera_translate[i]=-camera_poss[i];
		if (i!=2)
		{
			camera_orient[i]=camera_orients[i];
		}
	}
}
void camera::DRAWTHEFACE(point_matrix *temp,float *colour, float *normal, float *lightvector)
{
	float camera_translate[3]={-camera_pos[0],-camera_pos[1],-camera_pos[2]};

	translation camera_trans(camera_translate);
	rotation camera_rotx(camera_orient[0],'x');
	rotation camera_roty(camera_orient[1],'y');
	//translation t1(trans_vector1);

	//camera_trans.trans_matrix.drawMatrix();
	//camera_rotx.trans_matrix.drawMatrix();
	point_matrix temp_one = result_transformed(camera_trans,temp[0]);
	point_matrix temp_two = result_transformed(camera_trans,temp[1]);
	point_matrix temp_three = result_transformed(camera_trans,temp[2]);
	point_matrix temp_four = result_transformed(camera_trans,temp[3]);	

	/*cout<<"Translated cooidinate"<<endl;
	cout<<"("<<temp_one.coor[0]<<","<<temp_one.coor[1]<<","<<temp_one.coor[2]<<")"<<"-->";
	cout<<"("<<temp_two.coor[0]<<","<<temp_two.coor[1]<<","<<temp_two.coor[2]<<")"<<endl;
*/
	temp_one = result_transformed(camera_rotx,temp_one);
	temp_one = result_transformed(camera_roty,temp_one);	

	temp_two = result_transformed(camera_rotx,temp_two);
	temp_two = result_transformed(camera_roty,temp_two);

	temp_three = result_transformed(camera_rotx,temp_three);
	temp_three = result_transformed(camera_roty,temp_three);	

	temp_four = result_transformed(camera_rotx,temp_four);
	temp_four = result_transformed(camera_roty,temp_four);

	//cout<<"Rotated cooidinate"<<endl;
	//cout<<"("<<temp_one.coor[0]<<","<<temp_one.coor[1]<<","<<temp_one.coor[2]<<")"<<"-->";
	//cout<<"("<<temp_two.coor[0]<<","<<temp_two.coor[1]<<","<<temp_two.coor[2]<<")"<<endl;
  	
  	//...........................perspective..................//
	temp_one.coor[0] = ((ref_point[2]-camera_pos[2])/(temp_one.coor[2]-ref_point[2]))*temp_one.coor[0];	
	temp_one.coor[1] = ((ref_point[2]-camera_pos[2])/(temp_one.coor[2]-ref_point[2]))*temp_one.coor[1];

	temp_two.coor[0] = ((ref_point[2]-camera_pos[2])/(temp_two.coor[2]-ref_point[2]))*temp_two.coor[0];	
	temp_two.coor[1] = ((ref_point[2]-camera_pos[2])/(temp_two.coor[2]-ref_point[2]))*temp_two.coor[1];


	temp_three.coor[0] = ((ref_point[2]-camera_pos[2])/(temp_three.coor[2]-ref_point[2]))*temp_three.coor[0];	
	temp_three.coor[1] = ((ref_point[2]-camera_pos[2])/(temp_three.coor[2]-ref_point[2]))*temp_three.coor[1];

	temp_four.coor[0] = ((ref_point[2]-camera_pos[2])/(temp_four.coor[2]-ref_point[2]))*temp_four.coor[0];	
	temp_four.coor[1] = ((ref_point[2]-camera_pos[2])/(temp_four.coor[2]-ref_point[2]))*temp_four.coor[1];
	/*cout<<"Viewing cooidinate"<<endl;
	cout<<"("<<temp_one.coor[0]<<","<<temp_one.coor[1]<<")"<<"-->";
	cout<<"("<<temp_two.coor[0]<<","<<temp_two.coor[1]<<")"<<endl;*/
	/*float x_temp=temp_one.coor[0]/400;
	float y_temp=temp_one.coor[1]/400;


	glBegin(GL_QUADS);
	//glColor3f(1.0f,1.0f,1.0f);
	float x_temp=temp_one.coor[0]/400;
	float y_temp=temp_one.coor[1]/400;
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x_temp,y_temp);

	x_temp=temp_two.coor[0]/400;
	y_temp=temp_two.coor[1]/400;
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x_temp,y_temp);

	x_temp=temp_three.coor[0]/400;
	y_temp=temp_three.coor[1]/400;
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x_temp,y_temp);

	x_temp=temp_four.coor[0]/400;
	y_temp=temp_four.coor[1]/400;
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x_temp,y_temp);*/




	float dot = normal[0]*lightvector[0]+normal[1]*lightvector[1]+normal[2]*lightvector[2];
	cout<< "DOT=====1====="<<dot<<endl;

	dot = dot /(normal[3]*lightvector[3]);
	cout<< "noramal====="<<normal[3]<<endl;
	cout<< "lightvector====="<<lightvector[3]<<endl;
	cout<< "lightvector==4==="<<lightvector[4]<<endl;
	cout<< "DOT=====2====="<<dot<<endl;
	dot = dot * lightvector[4];
	cout<< "DOT=====3====="<<dot<<endl;

	float x_temp1=temp_one.coor[0]/400;
	float y_temp1=temp_one.coor[1]/400;

	float x_temp2=temp_two.coor[0]/400;
	float y_temp2=temp_two.coor[1]/400;
	
	float x_temp3=temp_three.coor[0]/400;
	float y_temp3=temp_three.coor[1]/400;
	
	float x_temp4=temp_four.coor[0]/400;
	float y_temp4=temp_four.coor[1]/400;
	//cout<< "DOT=========="<<dot<<endl;

	dot = 0.3 +dot;

	glBegin(GL_QUADS);
	glColor4f(colour[0]*dot,colour[1]*dot,colour[2]*dot,dot);
	glVertex2f(x_temp1,y_temp1);
	glVertex2f(x_temp2,y_temp2);
	
	glVertex2f(x_temp4,y_temp4);
	glVertex2f(x_temp3,y_temp3);
	glEnd();

	//dda(temp_one.coor[0],temp_one.coor[1],temp_two.coor[0],temp_two.coor[1] );
	//dda(temp_four.coor[0],temp_four.coor[1],temp_three.coor[0],temp_three.coor[1] );
	//dda(temp_one.coor[0],temp_one.coor[1],temp_three.coor[0],temp_three.coor[1] );
	//dda(temp_two.coor[0],temp_two.coor[1],temp_four.coor[0],temp_four.coor[1] );
	/*float a=temp_one.coor[0];
	float b=temp_one.coor[1];
	float c=temp_two.coor[0];
	float d=temp_two.coor[1];

	float k=fabs(d-b);
	float dx=c-a;
	float dy=d-b;
	int size=k+1;
	float tempdata1x[size];
	float tempdata1y[size];
	float tempdata2x[size];
	float tempdata2y[size];

	if(fabs(c-a)>fabs(d-b))
	{
		k=fabs(c-a);
	}
	for(int i=0;i<k;i++)
	{

		tempdata1x[i]=a;
		tempdata1y[i]=b;
		PLOTPOINT(a,b);

		a = a+dx / k;
		b = b+dy / k;
	}

	a=temp_three.coor[0];
	b=temp_three.coor[1];
	c=temp_four.coor[0];
	d=temp_four.coor[1];
	k=fabs(d-b);
	dx=c-a;
	dy=d-b;
	
	if(fabs(c-a)>fabs(d-b))
	{
		k=fabs(c-a);
	}
	for(int i=0;i<k;i++)
	{
		tempdata2x[i]=a;
		tempdata2y[i]=b;
		PLOTPOINT(a,b);
		a = a+dx / k;
		b = b+dy / k;
	}

	for(int i=0;i<=sizeof(tempdata1x);i++)
	{
		a=tempdata1x[i];
		b=tempdata1y[i];
		c=tempdata2x[i];
		d=tempdata2y[i];
		k=fabs(d-b);
		dx=c-a;
		dy=d-b;
		if(fabs(c-a)>fabs(d-b))
		{
			k=fabs(c-a);
		}
		for(int i=0;i<k;i++)
		{
			PLOTPOINT(a,b);
			a = a+dx / k;
			b = b+dy / k;
		}

	}*/

}



void camera::PLOTPOINT(float a, float b)
{
	glBegin(GL_POINTS);
	float x_temp=a/400;
	float y_temp=b/400;
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x_temp,y_temp);
	glEnd();
}
void camera::dda(float a, float b, float c, float d)
{
	float k=fabs(d-b);
	float dx=c-a;
	float dy=d-b;
	if(fabs(c-a)>fabs(d-b))
	{
		k=fabs(c-a);
	}
	for(int i=0;i<k;i++)
	{

		PLOTPOINT(a,b);

		a = a+dx / k;
		b = b+dy / k;
	}
}

