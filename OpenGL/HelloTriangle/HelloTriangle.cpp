#include "HelloTriangle.h"

HelloTriangle::HelloTriangle(QWidget *parent)
    : QOpenGLWidget(parent)
{
    //ui.setupUi(this);
}



void HelloTriangle::initializeGL() {

	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();

	GLfloat vertices[] = {
			-0.5f, -0.5f, 0.0f,  // left  
			 0.5f, -0.5f, 0.0f, // right  
			 0.0f,  0.5f, 0.0f  // top   
	};

	core->glGenVertexArrays(1, &VAO);
	core->glGenBuffers(1, &VBO);

	core->glBindVertexArray(VAO);

	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

	core->glEnableVertexAttribArray(0);

	core->glBindVertexArray(0);
	core->glBindBuffer(GL_ARRAY_BUFFER, 0);

	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	vertexShader.compileSourceFile("shader/triangle.vert");

	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	fragmentShader.compileSourceFile("shader/triangle.frag");


	shaderProgram.addShader(&vertexShader);
	shaderProgram.addShader(&fragmentShader);

	shaderProgram.link();
}

void HelloTriangle::resizeGL(int w, int h) {}

void HelloTriangle::paintGL() {


	core->glClearColor(0.6f, 0.8f, 0.6f, 1.0f);
	core->glClear(GL_COLOR_BUFFER_BIT);

	shaderProgram.bind();
	core->glBindVertexArray(VAO);

	core->glDrawArrays(GL_TRIANGLES, 0, 3);

	update();
}
