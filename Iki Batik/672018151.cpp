#include <iostream>
#include <glut.h>

GLfloat ctrlpoints[4][3] = {
		{ 150.0, 150.0, 0.0}, { 125.0, 50.0, 0.0}, {75, 25, 0.0}, {.0, .0, 0.0} };

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();

	glLineWidth(2);
	glTranslatef(150.0, 150.0, 0);

	int x, row, column;

	for (column = 0; column < 2; column++) {
		glTranslatef(-300 * column, 300 * column, 0);

		for (row = 0; row < 2; row++) {
			glTranslatef(300 * row, 0, 0);

			
			for (int z = 0; z < 2; z++) {
				glColor3f(1.0, 0.0 + 0.50 * z, 0.0);

				glRotatef(180, 0, 1, 0);
				for (x = 0; x < 4; x++) {

					glRotatef(90, 0, 0, 1);
					glBegin(GL_POLYGON);

					int i;
					for (i = 0; i <= 30; i++)
						glEvalCoord1f((GLfloat)i / 30.0);
					glEnd();
				}
			}
			for (int s = 0; s < 8; s++) {

				glRotatef(90 * s, 0, 0, 1);
				glBegin(GL_POLYGON);
				glColor3ub(0, 200, 200); glVertex2f(-150, 0);
				glColor3ub(0, 200, 200); glVertex2f(-100, 0);
				glColor3ub(0, 200, 200); glVertex2f(-150, 50);
				glEnd();
				glBegin(GL_POLYGON);
				glColor3ub(0, 250, 250); glVertex2f(-150, 0);
				glColor3ub(0, 250, 250); glVertex2f(-100, 0);
				glColor3ub(0, 250, 250); glVertex2f(-150, -50);
				glEnd();
			}
			
		}
	}

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void myinit() {
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glClearColor(.0, .0, .0, .0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600, 600.0, .0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("672018151");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();

	return 0;
}