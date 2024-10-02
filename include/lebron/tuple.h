#pragma once

typedef struct LEtuple LEtuple;

struct LEtuple
{
    float xyzw[4];
};

LEtuple leMakeTuple(float x, float y, float z, float w);
LEtuple leMakePoint(float x, float y, float z);
LEtuple leMakeVector(float x, float y, float z);

LEtuple leTupleAdd(LEtuple lhs, LEtuple rhs);
LEtuple leTupleSub(LEtuple lhs, LEtuple rhs);
LEtuple leTupleMul(LEtuple lhs, float rhs);
LEtuple leTupleDiv(LEtuple lhs, float rhs);

LEtuple leTupleNeg(LEtuple tuple);

float leTupleMag(LEtuple tuple);
LEtuple leTupleNorm(LEtuple tuple);

float leTupleDot(LEtuple lhs, LEtuple rhs);
LEtuple leTupleCross(LEtuple lhs, LEtuple rhs);