#ifndef math_triangle_2_h
#define math_triangle_2_h

#include "functions/functions.h"
#include "constants/constants.h"
#include "vector/vector.h"

typedef struct triangle2
{
    vec2_t pts[3];
} tri2_t;

tri2_t tri2_new (const vec2_t* pt1_pi, const vec2_t* pt2_pi, const vec2_t* pt3_pi);
void tri2_set (tri2_t* tri_po, const vec2_t* pt1_pi, const vec2_t* pt2_pi, const vec2_t* pt3_pi);
tri2_t tri2_scale (const tri2_t* tri_pi, const double n_i);

#endif
