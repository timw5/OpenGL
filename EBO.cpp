#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size) {
	//generate the VBO with only 1 object
	glGenBuffers(1, &ID);
	//bind the VBO specifying its a GL_array_buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	//introduce vertices into the vbo
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

}

void EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

}

void EBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}