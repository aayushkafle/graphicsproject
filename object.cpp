#include "transformation.h"
#include "object.h"
using namespace std;
float light[3]={1000,1000,1000};
float intensity=1000;
float ref_point[3]={0,0,-3000};
float camera_pos[3]={0,0,-500};

float camera_orient[2]={0,0};


camera c1(ref_point,camera_pos,camera_orient);

/*camera_control::camera_control()
{
	SDL_Event event_key;

	while(SDL_PollEvent(&event_key))
	{
		switch(event_key.type)
		{
			case SDLK_w:
			c1.ref_point[2]+=2;
			break;

			case SDLK_a:
			c1.ref_point[2]+=2;
			break;
		}
	}
}*/

line::line()
{

}
line::line(point_matrix *end_pointss)
{
	for(int i=0;i<2;i++)
	{
		end_points[i]=end_pointss[i];
	}
}
line::line(point_matrix one, point_matrix two)
{
	end_points[0]=one;
	end_points[1]=two;
}
void line::makeline(point_matrix one, point_matrix two)
{
	end_points[0]=one.equalsto();
	end_points[1]=two.equalsto();
	/*cout<<"lines made"<<endl;
	one.drawPoint();
	two.drawPoint();
	cout<<"lines same??"<<endl;
	end_points[0].drawPoint();
	end_points[1].drawPoint();*/

}


void line::drawLine()
{
	//c1.DRAWTHELINE(end_points[0],end_points[1]);
	/*cout<<end_points[0].coor[0]<<","<<end_points[0].coor[1]<<","<<end_points[0].coor[2]<<"--->";
	cout<<end_points[1].coor[0]<<","<<end_points[1].coor[1]<<","<<end_points[1].coor[2]<<endl;*/
}

line::~line()
{

}
line line::equalsto()
{
	//return *this;

	line temp;
	for(int i=0; i<2; i++)
	{
		temp.end_points[i]= end_points[i].equalsto();
	}
	return temp;
}

rectangle::rectangle()
{

}
rectangle::rectangle(line *edgess)
{
	for(int i=0;i<4;i++)
	{
		edges[i]=edgess[i];
	}
	
}

rectangle::rectangle(line one, line two, line three, line four)
{
	edges[0]=one;
	edges[1]=two;
	edges[2]=three;
	edges[3]=four;
}
void rectangle::makerectangle(line one, line two, line three, line four, float *colours)
{
	edges[0]=one;
	edges[1]=two;
	edges[2]=three;
	edges[3]=four;

	its_points[0]=one.end_points[0];
	its_points[1]=one.end_points[1];
	its_points[2]=two.end_points[0];
	its_points[3]=two.end_points[1];

	float AB[3]={its_points[1].coor[0]-its_points[0].coor[0],its_points[1].coor[1]-its_points[0].coor[1],its_points[1].coor[2]-its_points[0].coor[2]};
	float AC[3]={its_points[1].coor[0]-its_points[2].coor[0],its_points[1].coor[1]-its_points[2].coor[1],its_points[1].coor[2]-its_points[2].coor[2]};
	float cross[3]={((AB[0]*AC[1])-(AB[1]*AC[0])),-((AB[0]*AC[2])-(AB[2]*AC[0])),((AB[1]*AC[2])-(AB[2]*AC[1]))};


	colour[0]=colours[0];
	colour[1]=colours[1];
	colour[2]=colours[2];
	
	normal[0]=cross[0];
	normal[1]=cross[1];
	normal[2]=cross[2];
	normal[3]=pow(pow(normal[0],2)+pow(normal[1],2)+pow(normal[2],2),0.5);

	lightvector[0]=its_points[0].coor[0]-light[0];
	lightvector[1]=its_points[0].coor[1]-light[1];
	lightvector[2]=its_points[0].coor[2]-light[2];

	lightvector[3]=pow(pow(lightvector[0],2)+pow(lightvector[1],2)+pow(lightvector[2],2),0.5);
	lightvector[4]=intensity / lightvector[3];
}
void rectangle::drawRectangle()
{
	float cameravector[3]={its_points[0].coor[0]-light[0],its_points[0].coor[1]-light[1],its_points[0].coor[2]-light[2]};
	float dot=normal[0]*cameravector[0]+normal[1]*cameravector[1]+normal[2]*cameravector[2];
	if (dot>=0)
	{
		c1.DRAWTHEFACE(its_points,colour,normal,lightvector);
	}
	//for(int i=0; i<4; i++)
	//{
		//edges[1].drawLine();
		//edges[i].drawLine();
	//}
}

