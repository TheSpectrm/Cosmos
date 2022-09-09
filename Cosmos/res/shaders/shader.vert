#version 400 core

in vec3 position;
out vec3 color;

uniform mat4 modelMatrix;

void main(void)
{
	gl_Position = modelMatrix * vec4(position, 1.0);
	color = vec3(position.x + 0.5, 0.2, position.y + 0.5);
}