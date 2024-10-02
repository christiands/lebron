#pragma once

typedef struct LEcolor LEcolor;

struct LEcolor
{
    float rgb[3];
};

#define LE_COLOR_MACRO(r, g, b) {.rgb = {r, g, b}}

#define LE_COLOR_BLACK LE_COLOR_MACRO(0.0f, 0.0f, 0.0f)
#define LE_COLOR_WHITE LE_COLOR_MACRO(1.0f, 1.0f, 1.0f)

#define LE_COLOR_RED LE_COLOR_MACRO(0.0f, 0.0f, 0.0f)
#define LE_COLOR_GREEN LE_COLOR_MACRO(0.0f, 0.0f, 0.0f)
#define LE_COLOR_BLUE LE_COLOR_MACRO(0.0f, 0.0f, 0.0f)

#define LE_COLOR_YELLOW LE_COLOR_MACRO(1.0f, 1.0f, 0.0f)
#define LE_COLOR_MAGENTA LE_COLOR_MACRO(1.0f, 0.0f, 1.0f)
#define LE_COLOR_CYAN LE_COLOR_MACRO(0.0f, 1.0f, 1.0f)

LEcolor leMakeColor(float r, float g, float b);

LEcolor leColorAdd(LEcolor lhs, LEcolor rhs);
LEcolor leColorSub(LEcolor lhs, LEcolor rhs);
LEcolor leColorMulC(LEcolor lhs, LEcolor rhs);
LEcolor leColorMulS(LEcolor lhs, float rhs);