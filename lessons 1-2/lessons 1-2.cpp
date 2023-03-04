#include<stdio.h>
#include <glew.h>
#include <GL/glut.h>
#include "math_3d.h"
GLuint VBO;//переменна€, хран€ща€ указатель на буфер данных
static void RenderSceneCB() {//функци€ рисовани€
	glClear(GL_COLOR_BUFFER_BIT);//очистка буфера кадра
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//прив€зка VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//наполнение буфера данными
	glEnableVertexAttribArray(0);//включение атрибута вершины
	glDrawArrays(GL_POINTS, 0, 1);//функци€ отрисовки
	glDisableVertexAttribArray(0);//отключение атрибута вершины
	glutSwapBuffers();//функци€, мен€юща€ фоновый буфер и буфер кадра местами
}
static void CreateVertexBuffer() {
	Vector3f Vertices[1];//создание массива из 1 вектора 
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);//задание положени€ точки 
	glGenBuffers(1, &VBO);//генераци€ объекта
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//прив€зка VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);//наполнение буфера данными
}
int main(int argc, char** argv) {
	glutInit(&argc, argv); //инициализаци€ GLUT-библиотеки
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//установка режима отображени€ окна
	glutInitWindowSize(1024, 768);//установка размеров окна
	glutInitWindowPosition(100, 100);//установка местоположени€ окна
	glutCreateWindow("Window 01-02");//создание окна
	GLenum res = glewInit();//проверка на иниициализацию glew
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//установка цвета создаваемого окна
	CreateVertexBuffer();//создание вершинного буфера
	glutDisplayFunc(RenderSceneCB);//установка функции рисовани€ в окне
	glutMainLoop();//функци€ ожидани€
	glClear(GL_COLOR_BUFFER_BIT);//очистка буфера кадра
	glutSwapBuffers();//функци€, мен€юща€ фоновый буфер и буфер кадра местами
	return 0;
}
