#include <shaderProgram.h>

std::string Shader::get_file(const char* get_file)
{
    std::ifstream file(get_file, std::ios::in | std::ios::binary);
    if (!file){
        std::cout << "can't open shader" << std::endl;
        return 0;
    }
    std::string contents;
	file.seekg(0, std::ios::end);
	contents.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&contents[0], contents.size());
	file.close();
	return contents;

}

Shader::Shader(const char* Vertex_file, const char* Fragment_file){
    std::string vertex_code = get_file(Vertex_file);
    std::string fragment_code = get_file(Fragment_file);

    const char* vertex_source = vertex_code.c_str();
    const char* fragment_source = fragment_code.c_str();

    GLuint vertexShader, fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_source, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_source, NULL);
    glCompileShader(fragmentShader);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void Shader::useProgram(){
    glUseProgram(ID);
}
void Shader::deleteProgram(){
    glDeleteProgram(ID);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}