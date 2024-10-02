// I didn't do stupid macro crap here since having a readable interface is kinda important
#pragma once

#include <lebron/tuple.h>

#include <stdbool.h>
#include <stddef.h>

typedef struct LEmat2 LEmat2;
typedef struct LEmat3 LEmat3;
typedef struct LEmat4 LEmat4;

struct LEmat2
{
    float elem[4];
};

#define LE_IDENTITY2 {.elem = { \
1.0f, 0.0f,                     \
0.0f, 1.0f}}

// Expects an array of 4 elements
LEmat2 leMakeMat2(float* data);

bool leMat2Cmp(LEmat2 lhs, LEmat2 rhs);

float leMat2Det(LEmat2 matrix);


struct LEmat3
{
    float elem[9];
};

#define LE_IDENTITY3 {.elem = { \
1.0f, 0.0f, 0.0f,               \
0.0f, 1.0f, 0.0f,               \
0.0f, 0.0f, 1.0f}}

// Expects an array of 9 elements
LEmat3 leMakeMat3(float* data);

bool leMat3Cmp(LEmat3 lhs, LEmat3 rhs);

float leMat3Det(LEmat3 matrix);


struct LEmat4
{
    float elem[16];
};

#define LE_IDENTITY4 {.elem = { \
1.0f, 0.0f, 0.0f, 0.0f          \
0.0f, 1.0f, 0.0f, 0.0f,         \
0.0f, 0.0f, 1.0f, 0.0f,         \
0.0f, 0.0f, 0.0f, 1.0f}}

// Expects an array of 16 elements
LEmat4 leMakeMat4(float* data);
bool leMat4Cmp(LEmat4 lhs, LEmat4 rhs);

LEmat4 leMat4MulM(LEmat4 lhs, LEmat4 rhs);
LEmat4 leMat4MulS(LEmat4 lhs, float rhs);
LEtuple leMat4MulT(LEmat4 lhs, LEtuple rhs);

LEmat3 leMat4Submatrix(LEmat4 matrix, size_t row, size_t col);
float leMat4Det(LEmat4 matrix);