#version 330 core
out vec4 FragColor;

in vec4 vertexColor; // �Ӷ�����ɫ�����������������������ͬ��������ͬ��


uniform vec4 ourColor;

void main()
{
    //FragColor = vec4(0.3f, 0.5f, 0.2f, 1.0f);
	//FragColor = vertexColor;
	FragColor = ourColor;
} 