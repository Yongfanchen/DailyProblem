#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloShaderClassBySelf.h"
//QT
#include <QOpenGLWidget>
//类QOpenGLFunctions_x_x_Core是对OpenGL某个版本的包装器,这样就可以使用原版函数
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTime>
#include "shader.h"
class HelloShaderClassBySelf : public QOpenGLWidget
{
    Q_OBJECT

public:

    HelloShaderClassBySelf(QWidget *parent = Q_NULLPTR);
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();

private:
	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBO; GLuint VBOColor;
	QOpenGLShaderProgram shaderProgram;
	Shader *ourShader;
};
