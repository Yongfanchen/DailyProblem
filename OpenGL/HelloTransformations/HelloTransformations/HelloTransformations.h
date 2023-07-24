#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloTransformations.h"
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//类QOpenGLFunctions_x_x_Core是对OpenGL某个版本的包装器,这样就可以使用原版函数
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTime>
#include <QtMath> 
#include <QDebug>
#include <QVector4D>
#include "shader.h"

#include <QOpenGLTexture>
class HelloTransformations : public QOpenGLWidget
{
    Q_OBJECT

public:
    HelloTransformations(QWidget *parent = Q_NULLPTR);
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
private:
    //Ui::HelloTransformationsClass ui;

public:
	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBOPostion, VBOColor, VBOTexturePostion;
	GLuint EBO;
	QOpenGLTexture *texture1;//新添项
	QOpenGLTexture *texture2;//新添项

	Shader *ourShader;
};
