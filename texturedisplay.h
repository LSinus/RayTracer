//
// Created by Leonardo Sinibaldi on 12/02/25.
//

#ifndef TEXTUREDISPLAY_H
#define TEXTUREDISPLAY_H



class TextureDisplay {
private:
    GLuint textureID = 0;
    int width = 0;
    int height = 0;

public:
    void init() {
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    void updateTexture(const std::vector<uint32_t>& pixels, int w, int h) {
        width = w;
        height = h;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                    GL_UNSIGNED_BYTE, pixels.data());
    }

    void render(const char* window_name = "Image Viewer") {


        // Display the texture
        ImGui::Image((ImTextureID)textureID,
             ImVec2(static_cast<float>(width),
                    static_cast<float>(height)));
    }

    ~TextureDisplay() {
        if (textureID != 0) {
            glDeleteTextures(1, &textureID);
        }
    }
};

#endif //TEXTUREDISPLAY_H
