#include "HelloShader.h"

HelloShader::HelloShader(QWidget *parent)
	: QOpenGLWidget(parent) {


}

void HelloShader::initializeGL() {
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();//һ����װ��


//��������׼�������ݣ�VAO��VBO���ݲ��֡�ע�������-1~+1֮�䣬������ڷ�Χ�ڣ��Ͳ������ӿڳ���
	GLfloat vertices[] = {
			-0.5f, -0.5f, 0.0f,  // left  
			 0.5f, -0.5f, 0.0f, // right  
			 0.0f,  0.5f, 0.0f  // top   
	};


	//����һ��VAO�����Ұ�������
	core->glGenVertexArrays(1, &VAO);//������������һ��Ϊ��Ҫ�����Ļ����������ڶ���Ϊ���ڴ洢��һID����ID��GLuint����������ĵ�ַ
	core->glGenBuffers(1, &VBO);//��һ��������Ҫ���ɵĻ��������������ڶ�����Ҫ���������洢����������Ƶ�����

	//VAO��
	core->glBindVertexArray(VAO);
	//���и�GL_ARRAY_BUFFER�й�ϵ�Ĳ���״̬���������¼����				 
									 //������VBOȥ���������ڴ��е����ݣ�����һ���Խ��������ݴ���GPU����ΪCPU-->GPU�Ǻ�����
	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);//�󶨻������OpenGL״̬���ϡ�
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//�ѵ�ǰ����ĳ�����͵Ļ��壬��ָ����ڴ����Ӵ��䵽GPU�Ļ�����

	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	core->glEnableVertexAttribArray(0);//�Զ�������λ��ֵ��Ϊ���������ö������ԡ�����ɫ���ܹ������������


	//�󶨿ջ���������һ����ʵ���Բ�Ҫ



	//1.location��������ɫ����Ӧ�ģ�һ���СΪ16��
	//2.�������ԵĴ�С
	//3.
	//4.�Ƿ�ϣ�����ݱ���׼��
	//5.����

	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	bool success = vertexShader.compileSourceFile("shader/triangle.vert");
	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	success = fragmentShader.compileSourceFile("shader/triangle.frag");

	//������������ɫ������
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
