#include <lebron/math.h>

float leFloatAbs(float f)
{
    return f < 0.0f ? -f : f;
}

bool leFloatCmp(float lhs, float rhs)
{
    return leFloatCmpE(lhs, rhs, LE_FLOAT_EPSILON);
}

bool leFloatCmpE(float lhs, float rhs, float epsilon)
{
    return leFloatAbs(lhs - rhs) <= epsilon;
}