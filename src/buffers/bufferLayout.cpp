#include <custom/buffer/bufferLayout.h>

BufferLayout::BufferLayout() : stride(0)
{
}

unsigned int BufferLayout::getSizeOfType(unsigned int type)
{
    switch (type)
    {
    case GL_FLOAT:
        return sizeof(float);
    case GL_UNSIGNED_INT:
        return sizeof(unsigned int);
    case GL_UNSIGNED_BYTE:
        return sizeof(unsigned char);
    }
    assert(false);
    return 0;
}

template <typename T>
void BufferLayout::push(unsigned int count)
{
    static_assert(sizeof(T) == 0, "Unsupported Type");
}

// template specialization
template <>
void BufferLayout::push<float>(unsigned int count)
{

    element.push_back({
        count,
        GL_FLOAT,
        (char)false,
    });

    stride += count * sizeof(float);
}

template <>
void BufferLayout::push<unsigned int>(unsigned int count)
{
    element.push_back({
        count,
        GL_UNSIGNED_INT,
        (char)false,
    });

    stride += count * sizeof(unsigned int);
}