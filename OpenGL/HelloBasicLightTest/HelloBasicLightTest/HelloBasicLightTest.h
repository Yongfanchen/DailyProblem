#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloBasicLightTest.h"
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
class HelloBasicLightTest : public QOpenGLWidget
{
    Q_OBJECT

public:
    HelloBasicLightTest(QWidget *parent = Q_NULLPTR);

public:
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

	QOpenGLFunctions_3_3_Core *core;
	GLuint VAO;
	GLuint VBOPostion, VBOColor, VBOTexturePostion, VBONormals;
	//	GLuint EBO;
	QOpenGLTexture *texture1;//������
	QOpenGLTexture *texture2;//������

	Shader *CubeShader;
	Shader *LightShader;
	Camera *camera;

	QVector3D objectColor = QVector3D(0.53f, 0.32f, 0.31f);//����ı�������
	QVector3D lightColor = QVector3D(1.0f, 1.0f, 1.0f);//�����ɫ
};
