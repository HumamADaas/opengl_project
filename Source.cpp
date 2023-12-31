
#include <windows.h>		// Header File For Windows
#include <Gl\GL.H>			// Header File For The OpenGL32 Library
#include <Gl\GLU.H>			// Header File For The GLu32 Library
#include <Gl\GLAUX.H>		// Header File For The Glaux Library
#include <cmath>
#include<texture.h>

//#include <math.h>

//#include "texture.h"
#include"Position.h"
#include "camera.h"
#include"3DTexture.h"
#include"Model_3DS.h"
//#include <fstream>

# define M_PI           3.14159265358979323846

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc




GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

Camera MyCamera;
//
int  image, image2, image3, floorImg, wallImg;

//parts of alaqsa
int doorOfMosque, wall1, roof, column,yellow,carpet, crescent,
//the top side
	topWall1;
bool convert = false;


// skybox
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;

// model 3d
Model_3DS* tree;


GLUquadric *quadric = gluNewQuadric();


//draw octagon
void Draw_alaqsa(int door = -1, int wallMosque = -1, int carpet = -1) {
	
	glTranslated(0, 0, -20);
	
	if (door != -1) {
		//first door
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, door);

		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-1, -1, 0);

		glTexCoord2d(1, 0);
		glVertex3d(2, -1, 0);

		glTexCoord2d(1, 1);
		glVertex3d(2, 2, 0);

		glTexCoord2d(0, 1);
		glVertex3d(-1, 2, 0);

		glEnd();
		glPopMatrix();
	}

	//first wall (on the left)
	if (wallMosque != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wallMosque);

		glBegin(GL_QUADS);

		glTexCoord2d(0, 0);
		glVertex3d(-4, -1, -3);

		glTexCoord2d(1, 0);
		glVertex3d(-1, -1, 0);

		glTexCoord2d(1, 1);
		glVertex3d(-1, 2, 0);

		glTexCoord2d(0, 1);
		glVertex3d(-4, 2, -3);


		glEnd();

		glPopMatrix();
	}
	
	//second door
	if (door != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, door);

		glBegin(GL_QUADS);

		glTexCoord2d(0, 0);
		glVertex3d(-4, -1, -3);

		glTexCoord2d(1, 0);
		glVertex3d(-4, -1, -6);


		glTexCoord2d(1, 1);
		glVertex3d(-4, 2, -6);

		glTexCoord2d(0, 1);
		glVertex3d(-4, 2, -3);

		glEnd();
		glPopMatrix();
	}

	//second wall
	if (wallMosque != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wallMosque);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-1, -1, -9);

		glTexCoord2d(0, 1);
		glVertex3d(-1, 2, -9);

		glTexCoord2d(1, 1);
		glVertex3d(-4, 2, -6);

		glTexCoord2d(1, 0);
		glVertex3d(-4, -1, -6);
		glEnd();
		glPopMatrix();
	}
	
	//third door
	if (door != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, door);

		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-1, -1, -9);

		glTexCoord2d(1, 0);
		glVertex3d(2, -1, -9);

		glTexCoord2d(1, 1);
		glVertex3d(2, 2, -9);

		glTexCoord2d(0, 1);
		glVertex3d(-1, 2, -9);

		glEnd();
		glPopMatrix();
	}


	//third wall 
	if (wallMosque != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wallMosque);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(2, -1, -9);

		glTexCoord2d(0, 1);
		glVertex3d(2, 2, -9);

		glTexCoord2d(1, 1);
		glVertex3d(5, 2, -6);

		glTexCoord2d(1, 0);
		glVertex3d(5, -1, -6);
		glEnd();
		glPopMatrix();
	}
	
	//fourth door
	if (door != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, door);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(5, -1, -6);

		glTexCoord2d(0, 1);
		glVertex3d(5, 2, -6);

		glTexCoord2d(1, 1);
		glVertex3d(5, 2, -3);

		glTexCoord2d(1, 0);
		glVertex3d(5, -1, -3);
		glEnd();
		glPopMatrix();
	}

	//fourth wall 
	if (wallMosque != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, wallMosque);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(5, -1, -3);

		glTexCoord2d(0, 1);
		glVertex3d(5, 2, -3);

		glTexCoord2d(1, 1);
		glVertex3d(2, 2, 0);

		glTexCoord2d(1, 0);
		glVertex3d(2, -1, 0);
		glEnd();
		glPopMatrix();
	}
	
	
	
	// the ground
	//
	if (carpet != -1) {
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, carpet);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-1, -1, 0);

		glTexCoord2d(0, 9);
		glVertex3d(-1, -1, -9);

		glTexCoord2d(3, 6);
		glVertex3d(-4, -1, -6);

		glTexCoord2d(3, 3);
		glVertex3d(-4, -1, -3);
		glEnd();
		glPopMatrix();

		//
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, carpet);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(2, -1, -9);

		glTexCoord2d(0, 9);
		glVertex3d(2, -1, 0);

		glTexCoord2d(3, 6);
		glVertex3d(5, -1, -3);

		glTexCoord2d(3, 3);
		glVertex3d(5, -1, -6);




		glEnd();
		glPopMatrix();


		//the middle rectangle 
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, carpet);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-1, -1, -9);

		glTexCoord2d(0, 9);
		glVertex3d(-1, -1, 0);

		glTexCoord2d(3, 9);
		glVertex3d(2, -1, 0);

		glTexCoord2d(3, 0);
		glVertex3d(2, -1, -9);

		glEnd();
		glPopMatrix();
	}
	
}



