#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size) {
	//generate the VBO with only 1 object
	glGenBuffers(1, &ID);
	//bind the VBO specifying its a GL_array_buffer
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	//introduce vertices into the vbo
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);

}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}