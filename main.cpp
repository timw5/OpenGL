#include <iostream>
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaderClass.h"
#include"VAO.h"
#include "VBO.h"
#include "EBO.h"



int main() {

	//initialize GLFW
	glfwInit();

	//Tell GLFW what version of OpenGL we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//tell GLFW we are using the CORE profile
	//that means we are only using the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//coordinates of vertices
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, //lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, //lower right corner
		0.0f, 0.75f * float(sqrt(3)) * 2 / 3, 0.0f, // upper corner
		-0.5f/2, 0.5f * float(sqrt(3)) * 2 / 6, 0.0f,//inner left
		0.5f/2, 0.5f * float(sqrt(3)) * 2 / 6, 0.0f,//inner right
		0.0f, -0.5f * float(sqrt(3)) * 2 / 6, 0.0f,//inner down

	};




	//create a GLFWWindow object of 800 by 800 pixels, naming it "OpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);

	//make sure that the window loads
	if (window == NULL) {
		std::cout << "Failed to create a glfw window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//make the window
	glfwMakeContextCurrent(window);

	//load GLAD so it configures OpenGL
	gladLoadGL();

	//specify the viewport of OpenGL in the window
	glViewport(0, 0, 800, 600);

	//Create vertex shader object and get reference
	

	GLuint indices[] =
	{
		0, 3, 5, //lower left triangle
		3, 2, 4, //lower right triangle
		5, 4, 1 //upper tirangle
	};


	
	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));

	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();	


	while (!glfwWindowShouldClose(window))
	{
		//background color
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		shaderProgram.Activate();
		VAO1.Bind();
		//draw the triangle using the GL_TRIANGLES primitive 
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//cleanup
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}
