#include <custom/buffer/vertexBuffer.h>

VertexBuffer::VertexBuffer(float *data, unsigned int size)
{
    // create a buffer
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    // send buffer data to gpu;
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    std::cout << "Buffer Deleted" << std::endl;
    glDeleteBuffers(1, &id);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::unBind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}