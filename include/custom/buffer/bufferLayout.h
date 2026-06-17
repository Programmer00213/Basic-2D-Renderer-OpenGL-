#pragma once
#include <custom/core.h>

struct VertexBufferElements
{
    unsigned int count;
    unsigned int type;
    unsigned char normalized;
};

class BufferLayout
{
private:
    std::vector<VertexBufferElements> element;
    unsigned int stride;

public:
    static unsigned int getSizeOfType(unsigned int type);
    BufferLayout();

    template <typename T>
    void push(unsigned int count);

    inline std::vector<VertexBufferElements> getElements()
    {
        return element;
    }
    inline unsigned int GetStride()
    {
        return stride;
    }
};