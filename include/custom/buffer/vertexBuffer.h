#pragma once
#include <custom/core.h>

class VertexBuffer
{
private:
    unsigned int id;

public:
    VertexBuffer(float *data, unsigned int size);
    ~VertexBuffer();
    void bind() const; // this function can not modify any member variables
    void unBind() const;
};