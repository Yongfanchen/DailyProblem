#include "HelloShader.h"

HelloShader::HelloShader(QWidget *parent)
	: QOpenGLWidget(parent) {


}

void HelloShader::initializeGL() {
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();//一个包装类


//我们先先准备好数据，VAO，VBO数据部分。注意必须在-1~+1之间，如果不在范围内，就不会在视口出现
	GLfloat vertices[] = {
			-0.5f, -0.5f, 0.0f,  // left  
			 0.5f, -0.5f, 0.0f, // right  
			 0.0f,  0.5f, 0.0f  // top   
	};


	//创建一个VAO，并且绑定至缓冲
	core->glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
	core->glGenBuffers(1, &VBO);//第一个参数是要生成的缓冲对象的数量，第二个是要输入用来存储缓冲对象名称的数组

	//VAO绑定
	core->glBindVertexArray(VAO);
	//所有跟GL_ARRAY_BUFFER有关系的操作状态，它都会记录下来				 
									 //我们用VBO去管理我们内存中的数据，尽量一次性将大量数据传给GPU，因为CPU-->GPU是很慢的
	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定缓冲对象到OpenGL状态机上。
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//把当前绑定在某种类型的缓冲，所指向的内存对象从传输到GPU的缓冲区

	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	core->glEnableVertexAttribArray(0);//以顶点属性位置值作为参数，启用顶点属性。让着色器能够访问这块数据


	//绑定空缓冲区，这一步其实可以不要



	//1.location用来跟着色器对应的，一半大小为16个
	//2.顶点属性的大小
	//3.
	//4.是否希望数据被标准化
	//5.步长

	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	bool success = vertexShader.compileSourceFile("shader/triangle.vert");
	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	success = fragmentShader.compileSourceFile("shader/triangle.frag");

	//我们先生成着色器程序
	shaderProgram.addShader(&vertexShader);
	shaderProgram.addShader(&fragmentShader);
	success = shaderProgram.link();


	core->glBindBuffer(GL_ARRAY_BUFFER, 0);
	core->glBindVertexArray(0);
}

void HelloShader::resizeGL(int w, int h) {

	core->glViewport(0, 0, w, h);
}

void HelloShader::paintGL() {
	core->glClearColor(qAbs(qSin((float)time.elapsed() / 1000.0)), 0.4f, 0.6f, 1.0f);
	core->glClear(GL_COLOR_BUFFER_BIT);

	qDebug() << qSin((float)time.elapsed()) << endl;

	shaderProgram.bind();

	GLuint location = shaderProgram.uniformLocation("ourColor");
	shaderProgram.setUniformValue(location, QVector4D(0.4, qAbs(qSin((float)time.elapsed() / 1000.0)), 0.8, 1.0));
	core->glBindVertexArray(VAO);

	core->glDrawArrays(GL_TRIANGLES, 0, 3);

	update();
}