void DrawCylinder(float radius, float height, int num_segments,int texture =-1,Position temp = Position(0.0,0.0,0.0)) {
	glPushMatrix();
	if (texture != -1) {
		glBindTexture(GL_TEXTURE_2D, texture);
		//glTranslated(0.7, 4.7, -4.7);
		glTranslated(temp.getX(), temp.getY(), temp.getZ());
		glRotated(180, 0, 0, 1);

		glBegin(GL_QUADS);
		for (int i = 0; i < num_segments; i++) {
			float theta1 = 2.0f * 3.1415926f * float(i) / float(num_segments);
			float theta2 = 2.0f * 3.1415926f * float(i + 1) / float(num_segments);
			float s1 = float(i) / float(num_segments);
			float s2 = float(i + 1) / float(num_segments);
			// Side face
			glTexCoord2f(s1, 0);
			glVertex3f(radius * cosf(theta1), height, radius * sinf(theta1));
			glTexCoord2f(s2, 0);
			glVertex3f(radius * cosf(theta2), height, radius * sinf(theta2));
			glTexCoord2f(s2, 1);
			glVertex3f(radius * cosf(theta2), 0, radius * sinf(theta2));
			glTexCoord2f(s1, 1);
			glVertex3f(radius * cosf(theta1), 0, radius * sinf(theta1));
		}
		glEnd();
	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture);
		//glTranslated(0.7, 4.7, -4.7);
		glTranslated(temp.getX(), temp.getY(), temp.getZ());
		glRotated(180, 0, 0, 1);

		glBegin(GL_QUADS);
		for (int i = 0; i < num_segments; i++) {
			float theta1 = 2.0f * 3.1415926f * float(i) / float(num_segments);
			float theta2 = 2.0f * 3.1415926f * float(i + 1) / float(num_segments);
			float s1 = float(i) / float(num_segments);
			float s2 = float(i + 1) / float(num_segments);
			// Side face
			glTexCoord2f(s1, 0);
			glVertex3f(radius * cosf(theta1), height, radius * sinf(theta1));
			glTexCoord2f(s2, 0);
			glVertex3f(radius * cosf(theta2), height, radius * sinf(theta2));
			glTexCoord2f(s2, 1);
			glVertex3f(radius * cosf(theta2), 0, radius * sinf(theta2));
			glTexCoord2f(s1, 1);
			glVertex3f(radius * cosf(theta1), 0, radius * sinf(theta1));
		}

		glEnd();
	}
	glPopMatrix();
	/////////////
	/*
	glPopMatrix();
	for (int i = 0; i <= 0; i++) {
		float theta1 = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float theta2 = 2.0f * 3.1415926f * float(i + 1) / float(num_segments);

		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex3d(-1, 2, 0);
		glVertex3d(2, 2, 0);
		glVertex3f(radius * cosf(theta1), height, radius * sinf(theta1));
		glVertex3f(radius * cosf(theta2), height, radius * sinf(theta2));
		glEnd();
		glPopMatrix();
	}
	*/
}

