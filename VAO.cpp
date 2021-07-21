#include "VAO.h"


VAO::VAO() {
	//generate the VAO with only 1 object each
	glGenVertexArrays(1, &ID); //order matter here! do the VAO first!


}

void VAO::LinkVBO(VBO VBO, GLuint layout) {
	VBO.Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
	VBO.Unbind();
}
void VAO::Bind() {
	glBindVertexArray(ID);
}
void VAO::Unbind() {
	glBindVertexArray(0);
}
void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}