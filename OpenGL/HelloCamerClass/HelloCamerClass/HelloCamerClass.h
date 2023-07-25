#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloCamerClass.h"
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//类QOpenGLFunctions_x_x_Core是对OpenGL某个版本的包装器,这样就可以使用原版函数
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTime>
#include <QtMath> 
#include <QDebug>
#include <QVector4D>
#include <QOpenGLTexture>
#include <QKeyEvent>
#include "shader.h"
#include "camera.h"
class HelloCamerClass : public QOpenGLWidget
{
    Q_OBJECT

public:
    HelloCamerClass(QWidget *parent = Q_NULLPTR);

	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();

	void keyPressEvent(QKeyEvent *event);   //键盘按下事件
	void keyReleaseEvent(QKeyEvent *event);  //键盘释放事件
	void mouseMoveEvent(QMouseEvent *event);//鼠标事件
	void wheelEvent(QWheelEvent *event);    //滚轮事件
	void mousePressEvent(QMouseEvent *event);  //鼠标按下事件
	void mouseReleaseEvent(QMouseEvent *event); //鼠标释放事件

private:
    Ui::HelloCamerClassClass ui;
	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBOPostion, VBOColor, VBOTexturePostion;
	//	GLuint EBO;
	QOpenGLTexture *texture1;//新添项
	QOpenGLTexture *texture2;//新添项

	Shader *ourShader;
	Camera *camera;

	QTime time = QTime::currentTime();
};
