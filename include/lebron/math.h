#pragma once

#include <stdbool.h>

#define LE_FLOAT_EPSILON 0.000001f

float leFloatAbs(float f);

bool leFloatCmp(float lhs, float rhs);

bool leFloatCmpE(float lhs, float rhs, float epsilon);