#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloShader.h"
#include <QtWidgets/QWidget>
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//类QOpenGLFunctions_x_x_Core是对OpenGL某个版本的包装器,这样就可以使用原版函数
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTime>
#include <QtMath> 
#include <QDebug>
#include <QVector4D>
class HelloShader : public QOpenGLWidget
{
    Q_OBJECT

public:
    HelloShader(QWidget *parent = Q_NULLPTR);
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);//
	virtual void paintGL();
private:
    Ui::HelloShaderClass ui;
	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO; GLuint VBO; GLuint EBO;
	QOpenGLShaderProgram shaderProgram;

	QTime time = QTime::currentTime();
};
