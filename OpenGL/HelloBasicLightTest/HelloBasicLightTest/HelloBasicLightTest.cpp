#include "HelloBasicLightTest.h"

HelloBasicLightTest::HelloBasicLightTest(QWidget *parent)
    : QOpenGLWidget(parent)
{
	QVector<QVector3D> a;
	a.append(QVector3D());
	a.push_back(QVector3D());
}

void HelloBasicLightTest::initializeGL()
{
	//��ɫ������
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();
	CubeShader = new Shader("shader/cubeObject.vert", "shader/cubeObject.frag");
	LightShader = new Shader("shader/lightObject.vert", "shader/lightObject.frag");
	//���Ի����
	camera = new Camera(QVector3D(0.0f, 0.0f, 0.0f), this->width(), this->height());

	//VAO��VBO���ݲ���
	GLfloat verticesPostion[] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
	};

	GLfloat verticesColor[] = {
		 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 1.0f,

		 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 1.0f,

		 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 1.0f,

		 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 1.0f,

		 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 1.0f,

		 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		 1.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 1.0f
	};

	GLfloat verticesTexturePostion[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,

		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	GLfloat verticesNormals[] = {
	  0.0f,  0.0f, -1.0f,
	  0.0f,  0.0f, -1.0f,
	  0.0f,  0.0f, -1.0f,
	  0.0f,  0.0f, -1.0f,
	  0.0f,  0.0f, -1.0f,
	  0.0f,  0.0f, -1.0f,

	  0.0f,  0.0f,  1.0f,
	  0.0f,  0.0f,  1.0f,
	  0.0f,  0.0f,  1.0f,
	  0.0f,  0.0f,  1.0f,
	  0.0f,  0.0f,  1.0f,
	  0.0f,  0.0f,  1.0f,

	  -1.0f,  0.0f,  0.0f,
	  -1.0f,  0.0f,  0.0f,
	  -1.0f,  0.0f,  0.0f,
	  -1.0f,  0.0f,  0.0f,
	  -1.0f,  0.0f,  0.0f,
	  -1.0f,  0.0f,  0.0f,

	  1.0f,  0.0f,  0.0f,
	  1.0f,  0.0f,  0.0f,
	  1.0f,  0.0f,  0.0f,
	  1.0f,  0.0f,  0.0f,
	  1.0f,  0.0f,  0.0f,
	  1.0f,  0.0f,  0.0f,

	  0.0f, -1.0f,  0.0f,
	  0.0f, -1.0f,  0.0f,
	  0.0f, -1.0f,  0.0f,
	  0.0f, -1.0f,  0.0f,
	  0.0f, -1.0f,  0.0f,
	  0.0f, -1.0f,  0.0f,

	  0.0f,  1.0f,  0.0f,
	  0.0f,  1.0f,  0.0f,
	  0.0f,  1.0f,  0.0f,
	  0.0f,  1.0f,  0.0f,
	  0.0f,  1.0f,  0.0f,
	  0.0f,  1.0f,  0.0f
	};

	core->glGenVertexArrays(1, &VAO);//������������һ��Ϊ��Ҫ�����Ļ����������ڶ���Ϊ���ڴ洢��һID����ID��GLuint����������ĵ�ַ
	core->glGenBuffers(1, &VBOPostion);
	core->glGenBuffers(1, &VBOColor);
	core->glGenBuffers(1, &VBOTexturePostion);
	core->glGenBuffers(1, &VBONormals);

	core->glBindVertexArray(VAO);

	core->glBindBuffer(GL_ARRAY_BUFFER, VBOPostion);
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPostion), verticesPostion, GL_STATIC_DRAW);
	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	core->glEnableVertexAttribArray(0);

	// color attribute
	core->glBindBuffer(GL_ARRAY_BUFFER, VBOColor);
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColor), verticesColor, GL_STATIC_DRAW);
	core->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	core->glEnableVertexAttribArray(1);

	// texture coord attribute
	core->glBindBuffer(GL_ARRAY_BUFFER, VBOTexturePostion);
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTexturePostion), verticesTexturePostion, GL_STATIC_DRAW);
	core->glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	core->glEnableVertexAttribArray(2);

	// normals
	core->glBindBuffer(GL_ARRAY_BUFFER, VBONormals);
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesNormals), verticesNormals, GL_STATIC_DRAW);
	core->glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	core->glEnableVertexAttribArray(3);


	core->glBindVertexArray(0);
	//����

	//��һ������
	texture1 = new QOpenGLTexture(QImage("Texture.jpg").mirrored(), QOpenGLTexture::GenerateMipMaps); //ֱ�����ɰ�һ��2d����, �����ɶ༶����MipMaps
	texture1->setWrapMode(QOpenGLTexture::Repeat);// ����glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture1->setMinificationFilter(QOpenGLTexture::Nearest);   //�ȼ���glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture1->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	//�ڶ�������
	texture2 = new QOpenGLTexture(QImage("Texture2.jpg").mirrored(), QOpenGLTexture::GenerateMipMaps); //ֱ�����ɰ�һ��2d����, �����ɶ༶����MipMaps
	texture2->setWrapMode(QOpenGLTexture::Repeat);// ����glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture2->setMinificationFilter(QOpenGLTexture::Nearest);   //�ȼ���glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture2->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	CubeShader->use();
	CubeShader->shaderProgram.setUniformValue(CubeShader->shaderProgram.uniformLocation("texture1"), 0);
	CubeShader->shaderProgram.setUniformValue(CubeShader->shaderProgram.uniformLocation("texture2"), 1);

	core->glClearColor(0.3f, 0.2f, 0.3f, 1.0f);
}

