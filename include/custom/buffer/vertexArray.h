#pragma once
#include <custom/buffer/bufferLayout.h>
#include <custom/buffer/vertexBuffer.h>

class VertexArray
{
private:
    unsigned int id;

public:
    VertexArray();
    ~VertexArray();
    void bind() const;
    void unBind() const;
    void addLayout(VertexBuffer &vb, BufferLayout &layout);
};