#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloShader.h"
#include <QtWidgets/QWidget>
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//��QOpenGLFunctions_x_x_Core�Ƕ�OpenGLĳ���汾�İ�װ��,�����Ϳ���ʹ��ԭ�溯��
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
