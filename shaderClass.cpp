#include"shaderClass.h"

std::string get_file_contents(const char* filename)
{
	//read a shaders in as a string
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}


Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);//unsigned int
	//attach vertex shader source to the vertex shader object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//compile the vertex shader into machine code (for the GPU
	glCompileShader(vertexShader);

	//create fragment shader object and get reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//attach fragment shader source to the fragment shader object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	//compile the fragment shader into machine code
	glCompileShader(fragmentShader);

	//create shader program object and get its reference
	ID = glCreateProgram();

	//attach the vertex and fragment shader to the shader program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	//wrap up/link all the shaders together into the shader program
	glLinkProgram(ID);

	//delete the now useless vertex and fragment shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteProgram(ID);
}