void draw_the_top() {
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3d(-1, 2, 0);
		
		glTexCoord2f(0, 1);
		glVertex3d(2, 2, 0);

		glTexCoord2f(1, 1);
		glVertex3d(1.23, 2.5, -2.7);

		glTexCoord2f(0, 1);
		glVertex3d(-0.60, 2.5, -3.2);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-4, 2, -3);
		
		glTexCoord2d(1, 0);
		glVertex3d(-1, 2, 0);

		glTexCoord2d(1, 1);
		glVertex3d(-0.60, 2.5, -3.2);

		glTexCoord2d(0, 1);
		glVertex3d(-1.35, 2.5, -4.766);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-4, 2, -6);

	glTexCoord2d(1, 0);
	glVertex3d(-4, 2, -3);

	glTexCoord2d(1, 1);
	glVertex3d(-1.27, 2.5, -4.8);

	glTexCoord2d(0, 1);
	glVertex3d(-0.6, 2.5, -6.22);

	glEnd();
	glPopMatrix();
	
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1, 2, -9);

	glTexCoord2d(1, 0);
	glVertex3d(-4, 2, -6);

	glTexCoord2d(1, 1);
	glVertex3d(-0.7, 2.5, -6.22);

	glTexCoord2d(0, 1);
	glVertex3d(1.15, 2.5, -6.7);

	glEnd();
	glPopMatrix();

	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex3d(-1, 2, -9);

	glTexCoord2f(1, 0);
	glVertex3d(1.15, 2.5, -6.65);

	glTexCoord2f(1, 1);
	glVertex3d(2.51, 2.5, -5.56);

	glTexCoord2f(0, 1);
	glVertex3d(2, 2, -9);
	glEnd();
	glPopMatrix();
	//////////////////////////////////////////////
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);

	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(5, 2, -6);

		glTexCoord2d(1, 0);
		glVertex3d(2, 2, -9);

		glTexCoord2d(1, 1);
		glVertex3d(2.51, 2.5, -5.56);

		glTexCoord2d(0, 1);
		glVertex3d(2.5, 2.5, -3.8);
		//glVertex3d(2.75, 2.5, -3.85);//z = -3.9, x = 2.5 //z = -3.84, x = 2.6


	glEnd();
	glPopMatrix();

	
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3d(2, 2, 0);
		
		glTexCoord2d(1, 0);
		glVertex3d(5, 2, -3);
		//glVertex3d(2, 2, 0);

		glTexCoord2d(1, 1);
		glVertex3d(5, 2, -6);
		glTexCoord2d(0, 1);
		glVertex3d(2.5, 2.5, -3.8);
		
		glTexCoord2d(0, 0);

		glVertex3d(1.23, 2.5, -2.7);

	glEnd();
	glPopMatrix();


}

