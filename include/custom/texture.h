#pragma once
#include <custom/core.h>
#include <stb/stb_image.h>

class Texture
{
    // variable
public:
    int mySlot;

private:
    std::string textureLocation;
    static int textureSlot; // by default initialized to zero

    unsigned int textureId;

public:
    Texture(std::string textureLocation);
};
