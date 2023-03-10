#include<stdio.h>
#include <glew.h>
#include <GL/glut.h>
#include "math_3d.h"
GLuint VBO;//??????????, ???????? ????????? ?? ????? ??????
static void RenderSceneCB() {//??????? ?????????
	glClear(GL_COLOR_BUFFER_BIT);//??????? ?????? ?????
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//???????? VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//?????????? ?????? ???????
	glEnableVertexAttribArray(0);//????????? ???????? ???????
	glDrawArrays(GL_POINTS, 0, 1);//??????? ?????????
	glDisableVertexAttribArray(0);//?????????? ???????? ???????
	glutSwapBuffers();//???????, ???????? ??????? ????? ? ????? ????? ???????
}
static void CreateVertexBuffer() {
	Vector3f Vertices[1];//???????? ??????? ?? 1 ??????? 
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);//??????? ????????? ????? 
	glGenBuffers(1, &VBO);//????????? ???????
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//???????? VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);//?????????? ?????? ???????
}
int main(int argc, char** argv) {
	glutInit(&argc, argv); //????????????? GLUT-??????????
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//????????? ?????? ??????????? ????
	glutInitWindowSize(1024, 768);//????????? ???????? ????
	glutInitWindowPosition(100, 100);//????????? ?????????????? ????
	glutCreateWindow("Window 01-02");//???????? ????
	GLenum res = glewInit();//???????? ?? ?????????????? glew
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//????????? ????? ???????????? ????
	CreateVertexBuffer();//???????? ?????????? ??????
	glutDisplayFunc(RenderSceneCB);//????????? ??????? ????????? ? ????
	glutMainLoop();//??????? ????????
	glClear(GL_COLOR_BUFFER_BIT);//??????? ?????? ?????
	glutSwapBuffers();//???????, ???????? ??????? ????? ? ????? ????? ???????
	return 0;
}
