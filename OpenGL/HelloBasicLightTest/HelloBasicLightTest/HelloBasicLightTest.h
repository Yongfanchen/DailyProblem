#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloBasicLightTest.h"
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
class HelloBasicLightTest : public QOpenGLWidget
{
    Q_OBJECT

public:
    HelloBasicLightTest(QWidget *parent = Q_NULLPTR);

public:
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

	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBOPostion, VBOColor, VBOTexturePostion, VBONormals;
	//	GLuint EBO;
	QOpenGLTexture *texture1;//新添项
	QOpenGLTexture *texture2;//新添项

	Shader *CubeShader;
	Shader *LightShader;
	Camera *camera;

	QVector3D objectColor = QVector3D(0.53f, 0.32f, 0.31f);//物体的本身反射率
	QVector3D lightColor = QVector3D(1.0f, 1.0f, 1.0f);//光的颜色
};
