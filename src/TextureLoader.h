//
// Created by Colby on 12/24/2019.
//

#ifndef BOILER_TEXTURELOADER_H
#define BOILER_TEXTURELOADER_H
#define STB_IMAGE_IMPLEMENTATION

#include "../libs/stb/stb_image.h"
#include <iostream>
#include <glad/glad.h>

class TextureLoader {
private:
    int width, height;
    unsigned int textureId;
public:
    explicit TextureLoader(const std::string& fileName){
        stbi_set_flip_vertically_on_load(true);
        int nrChannels;
        unsigned char *data = stbi_load(("../res/textures/"+fileName+".png").c_str(), &width, &height, &nrChannels, 0);
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    }
};

#endif //BOILER_TEXTURELOADER_H
