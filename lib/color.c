#include <lebron/color.h>

LEcolor leMakeColor(float r, float g, float b)
{
    LEcolor result = {
        .rgb = {r, g, b},
    };

    return result;
}

LEcolor leColorAdd(LEcolor lhs, LEcolor rhs)
{
    LEcolor result = {
        .rgb = {
            lhs.rgb[0] + rhs.rgb[0],
            lhs.rgb[1] + rhs.rgb[1],
            lhs.rgb[2] + rhs.rgb[2],
        }
    };

    return result;
}

LEcolor leColorSub(LEcolor lhs, LEcolor rhs)
{
    LEcolor result = {
        .rgb = {
            lhs.rgb[0] - rhs.rgb[0],
            lhs.rgb[1] - rhs.rgb[1],
            lhs.rgb[2] - rhs.rgb[2],
        }
    };

    return result;
}

LEcolor leColorMulC(LEcolor lhs, LEcolor rhs)
{
    LEcolor result = {
        .rgb = {
            lhs.rgb[0] * rhs.rgb[0],
            lhs.rgb[1] * rhs.rgb[1],
            lhs.rgb[2] * rhs.rgb[2],
        }
    };

    return result;
}

LEcolor leColorMulS(LEcolor lhs, float rhs)
{
    LEcolor result = {
        .rgb = {
            lhs.rgb[0] * rhs,
            lhs.rgb[1] * rhs,
            lhs.rgb[2] * rhs,
        }
    };

    return result;
}