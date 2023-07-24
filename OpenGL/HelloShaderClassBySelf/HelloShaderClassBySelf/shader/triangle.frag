#version 330 core
out vec4 FragColor;
in vec3 ourColor;

uniform float TimeColorChange;

void main()
{
    FragColor = vec4(TimeColorChange*ourColor, 1.0f);
} 