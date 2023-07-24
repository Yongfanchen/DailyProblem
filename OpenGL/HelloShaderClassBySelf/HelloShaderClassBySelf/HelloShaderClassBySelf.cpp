#include "HelloShaderClassBySelf.h"

HelloShaderClassBySelf::HelloShaderClassBySelf(QWidget *parent)
	: QOpenGLWidget(parent) {}

void HelloShaderClassBySelf::initializeGL() {
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();//一个包装类
	ourShader = new Shader("shader/triangle.vert", "shader/triangle.frag");

	//我们先先准备好数据，VAO，VBO数据部分。注意必须在-1~+1之间，如果不在范围内，就不会在视口出现

	GLfloat verticesPostion[] = {
			-0.5f, -0.5f, 0.0f,  // left  
			 0.5f, -0.5f, 0.0f, // right  
			 0.0f,  0.5f, 0.0f  // top   
	};

	GLfloat verticesColor[] = {
			1.0f, 0.0f, 0.0f,  // left  
			0.0f, 1.0f, 0.0f, // right  
			0.0f, 0.0f, 1.0f  // top   
	};
	GLfloat verticesColor2[] = {
			0.0f, 1.0f, 0.4f,  // left  
			0.0f, 1.0f, 0.0f, // right  
			0.0f, 0.0f, 1.0f  // top   
	};


	//创建一个VAO，并且绑定至缓冲
	core->glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
	core->glGenBuffers(1, &VBO);//第一个参数是要生成的缓冲对象的数量，第二个是要输入用来存储缓冲对象名称的数组
	core->glGenBuffers(1, &VBOColor);

	//VAO绑定
	core->glBindVertexArray(VAO);
	//所有跟GL_ARRAY_BUFFER有关系的操作状态，它都会记录下来				 
									 //我们用VBO去管理我们内存中的数据，尽量一次性将大量数据传给GPU，因为CPU-->GPU是很慢的
	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定缓冲对象到OpenGL状态机上。
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPostion), verticesPostion, GL_STATIC_DRAW);//把当前绑定在某种类型的缓冲，所指向的内存对象从传输到GPU的缓冲区
	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	core->glBindBuffer(GL_ARRAY_BUFFER, VBOColor);//绑定缓冲对象到OpenGL状态机上。
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColor2), verticesColor2, GL_STATIC_DRAW);//把当前绑定在某种类型的缓冲，所指向的内存对象从传输到GPU的缓冲区
	core->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

	core->glEnableVertexAttribArray(0);//以顶点属性位置值作为参数，启用顶点属性。让着色器能够访问这块数据
	core->glEnableVertexAttribArray(1);//以顶点属性位置值作为参数，启用顶点属性。让着色器能够访问这块数据


	//绑定空缓冲区,作为结尾
	core->glBindVertexArray(0);
	core->glBindBuffer(GL_ARRAY_BUFFER, 0);//注意好顺序

	//1.location用来跟着色器对应的，一半大小为16个
	//2.顶点属性的大小
	//3.
	//4.是否希望数据被标准化
	//5.步长

	//1.着色器程序是运行在显卡上的程序，
	//2.glsl高级着色语言，C语言的简化版
	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	vertexShader.compileSourceFile("shader/triangle.vert");
	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	fragmentShader.compileSourceFile("shader/triangle.frag");
	//我们先生成着色器程序
	shaderProgram.addShader(&vertexShader);
	shaderProgram.addShader(&fragmentShader);
	shaderProgram.link();
}

void HelloShaderClassBySelf::resizeGL(int w, int h) {}

void HelloShaderClassBySelf::paintGL() {

	core->glClearColor(0.6f, 0.3f, 0.8f, 1.0f);//设置清除的颜色
	core->glClear(GL_COLOR_BUFFER_BIT);

	ourShader->use();
	QTime time(QTime::currentTime());
	float timeValue = time.msec();
	float TimeColorChange = timeValue / 1000.0;
	ourShader->setFloat("TimeColorChange", TimeColorChange);
	core->glBindVertexArray(VAO);
	core->glDrawArrays(GL_TRIANGLES, 0, 3);

	update();
}
