/*****************************************************************************
FILE : submit.c (311170030 2017-2018 Assignment 1)
NOTE : you have to implement functions in this file
*****************************************************************************/
/*****************************************************************************
Student Information
Student ID:
Student Name: MD TAUHIDUL ISLAM
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
const GLdouble FRUSTDIM = 100.f;

enum animationMode { IMMOBILE_MODE, THORUS_MODE, TEAPOT_MODE, SPHERE_MODE, CONE_MODE, CUBE_MODE };
enum lightMode { NORMAL_LIGHT, SPOT_LIGHT };

animationMode mode;
lightMode light_mode;

/* Objects parameters */

/* Cube */
float angle_cube;

/* Sphere */
float size_sphere;
float grow_sphere;

/* Thorus */
float grow_thorus;
float inner_thorus;
float outer_thorus;

/* Cone */
float grow_cone;
float high_cone;

/* Teapot */
float angle_teapot;


/* Init the objects parameters */
void initObjectsParameters() {
	mode = IMMOBILE_MODE;
	light_mode = SPOT_LIGHT;
	angle_cube = 0.6;
	size_sphere = 0.3;
	grow_sphere = 0.0003;
	grow_thorus = 0.001;
	inner_thorus = 0.03;
	outer_thorus = 0.8;
	grow_cone = 0.0006;
	high_cone = 0.8;
	angle_teapot = 0.0;
	
}

