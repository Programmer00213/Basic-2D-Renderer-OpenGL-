#include <custom/buffer/indexBuffer.h>

IndexBuffer::IndexBuffer(unsigned int *data, unsigned int count)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    std::cout << "Buffer Deleted" << std::endl;
    glDeleteBuffers(1, &id);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBuffer::unBind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}