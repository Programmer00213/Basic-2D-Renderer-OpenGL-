#include <custom/shader.h>

Shader::Shader(const std::string shaderFolder, std::vector<std::string> shaderFiles) : shaderFolder(shaderFolder), shaderFiles(shaderFiles)
{
    id = glCreateProgram();
    std::vector<int> shaderId;
    for (int i = 0; i < shaderFiles.size(); i++)
    {
        std::string shaderFile = shaderFolder + shaderFiles[i];
        getShaderType(shaderFile);

        // create shader object
        unsigned int s_id = glCreateShader(shaderType);

        shaderId.push_back(s_id);

        loadShaderCode(shaderFile);

        // attach shader code to shader object
        glShaderSource(s_id, 1, &shaderCodeBuffer, NULL); // last parameter is length of string, if not specified uses null terminator
        glCompileShader(s_id);

        // debug
        debug(s_id, GL_COMPILE_STATUS, shaderFile);

        // attach shader to shaderProgram
        glAttachShader(id, s_id);

        // delete shaderCodeBuffer
        delete shaderCodeBuffer;
    }
    glLinkProgram(id);
    debug(id, GL_LINK_STATUS);

    for (int i = 0; i < shaderId.size(); i++)
    {
        glDeleteShader(shaderId[i]);
    }
}
Shader::~Shader()
{
    std::cout << "Shader Program Deleted" << std::endl;
    glDeleteProgram(id);
}

void Shader::bind() const
{
    glUseProgram(id);
}
void Shader::unBind() const
{
    glUseProgram(0);
}
void Shader::setUniform(const std::string &name, const unsigned int value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

// private functions

void Shader::getShaderType(std::string &shaderFile)
{
    std::string extension = shaderFile.substr(shaderFile.size() - 3);

    if (extension == ".vs")
    {
        shaderName = "vertex";
        shaderType = GL_VERTEX_SHADER;
    }

    else if (extension == ".fs")
    {
        shaderName = "fragment";
        shaderType = GL_FRAGMENT_SHADER;
    }
}

void Shader::loadShaderCode(std::string &shaderFile)
{
    // open file
    std::ifstream file(shaderFile, std::ios::binary);

    if (!file)
    {
        throw std::runtime_error("\nFILE: " + shaderFile + " ERROR: Failed to open " + shaderName + " source file\n");
    }

    // get file size
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0);

    // create shader code buffer
    shaderCodeBuffer = new char[size + 1];
    shaderCodeBuffer[size] = '\0';

    // copy shader code to buffer
    file.read(shaderCodeBuffer, size);
}

void Shader::debug(unsigned int id, int statusType, const std::string &shaderFile)
{
    int debugStatus;
    std::string action = statusType == GL_COMPILE_STATUS ? "compile" : "link";
    char infoLog[512] = {};

    std::string fileInfo;
    if (!shaderFile.empty())
    {
        fileInfo = "\nFILE: " + shaderFile + "\n";
    }

    if (statusType == GL_COMPILE_STATUS)
    {
        glGetShaderiv(id, statusType, &debugStatus);
        if (!debugStatus)
        {
            glGetShaderInfoLog(id, 512, NULL, infoLog);
            throw std::runtime_error(fileInfo + "ERROR: Failed to " + action + " " + shaderName + " source code\n" + infoLog);
        }
    }
    else
    {
        glGetProgramiv(id, statusType, &debugStatus);
        if (!debugStatus)
        {
            glGetProgramInfoLog(id, 512, NULL, infoLog);
            throw std::runtime_error(fileInfo + "ERROR: Failed to " + action + " " + shaderName + " source code\n" + infoLog);
        }
    }
}