rectangle::~rectangle()
{

}
rectangle rectangle::equalsto()
{
	//return *this;
	rectangle temp;
	for(int i=0; i<4; i++)
	{
		temp.edges[i] = edges[i].equalsto();
	}
	return temp;
}

cuboid::cuboid()
{

}
cuboid::cuboid(point_matrix p1,float *orientations, float *dimensions)

{	
	center=p1.equalsto();
	for(int i=0;i<3;i++)
	{
		colour[i]=orientations[i];
		dimension[i]=dimensions[i];
		cout<<i<<"="<<dimension[i]<<endl;
	}





				float tempvertices7[3]={(-(dimension[0]/2)+center.coor[0]),( (dimension[1]/2)+center.coor[1]),(-(dimension[2]/2)+center.coor[2])};				float tempvertices6[3]={( (dimension[0]/2)+center.coor[0]),( (dimension[1]/2)+center.coor[1]),(-(dimension[2]/2)+center.coor[2])};

	float tempvertices3[3]={(-(dimension[0]/2)+center.coor[0]),( (dimension[1]/2)+center.coor[1]),( (dimension[2]/2)+center.coor[2])};				float tempvertices2[3]={( (dimension[0]/2)+center.coor[0]),( (dimension[1]/2)+center.coor[1]),( (dimension[2]/2)+center.coor[2])};





				float tempvertices4[3]={(-(dimension[0]/2)+center.coor[0]),(-(dimension[1]/2)+center.coor[1]),(-(dimension[2]/2)+center.coor[2])};				float tempvertices5[3]={( (dimension[0]/2)+center.coor[0]),(-(dimension[1]/2)+center.coor[1]),(-(dimension[2]/2)+center.coor[2])};

	float tempvertices0[3]={(-(dimension[0]/2)+center.coor[0]),(-(dimension[1]/2)+center.coor[1]),(+(dimension[2]/2)+center.coor[2])};				float tempvertices1[3]={( (dimension[0]/2)+center.coor[0]),(-(dimension[1]/2)+center.coor[1]),( (dimension[2]/2)+center.coor[2])};

	cout<<"floatbanaye"<<endl;

	cout<<tempvertices7[0]<<","<<tempvertices7[1]<<","<<tempvertices7[2]<<endl;
	cout<<tempvertices6[0]<<","<<tempvertices6[1]<<","<<tempvertices6[2]<<endl;
	cout<<tempvertices5[0]<<","<<tempvertices5[1]<<","<<tempvertices5[2]<<endl;
	cout<<tempvertices4[0]<<","<<tempvertices4[1]<<","<<tempvertices4[2]<<endl;
	cout<<tempvertices3[0]<<","<<tempvertices3[1]<<","<<tempvertices3[2]<<endl;
	cout<<tempvertices2[0]<<","<<tempvertices2[1]<<","<<tempvertices2[2]<<endl;
	cout<<tempvertices1[0]<<","<<tempvertices1[1]<<","<<tempvertices1[2]<<endl;
	cout<<tempvertices0[0]<<","<<tempvertices0[1]<<","<<tempvertices0[2]<<endl;
	cout<<"milena ra??"<<endl;
	
	vertices[0].makepoint(tempvertices0);
	vertices[1].makepoint(tempvertices1);
	vertices[2].makepoint(tempvertices2);
	vertices[3].makepoint(tempvertices3);
	vertices[4].makepoint(tempvertices4);
	vertices[5].makepoint(tempvertices5);
	vertices[6].makepoint(tempvertices6);
	vertices[7].makepoint(tempvertices7);

	/*for(int i=0; i<8; i++)
	{
		vertices[i].drawPoint();
		cout<<"vertices print bhayo??"<<endl;
	}
	cout<<"vertex assigned"<<endl;*/


	edges_c[0].makeline(vertices[0],vertices[1]);
	edges_c[1].makeline(vertices[1],vertices[2]);
	edges_c[2].makeline(vertices[3],vertices[2]);
	edges_c[3].makeline(vertices[0],vertices[3]);
	edges_c[4].makeline(vertices[1],vertices[5]);
	edges_c[5].makeline(vertices[2],vertices[6]);
	edges_c[6].makeline(vertices[0],vertices[4]);
	edges_c[7].makeline(vertices[3],vertices[7]);
	edges_c[8].makeline(vertices[4],vertices[5]);
	edges_c[9].makeline(vertices[5],vertices[6]);
	edges_c[10].makeline(vertices[7],vertices[6]);
	edges_c[11].makeline(vertices[4],vertices[7]);

	/*for(int i=0; i<12; i++)
	{
		edges_c[i].drawLine();
		cout<<"line print bhayo??"<<endl;
	}

	cout<<"edges made"<<endl;*/


	faces[0].makerectangle(edges_c[0],edges_c[2],edges_c[1],edges_c[3],colour);
	faces[1].makerectangle(edges_c[8],edges_c[10],edges_c[9],edges_c[11],colour);
	faces[2].makerectangle(edges_c[4],edges_c[5],edges_c[1],edges_c[9],colour);
	faces[3].makerectangle(edges_c[6],edges_c[7],edges_c[3],edges_c[11],colour);
	faces[4].makerectangle(edges_c[0],edges_c[8],edges_c[4],edges_c[6],colour);
	faces[5].makerectangle(edges_c[2],edges_c[10],edges_c[5],edges_c[7],colour);
	

}

