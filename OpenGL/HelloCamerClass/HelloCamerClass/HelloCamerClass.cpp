#include "HelloCamerClass.h"

HelloCamerClass::HelloCamerClass(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
}

void HelloCamerClass::initializeGL()
{//着色器部分
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();
	ourShader = new Shader("shader/vertexshadersource.vert", "shader/fragmentshadersource.frag");
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

	core->glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
	core->glGenBuffers(1, &VBOPostion);
	core->glGenBuffers(1, &VBOColor);
	core->glGenBuffers(1, &VBOTexturePostion);
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


	ourShader->use();
	ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture1"), 0);
	ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture2"), 1);

	core->glClearColor(0.3f, 0.2f, 0.3f, 1.0f);
}

void HelloCamerClass::resizeGL(int w, int h) {}

void HelloCamerClass::paintGL()
{
	core->glEnable(GL_DEPTH_TEST);

	core->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	core->glActiveTexture(GL_TEXTURE0);
	texture2->bind();
	core->glActiveTexture(GL_TEXTURE1);
	texture1->bind();

	ourShader->use();

	//QMatrix4x4 modelmat;//model矩阵,负责物体坐标->世界坐标
	//modelmat.rotate(QTime::currentTime().msecsSinceStartOfDay() / 500.0, QVector3D(0.4f, 0.3f, 0.7f));
	//ourShader->setMat4("model", modelmat);

	//QMatrix4x4 viewmat;//用于给摄像机的观察矩阵，可以看作是给全部绘制物体的统一model2矩阵
	//viewmat = camera->getViewMat();
	//ourShader->setMat4("view", viewmat);

	//QMatrix4x4 projectionmat;//三维转二维的透视投影矩阵，近大远小
	//projectionmat.perspective(0.0, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
	//ourShader->setMat4("projection", projectionmat);

	camera->DealKeyboardInputs();//主动调用，处理存储的所有键盘事件，实现捕获多键
	ourShader->setMat4("view", camera->getViewMat());
	QMatrix4x4 projection;
	projection.perspective(camera->zoom, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.f);
	ourShader->setMat4("projection", projection);


	core->glBindVertexArray(VAO);
	core->glDrawArrays(GL_TRIANGLES, 0, 36);
	update();
}

void HelloCamerClass::keyPressEvent(QKeyEvent * event)
{
	GLuint key = event->key();
	if (key >= 0 && key < 1024)
		camera->keys[key] = GL_TRUE;
}

void HelloCamerClass::keyReleaseEvent(QKeyEvent * event)
{
	GLuint key = event->key();
	if (key >= 0 && key < 1024)
		camera->keys[key] = GL_FALSE;
}

void HelloCamerClass::mouseMoveEvent(QMouseEvent * event)
{
	//float Xoffset = event->x() - rect().center().x();
	//float Yoffset = rect().center().y() - event->y(); // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的

	//if (camera->isLeftMousePress) {
	//	camera->DealMouseMovement(Xoffset, Yoffset);
	//}
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

void HelloCamerClass::wheelEvent(QWheelEvent * event)
{
	//QPoint offset = event->angleDelta();
	//camera->DealMouseScroll(offset.y() / 20.0f);
	QPoint offset = event->angleDelta();
	camera->DealMouseScroll(offset.y() / 20.0f);
}

void HelloCamerClass::mousePressEvent(QMouseEvent * event)
{
	//	if (event->button() == Qt::LeftButton) { //注意是button（）不是buttons（）；
//		camera->isLeftMousePress = GL_TRUE;
//	}
	if (event->button() == Qt::LeftButton)
	{ //注意是button（）不是buttons（）；
		camera->isLeftMousePress = GL_TRUE;
	}
}

void HelloCamerClass::mouseReleaseEvent(QMouseEvent * event)
{
	//if (event->button() == Qt::LeftButton) { //注意是button（）不是buttons（）；
	//	camera->isLeftMousePress = GL_FALSE;
	//	camera->isFirstMouse = GL_TRUE;
	//}
	if (event->button() == Qt::LeftButton)
	{ //注意是button（）不是buttons（）；
		camera->isLeftMousePress = GL_FALSE;
		camera->isFirstMouse = GL_TRUE;
	}
}
