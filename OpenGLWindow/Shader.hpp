#ifndef Shader_hpp
#define Shader_hpp

#include <GL/glew.h>

class Shader
{
public:
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void Use();
protected:
private:
    GLuint Program;
};

#endif /* Shader_hpp */