//rectangel
void draw_rectangles() {
	
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.5, 0.0, 0.0);
	glVertex3f( 1.5, 0.0, -1.0);
	glVertex3f(0.0, 0.0 , -1.0);

	glVertex3f(0.0, 0.5, -0.5);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	
}
//column
void draw_column(int radius, int height, int num_segments,Position temp = Position(0.0,0.0,0.0)) {
	double angle_increment = 2 * 3.14 / num_segments;
	double x, y;
	
	
	glPushMatrix();
	glTranslated(temp.getX(),temp.getY(),temp.getZ());
	
	glBindTexture(GL_TEXTURE_2D, column);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= num_segments; i++) {
		x = radius * cos(i * angle_increment);
		y = radius * sin(i * angle_increment);
		glTexCoord2f((float)i / num_segments, 0.0f);
		glVertex3d(x, 0, y);
		glTexCoord2f((float)i / num_segments, 1.0f);
		glVertex3d(x, height, y);
	}
	glEnd();
	glPopMatrix();
	
}

void draw_rectangle(Position temp = Position(0, 0, 0) , int texture = - 1) {
	//front
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(temp.getX() - 0.1, temp.getY() + 2, temp.getZ());
		glTexCoord2d(1, 0); glVertex3d(temp.getX() + 0.1, temp.getY() + 2, temp.getZ());
		glTexCoord2d(1, 1); glVertex3d(temp.getX() + 0.1, temp.getY() + 4, temp.getZ());
		glTexCoord2d(0, 1); glVertex3d(temp.getX() - 0.1, temp.getY() + 4, temp.getZ());

		glEnd();
	glPopMatrix();
	//right
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);  glVertex3d(temp.getX() + 0.1, temp.getY() + 2, temp.getZ());
		glTexCoord2d(1, 0); glVertex3d(temp.getX() + 0.1, temp.getY() + 2, temp.getZ() - 0.1);
		glTexCoord2d(1, 1); glVertex3d(temp.getX() + 0.1, temp.getY() + 4, temp.getZ() - 0.1);
		glTexCoord2d(0, 1); glVertex3d(temp.getX() + 0.1, temp.getY() + 4, temp.getZ());
		glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(temp.getX() - 0.1, temp.getY() + 2, temp.getZ() - 0.1);
	glTexCoord2d(1, 0); glVertex3d(temp.getX() + 0.1, temp.getY() + 2, temp.getZ() - 0.1);
	glTexCoord2d(1, 1); glVertex3d(temp.getX() + 0.1, temp.getY() + 4, temp.getZ() - 0.1);
	glTexCoord2d(0, 1); glVertex3d(temp.getX() - 0.1, temp.getY() + 4, temp.getZ() - 0.1);

	glEnd();
	glPopMatrix();

	//left
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(temp.getX() - 0.1, temp.getY() + 2, temp.getZ());
	glTexCoord2d(1, 0); glVertex3d(temp.getX() - 0.1, temp.getY() + 2, temp.getZ() - 0.1);
	glTexCoord2d(1, 1); glVertex3d(temp.getX() - 0.1, temp.getY() + 4, temp.getZ() - 0.1);
	glTexCoord2d(0, 1); glVertex3d(temp.getX() - 0.1, temp.getY() + 4, temp.getZ());
	glEnd();
	glPopMatrix();

}

