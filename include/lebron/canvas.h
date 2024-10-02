#pragma once

#include <lebron/color.h>

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct LEcanvas LEcanvas;

struct LEcanvas
{
    size_t width, height;
    float* buffer;
};

void leCreateCanvas(LEcanvas* target, size_t width, size_t height);
void leDeleteCanvas(LEcanvas* target);

LEcolor leCanvasGetPixel(const LEcanvas* target, size_t x, size_t y);
void leCanvasSetPixel(LEcanvas* target, size_t x, size_t y, LEcolor color);

// NOTE: dest has to be deallocated manually
void leCanvasAsRGB8(const LEcanvas* target, uint8_t** dest);

void leCanvasWritePNG(const LEcanvas* target, const char* filename);