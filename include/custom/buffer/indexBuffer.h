#pragma once
#include <custom/core.h>

class IndexBuffer
{
private:
    unsigned int id;

public:
    IndexBuffer(unsigned int *data, unsigned int count);
    ~IndexBuffer();
    void bind() const;
    void unBind() const;
};