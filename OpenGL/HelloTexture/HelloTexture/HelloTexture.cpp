#include "HelloTexture.h"

HelloTexture::HelloTexture(QWidget *parent)
	: QOpenGLWidget(parent) {
	//ui.setupUi(this);
}

void HelloTexture::initializeGL() {
	//着色器部分
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();
	ourShader = new Shader("shader/vertexshadersource.vert", "shader/fragmentshadersource.frag");

	//VAO，VBO数据部分
	GLfloat verticesPostion[] = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	GLfloat verticesColor[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f
	};

	GLfloat verticesTexturePostion[] = {
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	GLuint indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	core->glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
	core->glGenBuffers(1, &VBOPostion);
	core->glGenBuffers(1, &VBOColor);
	core->glGenBuffers(1, &VBOTexturePostion);
	core->glGenBuffers(1, &EBO);


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
	core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	core->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	core->glBindVertexArray(0);
	//纹理




	//第一张纹理
	texture1 = new QOpenGLTexture(QImage("Texture.bmp").mirrored(), QOpenGLTexture::GenerateMipMaps); //直接生成绑定一个2d纹理, 并生成多级纹理MipMaps
	texture1->setWrapMode(QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture1->setMinificationFilter(QOpenGLTexture::Nearest);   //等价于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture1->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	//第二张纹理
	texture2 = new QOpenGLTexture(QImage("face.bmp").mirrored(), QOpenGLTexture::GenerateMipMaps); //直接生成绑定一个2d纹理, 并生成多级纹理MipMaps
	texture2->setWrapMode(QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture2->setMinificationFilter(QOpenGLTexture::Nearest);   //等价于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	texture2->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	ourShader->use();
	ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture1"), 0);
	ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture2"), 1);





	core->glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void HelloTexture::resizeGL(int w, int h) {}

void HelloTexture::paintGL() {
	core->glClear(GL_COLOR_BUFFER_BIT);

	core->glActiveTexture(GL_TEXTURE0);
	texture2->bind();
	core->glActiveTexture(GL_TEXTURE1);
	texture1->bind();

	ourShader->use();
	core->glBindVertexArray(VAO);
	//core->glDrawArrays(GL_TRIANGLES, 0, 3);
	core->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	update();
}
