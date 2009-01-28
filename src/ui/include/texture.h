
#ifndef __TEXTURE_H_
#define __TEXTURE_H_

#include <string>

typedef struct
{
    /** OpenGL Texture ID. */
    unsigned int id;

    /** Upper-left u-coordinate. Ranges from 0.0f to 1.0f. */
    float u1;

    /** Upper-left v-coordinate. Ranges from 0.0f to 1.0f. */
    float v1;

    /** Lower-right u-coordinate. Ranges from 0.0f to 1.0f. */
    float u2;

    /** Lower-right v-coordinate. Ranges from 0.0f to 1.0f. */
    float v2;

    /** Width of texture in pixels. */
    int width;

    /** Height of texture in pixels. */
    int height;
}
texture_t;

class texture
{
    public:
        texture( std::string filename );
        ~texture();
        texture_t texture_data;
};

#endif