//dome
void DrawDome(float rad, int texture=-1 , Position center = Position(0, 0, 0))
{	
	glPushMatrix();
	draw_rectangle(center,crescent);

	glTranslated(center.getX(), center.getY(), center.getZ());
	float lastcenter = rad * sin(3.14 / 2);
	float lastr = rad * cos(3.14 / 2);
	for (float vertical = 3.14 / 2.0; vertical >= 0; vertical -= 0.1)
	{


		float centeri = rad * sin(vertical);
		float ri = rad * cos(vertical);
		int col = 0;
		for (float horizin = 0; horizin <= 2 * 3.14 + 0.1; horizin += 0.1)
		{
			Position a = Position(ri * cos(horizin), centeri, ri * sin(horizin));
			Position b = Position(ri * cos(horizin + 0.1), centeri, ri * sin(horizin + 0.1));
			Position c = Position(lastr * cos(horizin), lastcenter, lastr * sin(horizin));
			Position d = Position(lastr * cos(horizin + 0.1), lastcenter, lastr * sin(horizin + 0.1));
			if (texture != -1)
			{
				glBindTexture(GL_TEXTURE_2D, texture);
				glBegin(GL_QUADS);
				glTexCoord2d(1 - (horizin) / (2 * 3.14), 0.5 + sin(vertical - 0.1) / 2.0);
				glVertex3f(a.getX(), a.getY(), a.getZ());
				glTexCoord2d(1 - (horizin + 0.1) / (2 * 3.14), 0.5 + sin(vertical - 0.1) / 2.0);
				glVertex3f(b.getX(), b.getY(), b.getZ());
				glTexCoord2d(1 - (horizin + 0.1) / (2 * 3.14), 0.5 + sin(vertical) / 2.0);
				glVertex3f(d.getX(), d.getY(), d.getZ());
				glTexCoord2d(1 - (horizin) / (2 * 3.14), 0.5 + sin(vertical) / 2.0);
				glVertex3f(c.getX(), c.getY(), c.getZ());
				glEnd();
			}
			else
			{
				glBegin(GL_QUADS);
				glVertex3f(a.getX(), a.getY(), a.getZ());
				glVertex3f(b.getX(), b.getY(), b.getZ());
				glVertex3f(d.getX(), d.getY(), d.getZ());
				glVertex3f(c.getX(), c.getY(), c.getZ());
				glEnd();
			}
		}
		lastr = ri;
		lastcenter = centeri;
	}
	//glTranslated(-center.getX(), -center.getY(), -center.getZ());

	glPopMatrix();
};


////////////////////////////////////////////////////////////////////////////
void drawUnitCube() {

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//Back Face
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	//Right Face
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	//Left Face
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	//Top Face
	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}

void drawMyCube(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	drawUnitCube();

	glPopMatrix();

}


void drawMySphere(GLUquadric *quadric, float x, float y, float z, float radius, float xRotate, float yRotate, float zRotate) {

	glPushMatrix();

	glTranslatef(x, y, z);
	glRotatef(zRotate, 0, 0, 1);
	glRotatef(yRotate, 0, 1, 0);
	glRotatef(xRotate, 1, 0, 0);
	gluSphere(quadric, radius, 32, 32);

	glPopMatrix();
}

void drawMyCylinder(GLUquadric *quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(zRotate, 0, 0, 1);
	glRotatef(yRotate, 0, 1, 0);
	glRotatef(xRotate, 1, 0, 0);
	gluCylinder(quadric, baseRadius, topRadius, height, 32, height * 5);
	glPopMatrix();
}


void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SKYFRONT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SKYLEFT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SKYUP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SKYDOWN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}


