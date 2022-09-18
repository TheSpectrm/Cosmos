#version 400 core

in vec3 position;
out vec3 color;

uniform mat4 model_matrix;
uniform mat4 proj_matrix;

void main(void)
{
	gl_Position = proj_matrix * model_matrix * vec4(position, 1.0);
	color = vec3(position.x + 0.5, 0.2, position.y + 0.5);
}