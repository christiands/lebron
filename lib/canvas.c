#include <lebron/canvas.h>

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void leCreateCanvas(LEcanvas* target, size_t width, size_t height)
{
    target->buffer = calloc(width * height * 3, sizeof(float));
    target->width = width;
    target->height = height;
}

void leDeleteCanvas(LEcanvas* target)
{
    free(target->buffer);
}

LEcolor leCanvasGetPixel(const LEcanvas* target, size_t x, size_t y)
{
    assert(x < target->width && y < target->height);

    LEcolor result;

    memcpy(result.rgb, &target->buffer[(y * target->width + x) * 3], sizeof(float) * 3);

    return result;
}

void leCanvasSetPixel(LEcanvas* target, size_t x, size_t y, LEcolor color)
{
    assert(x < target->width && y < target->height);

    memcpy(&target->buffer[(y * target->width + x) * 3], color.rgb, sizeof(float) * 3);
}

void leCanvasAsRGB8(const LEcanvas* target, uint8_t** dest)
{
    size_t elem_count = target->width * target->height * 3;
    uint8_t* buffer = malloc(elem_count);

    assert(buffer != NULL);

    for(size_t i = 0; i < elem_count; ++i) {
        buffer[i] = (uint8_t) (target->buffer[i] * 255.0f);
    }

    *dest = buffer;
}

void leCanvasWritePNG(const LEcanvas* target, const char* filename)
{
    // A bit weird, but if target width is greater than max as well it'll still throw
    assert(target->width * 3 <= INT_MAX && target->height <= INT_MAX);

    uint8_t* buffer;
    leCanvasAsRGB8(target, &buffer);

    stbi_write_png(filename, target->width, target->height, 3, buffer, target->width * 3);

    free(buffer);
}