void init(void) // All Setup For OpenGL Goes Here
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void display(void) // Here's Where We Do All The Drawing
{

	// Lights
	GLfloat light_pos0[] = { 0.75, 1.0, -1.0, 0.0 };
	GLfloat spot_pos0[] = { 0.75, 1.0, -1.0, 1.0 };
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };


	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	/* Material */
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
	/*----------------------------------------------*/

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	if (light_mode == SPOT_LIGHT)
		glLightfv(GL_LIGHT0, GL_POSITION, spot_pos0);
	else if (light_mode == NORMAL_LIGHT)
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Objects
	// Reset transformation
	glLoadIdentity();

	// Draw the planes
	glBegin(GL_TRIANGLES);
	glColor3f(0.8, 0.8, 0.8);
	//glPushMatrix();

	// Plane in the middle of the screen
	glVertex3f(-0.75, -0.75, 0.75);
	glVertex3f(-0.75, 0.75, 0.75);
	glVertex3f(0.75, 0.75, 0.75);

	glColor3f(0.8, 0.3, 0.8);

	glVertex3f(-0.75, -0.75, 0.75);
	glVertex3f(0.75, 0.75, 0.75);
	glVertex3f(0.75, -0.75, 0.75);

	// Left plane
	glVertex3f(-0.75, -0.75, 0.75);
	glVertex3f(-1.2, -1.2, -0.75);
	glVertex3f(-1.2, 1.2, -0.75);

	glColor3f(0.8, 0.4, 0.8);

	glVertex3f(-1.2, 1.2, -0.75);
	glVertex3f(-0.75, 0.75, 0.75);
	glVertex3f(-0.75, -0.75, 0.75);

	// Right plane
	glVertex3f(0.75, -0.75, 0.75);
	glVertex3f(1.2, -1.2, -0.75);
	glVertex3f(1.2, 1.2, -0.75);

	glColor3f(0.8, 0.5, 0.8);

	glVertex3f(1.2, 1.2, -0.75);
	glVertex3f(0.75, 0.75, 0.75);
	glVertex3f(0.75, -0.75, 0.75);

	// Top plane
	glVertex3f(-0.75, 0.75, 0.75);
	glVertex3f(-1.2, 1.2, -0.75);
	glVertex3f(1.2, 1.2, -0.75);

	glColor3f(0.8, 0.6, 0.8);

	glVertex3f(1.2, 1.2, -0.75);
	glVertex3f(0.75, 0.75, 0.75);
	glVertex3f(-0.75, 0.75, 0.75);

	// Bottom plane
	glVertex3f(-0.75, -0.75, 0.75);
	glVertex3f(-1.2, -1.2, -0.75);
	glVertex3f(1.2, -1.2, -0.75);

	glColor3f(0.8, 0.7, 0.8);

	glVertex3f(1.2, -1.2, -0.75);
	glVertex3f(0.75, -0.75, 0.75);
	glVertex3f(-0.75, -0.75, 0.75);

	//glPopMatrix();
	glEnd();

	// Draw the cube
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(-0.3, -0.8, 0.0);
	if (mode == CUBE_MODE)
		angle_cube += 0.05f;
	glRotated(angle_cube, 1.0f, 1.0f, 0.0f);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCube(0.25);
	glPopMatrix();

	// Draw the sphere
	//glLoadIdentity();
	glColor3f(0.0, 0.8, 1.0);
	glPushMatrix();
	glTranslated(0, 0, 0.0);
	glRotated(45.0f, 1.0f, 1.0f, 0.0f);
	if (mode == SPHERE_MODE) {
		if (size_sphere >= 0.3) {
			grow_sphere = -0.0001;
		}
		else if (size_sphere <= 0.1) {
			grow_sphere = 0.0001;
		}
		size_sphere += grow_sphere;
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glutSolidSphere(size_sphere, 50, 50);
	glPopMatrix();

	// Draw the cone
	//glLoadIdentity();
	glColor3f(0.0, 1.0, 1);
	glPushMatrix();

	glTranslated(-0.6, -0.8, 0.0);
	glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
	if (mode == CONE_MODE) {
		if (high_cone >= 0.55)
			grow_cone = -0.0005;
		else if (high_cone <= 0.1)
			grow_cone = 0.0005;
		high_cone += grow_cone;
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCone(0.2, high_cone, 20, 20);
	glPopMatrix();

	// Draw the teapot
	//glLoadIdentity();
	glColor3f(1.0, 1.0, .5);
	glPushMatrix();

	glTranslated(0.6, -0.8, 0.0);
	if (mode == TEAPOT_MODE)
		angle_teapot += 0.1f;
	glRotated(angle_teapot, 0.0f, 0.0f, 0.0f);
	glRotated(angle_teapot, angle_teapot, 0.0f, 0.0f);
	glRotated(angle_teapot, 0.0f, angle_teapot, 0.0f);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glutSolidTeapot(0.2);
	glPopMatrix();


	// Draw the torus
	//glLoadIdentity();
	glColor3f(0.0, 1.0, .8);
	glPushMatrix();

	glTranslated(-0.0, -0.0, 0.0);
	if (mode == THORUS_MODE) {
		if (inner_thorus >= 0.2) {
			grow_thorus = -0.0002;
		}
		else if (inner_thorus <= 0.025) {
			grow_thorus = 0.0001;
		}
		inner_thorus += grow_thorus;
		outer_thorus -= grow_thorus;
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidTorus(inner_thorus, outer_thorus, 50, 50);
	glPopMatrix();


	glEnd();

	glFlush();
	glutSwapBuffers();

	glutPostRedisplay();
}


void reshape(int w, int h) // Resize the GL Window. w=width, h=height
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-FRUSTDIM, FRUSTDIM, -FRUSTDIM, FRUSTDIM, 320., 640.);

}

void keyboard(unsigned char key, int x, int y) // Handle the keyboard events here
{
	switch (key)
	{
	case'\033':
		exit(0);
		break;
	case'0':
		mode = IMMOBILE_MODE;
		break;
	case'1':
		mode = THORUS_MODE;
		break;
	case'2':
		mode = TEAPOT_MODE;
		break;

	case'3':
		mode = SPHERE_MODE;
		break;
	case'4':
		mode = CONE_MODE;
		break;
	case'5':
		mode = CUBE_MODE;
		break;
	case'q':
		mode = IMMOBILE_MODE;
		break;
	case'r':
		mode = IMMOBILE_MODE;
		initObjectsParameters();
		break;
	case'l':
		if (light_mode == NORMAL_LIGHT)
			light_mode = SPOT_LIGHT;
		else
			light_mode = NORMAL_LIGHT;
		break;
	}
}


int main(int argc, char** argv)
{

	mode = IMMOBILE_MODE;
	light_mode = SPOT_LIGHT;

	initObjectsParameters();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D scene");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}