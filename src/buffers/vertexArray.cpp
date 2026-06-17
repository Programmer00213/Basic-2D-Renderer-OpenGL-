#include <custom/buffer/vertexArray.h>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &id);
    bind();
}

VertexArray::~VertexArray()
{
}

void VertexArray::bind() const
{
    glBindVertexArray(id);
}

void VertexArray::unBind() const
{
    glBindVertexArray(0);
}

void VertexArray::addLayout(VertexBuffer &vb, BufferLayout &layout)
{
    vb.bind();
    std::vector<VertexBufferElements> elements = layout.getElements();
    size_t offset = 0; // integer is 4 bytes but pointer is 8 bytes, so using size_t
    for (int i = 0; i < elements.size(); i++)
    {
        VertexBufferElements element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void *)offset);
        offset += element.count * BufferLayout::getSizeOfType(element.type);
    }
}