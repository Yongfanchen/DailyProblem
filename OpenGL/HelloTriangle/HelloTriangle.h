#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloTriangle.h"
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//��QOpenGLFunctions_x_x_Core�Ƕ�OpenGLĳ���汾�İ�װ��,�����Ϳ���ʹ��ԭ�溯��
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>


class HelloTriangle : public QOpenGLWidget
{
    Q_OBJECT

public:
    HelloTriangle(QWidget *parent = Q_NULLPTR);
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
private:
    Ui::HelloTriangleClass ui;
	QOpenGLFunctions_3_3_Core *core; 
	GLuint VAO; GLuint VBO;
	QOpenGLShaderProgram shaderProgram;
};
