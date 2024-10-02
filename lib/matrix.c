// I'm sorry to whoever has to read this heresy
#include "macros.h"

#include <lebron/math.h>

#include <stdbool.h>
#include <string.h>

#ifndef LEI_MATRIX_DIM
#error "LEI_MATRIX_DIM must be specified"
#endif

#ifndef LEI_MATRIX_ELEMS
#error "LEI_MATRIX_ELEMS must be specified"
#endif

#define LEI_MATRIX_TYPENAME LEI_CONCAT(LEmat, LEI_MATRIX_DIM)
#define LEI_MATRIX_MAKE LEI_CONCAT(leMakeMat, LEI_MATRIX_DIM)
#define LEI_MATRIX_FN(NAME) LEI_CONCAT(leMat, LEI_CONCAT(LEI_MATRIX_DIM, NAME))

LEI_MATRIX_TYPENAME LEI_MATRIX_MAKE(float* data)
{
    LEI_MATRIX_TYPENAME result;

    memcpy(result.elem, data, sizeof(float) * LEI_MATRIX_ELEMS);

    return result;
}

bool LEI_MATRIX_FN(Cmp)(LEI_MATRIX_TYPENAME lhs, LEI_MATRIX_TYPENAME rhs)
{
    for(size_t i = 0; i < LEI_MATRIX_ELEMS; ++i) {
        if(!leFloatCmp(lhs.elem[i], rhs.elem[i])) {
            return false;
        }
    }

    return true;
}