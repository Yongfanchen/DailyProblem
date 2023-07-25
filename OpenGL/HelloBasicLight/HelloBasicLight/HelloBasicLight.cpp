#include "HelloBasicLight.h"

HelloBasicLight::HelloBasicLight(QWidget *parent)
	: QOpenGLWidget(parent)
{

}

void HelloBasicLight::initializeGL()
{
	//着色器部分
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();
	CubeShader = new Shader("shader/cubeObject.vert", "shader/cubeObject.frag");
	LightShader = new Shader("shader/lightObject.vert", "shader/lightObject.frag");
	//初试化相机
	camera = new Camera(QVector3D(0.0f, 0.0f, 0.0f), this->width(), this->height());

	//VAO，VBO数据部分
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


	core->glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
	core->glGenBuffers(1, &VBOPostion);
	core->glGenBuffers(1, &VBOColor);
	core->glGenBuffers(1, &VBOTexturePostion);
	core->glGenBuffers(1, &VBONormals);
	//core->glGenBuffers(1, &EBO);


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
	//EBO
	//core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//core->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	core->glBindVertexArray(0);
	//纹理




	//第一张纹理
	texture1 = new QOpenGLTexture(QImage("Texture.jpg").mirrored(), QOpenGLTexture::GenerateMipMaps); //直接生成绑定一个2d纹理, 并生成多级纹理MipMaps
	texture1->setWrapMode(QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture1->setMinificationFilter(QOpenGLTexture::Nearest);   //等价于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture1->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	//第二张纹理
	texture2 = new QOpenGLTexture(QImage("Texture2.jpg").mirrored(), QOpenGLTexture::GenerateMipMaps); //直接生成绑定一个2d纹理, 并生成多级纹理MipMaps
	texture2->setWrapMode(QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture2->setMinificationFilter(QOpenGLTexture::Nearest);   //等价于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture2->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	CubeShader->use();
	CubeShader->shaderProgram.setUniformValue(CubeShader->shaderProgram.uniformLocation("texture1"), 0);
	CubeShader->shaderProgram.setUniformValue(CubeShader->shaderProgram.uniformLocation("texture2"), 1);






	core->glClearColor(0.3f, 0.2f, 0.3f, 1.0f);
}

void HelloBasicLight::resizeGL(int w, int h)
{}

void HelloBasicLight::paintGL()
{
	float time = QTime::currentTime().msecsSinceStartOfDay() / 1000.0;

	core->glEnable(GL_DEPTH_TEST);

	core->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//绘制光源--------------------------------------------------
	LightShader->use();
	//相机调用
	camera->DealKeyboardInputs();//主动调用，处理存储的所有键盘事件，实现捕获多键
	LightShader->setMat4("view", camera->getViewMat());
	QMatrix4x4 projectionLight;
	projectionLight.perspective(camera->zoom, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
	LightShader->setMat4("projection", projectionLight);
	QMatrix4x4 modelLight;
	QVector3D lightPos = QVector3D(0.0f, 0.0f, 0.0f);
	modelLight.scale(0.5);
	modelLight.rotate(time*-40.0f, QVector3D(0.0f, 1.0f, 0.0f));
	modelLight.translate(lightPos);

	//光照数据传入
	LightShader->setMat4("model", modelLight);
	LightShader->setVec3("lightColor", QVector3D(1.0f, 1.0f, 1.0f));
	//绑定VAO的，进行绘制
	core->glBindVertexArray(VAO);
	core->glDrawArrays(GL_TRIANGLES, 0, 36);



	//绘制物体--------------------------------------------------
	CubeShader->use();
	//相机调用
	camera->DealKeyboardInputs();//主动调用，处理存储的所有键盘事件，实现捕获多键
	CubeShader->setMat4("view", camera->getViewMat());
	QMatrix4x4 projection;
	projection.perspective(camera->zoom, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
	CubeShader->setMat4("projection", projection);
	//光照数据传入
	CubeShader->setVec3("objectColor", this->objectColor);
	CubeShader->setVec3("lightColor", this->lightColor);
	CubeShader->setVec3("lightPos", lightPos);
	CubeShader->setVec3("viewPos", camera->cameraPos);

	core->glBindVertexArray(VAO);
	QMatrix4x4 modelCube;
	modelCube.scale(8.0f);
	modelCube.translate(QVector3D(1.0f, 0.0f, 0.0f));
	modelCube.rotate(time*40.0f, QVector3D(0.0f, 1.0f, 0.0f));
	LightShader->setMat4("model", modelCube);
	core->glDrawArrays(GL_TRIANGLES, 0, 36);
	;



	update();
}

void HelloBasicLight::keyPressEvent(QKeyEvent * event)
{
	GLuint key = event->key();
	if (key >= 0 && key < 1024)
		camera->keys[key] = GL_TRUE;
}

void HelloBasicLight::keyReleaseEvent(QKeyEvent * event)
{
	GLuint key = event->key();
	if (key >= 0 && key < 1024)
		camera->keys[key] = GL_FALSE;
}

void HelloBasicLight::mouseMoveEvent(QMouseEvent * event)
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

void HelloBasicLight::wheelEvent(QWheelEvent * event)
{
	QPoint offset = event->angleDelta();
	camera->DealMouseScroll(offset.y() / 20.0f);
}

void HelloBasicLight::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{ //注意是button（）不是buttons（）；
		camera->isLeftMousePress = GL_TRUE;
	}
}

void HelloBasicLight::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{ //注意是button（）不是buttons（）；
		camera->isLeftMousePress = GL_FALSE;
		camera->isFirstMouse = GL_TRUE;
	}
}
