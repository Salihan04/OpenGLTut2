#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"
#include <iostream>

using namespace std;

GLuint VBO;

void renderScene() {

	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void initialiseGlutCallbacks() {

	glutDisplayFunc(renderScene);
}

void createVertexBuffer() {

	Vector3f vertices[1];
	vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Tutorial 02 - Hello Dot");

	initialiseGlutCallbacks();

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(res));

		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	createVertexBuffer();

	glutMainLoop();

	return 0;
}