#include <lebron/tuple.h>

#include <math.h>

LEtuple leMakeTuple(float x, float y, float z, float w)
{
    LEtuple result = {
        .xyzw = {x, y, z, w},
    };

    return result;
}

LEtuple leMakePoint(float x, float y, float z)
{
    return leMakeTuple(x, y, z, 1.0f);
}

LEtuple leMakeVector(float x, float y, float z)
{
    return leMakeTuple(x, y, z, 0.0f);
}

LEtuple leTupleAdd(LEtuple lhs, LEtuple rhs)
{
    LEtuple result = {
        .xyzw = {
            lhs.xyzw[0] + rhs.xyzw[0],
            lhs.xyzw[1] + rhs.xyzw[1],
            lhs.xyzw[2] + rhs.xyzw[2],
            lhs.xyzw[3] + rhs.xyzw[3],
        }
    };

    return result;
}

LEtuple leTupleSub(LEtuple lhs, LEtuple rhs)
{
    LEtuple result = {
        .xyzw = {
            lhs.xyzw[0] - rhs.xyzw[0],
            lhs.xyzw[1] - rhs.xyzw[1],
            lhs.xyzw[2] - rhs.xyzw[2],
            lhs.xyzw[3] - rhs.xyzw[3],
        }
    };

    return result;
}

LEtuple leTupleMul(LEtuple lhs, float rhs)
{
    LEtuple result = {
        .xyzw = {
            lhs.xyzw[0] * rhs,
            lhs.xyzw[1] * rhs,
            lhs.xyzw[2] * rhs,
            lhs.xyzw[3] * rhs,
        }
    };

    return result;
}

LEtuple leTupleDiv(LEtuple lhs, float rhs)
{
    LEtuple result = {
        .xyzw = {
            lhs.xyzw[0] / rhs,
            lhs.xyzw[1] / rhs,
            lhs.xyzw[2] / rhs,
            lhs.xyzw[3] / rhs,
        }
    };

    return result;
}

LEtuple leTupleNeg(LEtuple tuple)
{
    LEtuple result = {
        .xyzw = {
            -tuple.xyzw[0],
            -tuple.xyzw[1],
            -tuple.xyzw[2],
            -tuple.xyzw[3],
        }
    };

    return result;
}

float leTupleMag(LEtuple tuple)
{
    return sqrtf(
        tuple.xyzw[0] * tuple.xyzw[0] +
        tuple.xyzw[1] * tuple.xyzw[1] +
        tuple.xyzw[2] * tuple.xyzw[2] +
        tuple.xyzw[3] * tuple.xyzw[3]
    );
}

LEtuple leTupleNorm(LEtuple tuple)
{
    return leTupleDiv(tuple, leTupleMag(tuple));
}

float leTupleDot(LEtuple lhs, LEtuple rhs)
{
    return (lhs.xyzw[0] * rhs.xyzw[0]) +
           (lhs.xyzw[1] * rhs.xyzw[1]) +
           (lhs.xyzw[2] * rhs.xyzw[2]) +
           (lhs.xyzw[3] * rhs.xyzw[3]);
}

LEtuple leTupleCross(LEtuple lhs, LEtuple rhs)
{
    return leMakeVector(
        (lhs.xyzw[1] * rhs.xyzw[2]) - (lhs.xyzw[2] * rhs.xyzw[1]),
        (lhs.xyzw[2] * rhs.xyzw[0]) - (lhs.xyzw[0] * rhs.xyzw[2]),
        (lhs.xyzw[0] * rhs.xyzw[1]) - (lhs.xyzw[1] * rhs.xyzw[0])
    );
}