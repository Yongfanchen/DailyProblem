#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QKeyEvent>
#include <QOpenGLShader>//Ϊ��glfloat ��Щ�����������������ͷ�ļ�
#include <QDebug>


enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};


class Camera {
public:
	Camera(QVector3D position = QVector3D(0.0f, 0.0f, 0.0f), int width = 300,int height=300)
		 {

		this->cameraPos = position;
		this->lastX = width / 2;
		this->lastY = height / 2;

		this->UpdateCameraLookatMatVectors();

	}

public:
	QMatrix4x4 getViewMat(); //����view������

	void DealMouseMovement(GLfloat Xoffset, GLfloat Yoffset); //�������������ľ���仯����,offsetƫ����
	void DealMouseScroll(GLfloat Yoffset);//�������¼�
	void DealKeyboardInputs();//***ÿ����Ⱦ�������ã�����洢�����м����¼���
	void DealKeyInput(CameraMovement direction);//���̴����¼�����������

	void UpdateCameraLookatMatVectors();//�����й�lookat����������


public://��Ա����

	//����й�
	QVector3D cameraPos = QVector3D(0.0f, 0.0f, 0.0f);//���λ��
	QVector3D cameraTarget = QVector3D(0.0, 0.0f, 1.0f);//����Եķ���������һ������
	QVector3D cameraDirection = QVector3D(cameraPos - cameraTarget);//�������������������z�ĸ����᷽��
	QVector3D cameraUp = QVector3D(0.0f, 1.0f, 0.0f);//����ָ��y��������
	QVector3D cameraRight = QVector3D::crossProduct(cameraDirection, cameraUp);//����ԭ��Ҳ������x�������򣬵�����Ϊ�������Ը���һЩ��������в��

																			   
	//����й�
	GLfloat sensitivity = 0.01f;     //���������
	GLfloat movementSpeed = 0.1f;     //�����ƶ��ٶ�
	GLfloat zoom = 45.0f;//ͶӰ������Ǹ��Ƕ�
		//ŷ����,ˮƽ���ƶ�Ӱ��ƫ���ǣ���ֱ���ƶ�Ӱ�츩����
	GLfloat yaw = -90.0f;             //ƫ����
	GLfloat pitch = 0.0f;           //���ӽ�
			//cameraDirection.setX(cos(yaw)*cos(pitch));
			//cameraDirection.setY(sin(pitch));
			//cameraDirection.setZ(sin(yaw)*cos(pitch));
			//����Ƿ���
	GLboolean isFirstMouse = GL_TRUE;
	GLboolean isLeftMousePress = GL_FALSE;

	//��Ļ����,��һ�ε�λ��
	GLint lastX;
	GLint lastY;


	//���̶����������
	GLboolean keys[1024] = {0};


};
#endif // CAMERA_H