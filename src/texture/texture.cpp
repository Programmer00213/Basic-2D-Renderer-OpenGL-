#include <custom/texture.h>

int Texture::textureSlot = 0;

Texture::Texture(std::string textureLocation) : textureLocation(textureLocation)
{
    // create texture
    glGenTextures(1, &textureId);

    // activate and bind texture
    glActiveTexture(GL_TEXTURE0 + textureSlot);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // increase texture slot id
    mySlot = textureSlot++;

    // set texture parameters

    // how to fill the surface if texture is smaller than the surface for S = X axis and T = Y axis
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // how to display pixels when texture is bigger or smaller than the surface
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // needs minmap to work
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, colorChannel;
    stbi_set_flip_vertically_on_load(GL_TRUE);
    unsigned char *data = stbi_load(textureLocation.c_str(), &width, &height, &colorChannel, 0);

    if (data)
    {
        // get color format used in the image
        GLenum format = colorChannel == 4 ? GL_RGBA : GL_RGB;
        // upload texture data to GPU
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        // create texture minmap
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        throw std::runtime_error("ERROR: Failed to load texture: " + textureLocation);
    }

    // free memory used to load image
    stbi_image_free(data);
}