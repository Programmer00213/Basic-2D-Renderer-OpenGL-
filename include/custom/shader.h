#pragma once

#include <custom/core.h>
#include <fstream>
#include <string>

class Shader
{
    // variables
private:
    // shader program id
    unsigned int id;

    const std::string shaderFolder;
    std::vector<std::string> shaderFiles;

    char *shaderCodeBuffer;

    unsigned int shaderType;
    std::string shaderName;

    // functions
public:
    Shader(const std::string shaderFolder, std::vector<std::string> shaderFiles);
    ~Shader();
    void bind() const;
    void unBind() const;
    void setUniform(const std::string &name, const unsigned int value) const;

private:
    void getShaderType(std::string &shaderFile);
    void loadShaderCode(std::string &shaderFile);
    void debug(unsigned int id, int statusType, const std::string &shaderFile = "");
};