void HelloBasicLightTest::resizeGL(int w, int h)
{}

void HelloBasicLightTest::paintGL()
{
	core->glEnable(GL_DEPTH_TEST);

	core->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//���ƹ�Դ--------------------------------------------------
	LightShader->use();
	//�������
	camera->DealKeyboardInputs();//�������ã�����洢�����м����¼���ʵ�ֲ�����
	LightShader->setMat4("view", camera->getViewMat());
	QMatrix4x4 projectionLight;
	projectionLight.perspective(camera->zoom, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
	LightShader->setMat4("projection", projectionLight);
	QMatrix4x4 modelLight;
	QVector3D lightPos = QVector3D(0.0f, 0.0f, 0.0f);
	modelLight.scale(0.5);
	modelLight.translate(lightPos);
	//�������ݴ���
	LightShader->setVec3("lightColor", QVector3D(1.0f, 1.0f, 1.0f));
	//��VAO�ģ����л���
	core->glBindVertexArray(VAO);
	core->glDrawArrays(GL_TRIANGLES, 0, 36);

	//��������--------------------------------------------------
	CubeShader->use();
	//�������
	camera->DealKeyboardInputs();//�������ã�����洢�����м����¼���ʵ�ֲ�����
	CubeShader->setMat4("view", camera->getViewMat());
	QMatrix4x4 projection;
	projection.perspective(camera->zoom, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
	CubeShader->setMat4("projection", projection);
	//�������ݴ���
	CubeShader->setVec3("objectColor", this->objectColor);
	CubeShader->setVec3("lightColor", this->lightColor);
	CubeShader->setVec3("lightPos", lightPos);

	core->glBindVertexArray(VAO);
	QMatrix4x4 modelCube;
	modelCube.scale(3.0f);
	modelCube.translate(QVector3D(4.0f, 0.0f, 0.0f));
	modelCube.rotate(30.0f, QVector3D(1.0f, 0.0f, 1.0f));
	LightShader->setMat4("model", modelCube);
	core->glDrawArrays(GL_TRIANGLES, 0, 36);
	modelCube.translate(QVector3D(0.0f, 4.0f, 0.0f));
	LightShader->setMat4("model", modelCube);
	core->glDrawArrays(GL_TRIANGLES, 0, 36);

	update();
}

void HelloBasicLightTest::keyPressEvent(QKeyEvent * event)
{
	GLuint key = event->key();
	if (key >= 0 && key < 1024)
		camera->keys[key] = GL_TRUE;
}

void HelloBasicLightTest::keyReleaseEvent(QKeyEvent * event)
{
	GLuint key = event->key();
	if (key >= 0 && key < 1024)
		camera->keys[key] = GL_FALSE;
}

void HelloBasicLightTest::mouseMoveEvent(QMouseEvent * event)
{
	GLint xpos = event->pos().x();
	GLint ypos = event->pos().y();

	if (camera->isLeftMousePress)
	{
		if (camera->isFirstMouse)
		{
			camera->lastX = xpos;
			camera->lastY = ypos;
			camera->isFirstMouse = GL_FALSE;
		}

		GLint Xoffset = xpos - camera->lastX;
		GLint Yoffset = camera->lastY - ypos; // reversed since y-coordinates go from bottom to top
		camera->lastX = xpos;
		camera->lastY = ypos;
		camera->DealMouseMovement(Xoffset, Yoffset);
	}
}

void HelloBasicLightTest::wheelEvent(QWheelEvent * event)
{
	QPoint offset = event->angleDelta();
	camera->DealMouseScroll(offset.y() / 20.0f);
}

void HelloBasicLightTest::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{ //ע����button��������buttons������
		camera->isLeftMousePress = GL_TRUE;
	}
}

void HelloBasicLightTest::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{ //ע����button��������buttons������
		camera->isLeftMousePress = GL_FALSE;
		camera->isFirstMouse = GL_TRUE;
	}
}
