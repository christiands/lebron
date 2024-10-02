#include <stdio.h>

#include <lebron/canvas.h>

int main(int argc, char** argv)
{
    LEcanvas canvas;
    leCreateCanvas(&canvas, 1280, 720);

    for(size_t x = 0; x < 1280; ++x) {
        LEcolor color = leMakeColor(0.0f, 0.0f, x / 1280.0f);
        for(size_t y = 0; y < 720; ++y) {
            leCanvasSetPixel(&canvas, x, y, color);
        }
    }

    leCanvasWritePNG(&canvas, "result.png");
    leDeleteCanvas(&canvas);

    return 0;
}