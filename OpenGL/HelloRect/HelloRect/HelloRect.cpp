#include "HelloRect.h"

HelloRect::HelloRect(QWidget *parent)
	: QOpenGLWidget(parent) {
	//ui.setupUi(this);
}
GLuint indices[] = { // 注意索引从0开始! 
	0, 1, 3, // 第一个三角形
	1, 3, 2  // 第二个三角形
};
void HelloRect::initializeGL() {
	//0.数据
	GLfloat vertices[] = {
	0.5f, 0.5f, 0.0f,   // 右上角
	0.5f, -0.5f, 0.0f,  // 右下角
	-0.5f, -0.5f, 0.0f, // 左下角
	-0.5f, 0.5f, 0.0f   // 左上角
	};

	GLuint indices[] = { // 注意索引从0开始! 
	0, 1, 3, // 第一个三角形
	1, 3, 2  // 第二个三角形
	};
	//1.初始化QT封装的OpenGL类
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();//一个包装类


	//2.利用VAO和VBO将数据从内存送到显卡缓存。
		//2.1生成VAO、VBO、EBO
	core->glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
	core->glGenBuffers(1, &VBO);//第一个参数是要生成的缓冲对象的数量，第二个是要输入用来存储缓冲对象名称的数组
	core->glGenBuffers(1, &EBO);
	//2.2绑定VAO，让VAO记忆，相关的数据的绑定设置状态。
	core->glBindVertexArray(VAO);//所有跟物体绘制有关系的状态，它都会记忆
		//2.3绑定VBO、EBO传送数据，确定属性
	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定缓冲对象到OpenGL状态机上。
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//把当前绑定在某种类型的缓冲，所指向的内存对象从传输到GPU的缓冲区
	core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//绑定缓冲对象到OpenGL状态机上。
	core->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//把当前绑定在某种类型的缓冲，所指向的内存对象从传输到GPU的缓冲区

	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	core->glEnableVertexAttribArray(0);//以顶点属性位置值作为参数，启用顶点属性。让着色器能够访问这块数据
	core->glPolygonMode(GL_BACK, GL_LINE);
	core->glBindVertexArray(0);//VAO记忆结束
		//2.4 解绑，注意解绑语句不能放到VAO的区间呢，否则VAO就记忆了解绑，就没法paint了
	core->glBindBuffer(GL_ARRAY_BUFFER, 0);
	core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	//生成着色器
	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	vertexShader.compileSourceFile("shader/rect.vert");
	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	fragmentShader.compileSourceFile("shader/rect.frag");

	//我们先生成着色器程序
	shaderProgram.addShader(&vertexShader);
	shaderProgram.addShader(&fragmentShader);
	shaderProgram.link();

}

void HelloRect::resizeGL(int w, int h) {}

void HelloRect::paintGL() {
	core->glClearColor(0.6f, 0.8f, 0.6f, 1.0f);
	core->glClear(GL_COLOR_BUFFER_BIT);
	shaderProgram.bind();
	core->glBindVertexArray(VAO);

	core->glDrawArrays(GL_TRIANGLES, 0, 3);

	//core->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	core->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//如果你绑定了EBO，偏移量
	//不绑定EBO，
}