void cuboid::drawCuboid()
{
	faces[0].drawRectangle();
	faces[1].drawRectangle();
	faces[2].drawRectangle();
	faces[3].drawRectangle();
	faces[4].drawRectangle();
	faces[5].drawRectangle();
}

cuboid::~cuboid()
{

}

void event::EVENT_W()
{
	//cout<<"old----("<<c1.camera_pos[2]<<endl;
	c1.camera_pos[2]=c1.camera_pos[2]+20;
	//cout<<"w pressed----("<<c1.camera_pos[2]<<endl;
}

void event::EVENT_S()
{
	//cout<<"old----("<<c1.camera_pos[2]<<endl;
	c1.camera_pos[2]=c1.camera_pos[2]-20;
	//cout<<"s pressed----("<<c1.camera_pos[2]<<endl;
}
void event::EVENT_A()
{
	cout<<"old----("<<c1.camera_pos[0]<<endl;
	c1.camera_pos[0]=c1.camera_pos[0]+20;
	cout<<"a pressed----("<<c1.camera_pos[0]<<endl;
}

void event::EVENT_D()
{
	cout<<"old----("<<c1.camera_pos[0]<<endl;
	c1.camera_pos[0]=c1.camera_pos[0]-20;
	cout<<"d pressed----("<<c1.camera_pos[0]<<endl;
}
void event::EVENT_SHIFT()
{
	cout<<"old----("<<c1.camera_pos[1]<<endl;
	c1.camera_pos[1]=c1.camera_pos[1]+20;
	cout<<"shift pressed----("<<c1.camera_pos[1]<<endl;
}

void event::EVENT_SPACE()
{
	cout<<"old----("<<c1.camera_pos[1]<<endl;
	c1.camera_pos[1]=c1.camera_pos[1]-20;
	cout<<"space pressed----("<<c1.camera_pos[1]<<endl;
}
void event::EVENT_UP()
{
	//cout<<"old----("<<c1.camera_pos[1]<<endl;
	c1.camera_orient[0]=c1.camera_orient[0]+2;
	//cout<<"space pressed----("<<c1.camera_pos[1]<<endl;
}
void event::EVENT_DOWN()
{
	//cout<<"old----("<<c1.camera_pos[1]<<endl;
	c1.camera_orient[0]=c1.camera_orient[0]-2;
	//cout<<"space pressed----("<<c1.camera_pos[1]<<endl;
}
void event::EVENT_LEFT()
{
	//cout<<"old----("<<c1.camera_pos[1]<<endl;
	c1.camera_orient[1]=c1.camera_orient[1]-2;
	//cout<<"space pressed----("<<c1.camera_pos[1]<<endl;
}
void event::EVENT_RIGHT()
{
	//cout<<"old----("<<c1.camera_pos[1]<<endl;
	c1.camera_orient[1]=c1.camera_orient[1]+2;
	//cout<<"space pressed----("<<c1.camera_pos[1]<<endl;
}
