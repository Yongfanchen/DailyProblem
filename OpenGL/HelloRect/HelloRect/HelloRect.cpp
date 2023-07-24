#include "HelloRect.h"

HelloRect::HelloRect(QWidget *parent)
	: QOpenGLWidget(parent) {
	//ui.setupUi(this);
}
GLuint indices[] = { // ע��������0��ʼ! 
	0, 1, 3, // ��һ��������
	1, 3, 2  // �ڶ���������
};
void HelloRect::initializeGL() {
	//0.����
	GLfloat vertices[] = {
	0.5f, 0.5f, 0.0f,   // ���Ͻ�
	0.5f, -0.5f, 0.0f,  // ���½�
	-0.5f, -0.5f, 0.0f, // ���½�
	-0.5f, 0.5f, 0.0f   // ���Ͻ�
	};

	GLuint indices[] = { // ע��������0��ʼ! 
	0, 1, 3, // ��һ��������
	1, 3, 2  // �ڶ���������
	};
	//1.��ʼ��QT��װ��OpenGL��
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();//һ����װ��


	//2.����VAO��VBO�����ݴ��ڴ��͵��Կ����档
		//2.1����VAO��VBO��EBO
	core->glGenVertexArrays(1, &VAO);//������������һ��Ϊ��Ҫ�����Ļ����������ڶ���Ϊ���ڴ洢��һID����ID��GLuint����������ĵ�ַ
	core->glGenBuffers(1, &VBO);//��һ��������Ҫ���ɵĻ��������������ڶ�����Ҫ���������洢����������Ƶ�����
	core->glGenBuffers(1, &EBO);
	//2.2��VAO����VAO���䣬��ص����ݵİ�����״̬��
	core->glBindVertexArray(VAO);//���и���������й�ϵ��״̬�����������
		//2.3��VBO��EBO�������ݣ�ȷ������
	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);//�󶨻������OpenGL״̬���ϡ�
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//�ѵ�ǰ����ĳ�����͵Ļ��壬��ָ����ڴ����Ӵ��䵽GPU�Ļ�����
	core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//�󶨻������OpenGL״̬���ϡ�
	core->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//�ѵ�ǰ����ĳ�����͵Ļ��壬��ָ����ڴ����Ӵ��䵽GPU�Ļ�����

	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	core->glEnableVertexAttribArray(0);//�Զ�������λ��ֵ��Ϊ���������ö������ԡ�����ɫ���ܹ������������
	core->glPolygonMode(GL_BACK, GL_LINE);
	core->glBindVertexArray(0);//VAO�������
		//2.4 ���ע������䲻�ܷŵ�VAO�������أ�����VAO�ͼ����˽�󣬾�û��paint��
	core->glBindBuffer(GL_ARRAY_BUFFER, 0);
	core->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	//������ɫ��
	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	vertexShader.compileSourceFile("shader/rect.vert");
	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	fragmentShader.compileSourceFile("shader/rect.frag");

	//������������ɫ������
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
	//��������EBO��ƫ����
	//����EBO��
}
