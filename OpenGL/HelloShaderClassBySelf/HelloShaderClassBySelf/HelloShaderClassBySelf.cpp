#include "HelloShaderClassBySelf.h"

HelloShaderClassBySelf::HelloShaderClassBySelf(QWidget *parent)
	: QOpenGLWidget(parent) {}

void HelloShaderClassBySelf::initializeGL() {
	core = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();//һ����װ��
	ourShader = new Shader("shader/triangle.vert", "shader/triangle.frag");

	//��������׼�������ݣ�VAO��VBO���ݲ��֡�ע�������-1~+1֮�䣬������ڷ�Χ�ڣ��Ͳ������ӿڳ���

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


	//����һ��VAO�����Ұ�������
	core->glGenVertexArrays(1, &VAO);//������������һ��Ϊ��Ҫ�����Ļ����������ڶ���Ϊ���ڴ洢��һID����ID��GLuint����������ĵ�ַ
	core->glGenBuffers(1, &VBO);//��һ��������Ҫ���ɵĻ��������������ڶ�����Ҫ���������洢����������Ƶ�����
	core->glGenBuffers(1, &VBOColor);

	//VAO��
	core->glBindVertexArray(VAO);
	//���и�GL_ARRAY_BUFFER�й�ϵ�Ĳ���״̬���������¼����				 
									 //������VBOȥ���������ڴ��е����ݣ�����һ���Խ��������ݴ���GPU����ΪCPU-->GPU�Ǻ�����
	core->glBindBuffer(GL_ARRAY_BUFFER, VBO);//�󶨻������OpenGL״̬���ϡ�
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPostion), verticesPostion, GL_STATIC_DRAW);//�ѵ�ǰ����ĳ�����͵Ļ��壬��ָ����ڴ����Ӵ��䵽GPU�Ļ�����
	core->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	core->glBindBuffer(GL_ARRAY_BUFFER, VBOColor);//�󶨻������OpenGL״̬���ϡ�
	core->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColor2), verticesColor2, GL_STATIC_DRAW);//�ѵ�ǰ����ĳ�����͵Ļ��壬��ָ����ڴ����Ӵ��䵽GPU�Ļ�����
	core->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

	core->glEnableVertexAttribArray(0);//�Զ�������λ��ֵ��Ϊ���������ö������ԡ�����ɫ���ܹ������������
	core->glEnableVertexAttribArray(1);//�Զ�������λ��ֵ��Ϊ���������ö������ԡ�����ɫ���ܹ������������


	//�󶨿ջ�����,��Ϊ��β
	core->glBindVertexArray(0);
	core->glBindBuffer(GL_ARRAY_BUFFER, 0);//ע���˳��

	//1.location��������ɫ����Ӧ�ģ�һ���СΪ16��
	//2.�������ԵĴ�С
	//3.
	//4.�Ƿ�ϣ�����ݱ���׼��
	//5.����

	//1.��ɫ���������������Կ��ϵĳ���
	//2.glsl�߼���ɫ���ԣ�C���Եļ򻯰�
	QOpenGLShader vertexShader(QOpenGLShader::Vertex);
	vertexShader.compileSourceFile("shader/triangle.vert");
	QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
	fragmentShader.compileSourceFile("shader/triangle.frag");
	//������������ɫ������
	shaderProgram.addShader(&vertexShader);
	shaderProgram.addShader(&fragmentShader);
	shaderProgram.link();
}

void HelloShaderClassBySelf::resizeGL(int w, int h) {}

void HelloShaderClassBySelf::paintGL() {

	core->glClearColor(0.6f, 0.3f, 0.8f, 1.0f);//�����������ɫ
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
