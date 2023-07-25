#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloCamerClass.h"
#include <QOpenGLWidget>//QT
#include <QOpenGLFunctions_3_3_Core>//��QOpenGLFunctions_x_x_Core�Ƕ�OpenGLĳ���汾�İ�װ��,�����Ϳ���ʹ��ԭ�溯��
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

	void keyPressEvent(QKeyEvent *event);   //���̰����¼�
	void keyReleaseEvent(QKeyEvent *event);  //�����ͷ��¼�
	void mouseMoveEvent(QMouseEvent *event);//����¼�
	void wheelEvent(QWheelEvent *event);    //�����¼�
	void mousePressEvent(QMouseEvent *event);  //��갴���¼�
	void mouseReleaseEvent(QMouseEvent *event); //����ͷ��¼�

private:
    Ui::HelloCamerClassClass ui;
	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBOPostion, VBOColor, VBOTexturePostion;
	//	GLuint EBO;
	QOpenGLTexture *texture1;//������
	QOpenGLTexture *texture2;//������

	Shader *ourShader;
	Camera *camera;

	QTime time = QTime::currentTime();
};
