#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HelloTexture.h"
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//��QOpenGLFunctions_x_x_Core�Ƕ�OpenGLĳ���汾�İ�װ��,�����Ϳ���ʹ��ԭ�溯��
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTime>
#include <QtMath> 
#include <QDebug>
#include <QVector4D>
#include "shader.h"

#include <QOpenGLTexture>
class HelloTexture : public QOpenGLWidget
{
    Q_OBJECT

public:
public:
	HelloTexture(QWidget *parent = Q_NULLPTR);
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
private:
    Ui::HelloTextureClass ui;

	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBOPostion, VBOColor, VBOTexturePostion;
	GLuint EBO;
	QOpenGLTexture *texture1;//������
	QOpenGLTexture *texture2;//������

	Shader *ourShader;
};