void Key(bool* keys, float speed)
{
	if (keys['S'])
		MyCamera.RotateX(-1 * speed);
	if (keys['W'])
		MyCamera.RotateX(1 * speed);
	if (keys['D'])
		MyCamera.RotateY(-1 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
		MyCamera.RotateY(1 * speed);
	if (keys[VK_UP]) {
		MyCamera.MoveForward(1 * speed);
		
	}
	if (keys[VK_DOWN]) {
		MyCamera.MoveForward(-1 * speed);
		
	}
	if (keys[VK_RIGHT])
		MyCamera.MoveRight(1 * speed);
	if (keys[VK_LEFT])
		MyCamera.MoveRight(-1 * speed);
	if (keys['O'])
		MyCamera.MoveUpward(1 * speed);
	if (keys['L'])
		MyCamera.MoveUpward(-1 * speed );
	if (keys['T'] && keys['H']) {
		MyCamera.Position.z = 40;
		MyCamera.Position.y = 10;
	}
	if (keys['F'] && keys['I']) {
		MyCamera.Position.z = 15;
		MyCamera.Position.y = 0;
	}
	
}


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations



	glEnable(GL_TEXTURE_2D);

	//image = LoadTexture((char*)"back.bmp", 255);
	//image2 = LoadTexture((char*)"DU icon.bmp");
	//image3 = LoadTexture((char*)"building.bmp", 255);
	floorImg = LoadTexture((char*)"floor.bmp", 255);
	//wallImg = LoadTexture((char*)"wall.bmp", 255);
	
	// skybox
	SKYFRONT = LoadTexture((char*)"around1.bmp", 255);
	SKYBACK = LoadTexture((char*)"around1.bmp", 255);
	SKYLEFT = LoadTexture((char*)"around3.bmp", 255);
	SKYRIGHT = LoadTexture((char*)"around3.bmp", 255);
	SKYUP = LoadTexture((char*)"up.bmp", 255);
	SKYDOWN = LoadTexture((char*)"OIP.bmp", 255);
	// note if you load a image the opengl while on the GL_Texture_2D himself
	
	doorOfMosque = LoadTexture((char*)"door.bmp", 255);
	wall1 = LoadTexture((char*)"wall1.bmp", 255); //wall6
	topWall1 = LoadTexture((char*)"R_3.bmp", 255); 
	roof = LoadTexture((char*)"top2.bmp", 255);
	column = LoadTexture((char*)"column2.bmp", 255);
	yellow = LoadTexture((char*)"yellow.bmp", 255);
	carpet = LoadTexture((char*)"carpet.bmp", 255);
	crescent = LoadTexture((char*)"top.bmp", 255);
	 //= LoadTexture((char*)".bmp", 255);
	
	//glDisable(GL_TEXTURE_2D);
	
	//glEnable(GL_TEXTURE_2D);
	
	
	//position  of camera
	MyCamera = Camera();
	MyCamera.Position.x = 0;
	MyCamera.Position.y = 0;
	MyCamera.Position.z = 15;
	
	/*
	mosque = new Model_3DS();
	mosque->Load((char*)"R.3ds");
	mosque->pos.x = -10;
	mosque->pos.y = 0;
	mosque->pos.z = 0;
	mosque->scale = 0.1;
	*/
	//GLTexture BARK, Leaf;
	
	//Leaf.LoadBMP((char*)"bat.bmp");
	//BARK.LoadBMP((char*)"bark_loo.bmp");

	//tree->Materials[0].tex = BARK;
	//tree->Materials[1].tex = Leaf;
	
	

	return TRUE;										// Initialization Went OK
}
float a=0.1;
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glTranslated(0, 0, -80);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	


	MyCamera.Render();
	Key(keys, 0.009);
	
	//Draw_Skybox(0, 0, 0, 100, 100, 100);
	
	Draw_alaqsa(doorOfMosque,wall1,carpet);
	DrawCylinder(2,2.3 , 7,topWall1,Position(0.7, 4.7, -4.7));
	draw_the_top();
	//draw_column(1, 6, 50); // is ok
	//draw_rectangles();
	
	DrawDome(2, yellow, Position(0.7, 4.5, -4.7));
	

	///////////////////////////////////draw the ground///////////////////////
	/*
	glPushMatrix();
	glTranslated(0, 0, -20);

	glBindTexture(GL_TEXTURE_2D, floorImg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);		
	glVertex3d(-50, -1.5, 50);

	glTexCoord2d(0, 1);
	glVertex3d(50, -1.5, 50);

	glTexCoord2d(1, 1);
	glVertex3d(50, -1.5, -50);

	glTexCoord2d(1, 0);		
	glVertex3d(-50, -1.5, -50);

	glEnd();
	glPopMatrix();
	*/
	////////////////////////////////////////////////////////////////
	//mosque->Draw();
	return TRUE;
	
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	char ch[] = "*OpenGL template*";
	if (!CreateGLWindow(ch, 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				char c[] = "OpenGL template";
				if (!CreateGLWindow(c, 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}
