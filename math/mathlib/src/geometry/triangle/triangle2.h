#ifndef math_triangle_2_h
#define math_triangle_2_h

#include "functions/functions.h"
#include "constants/constants.h"
#include "vector/vector2.h"

typedef struct triangle2
{
    vec2_t pts[3];
} tri2_t;

tri2_t tri2_new (const vec2_t* pt1_pi, const vec2_t* pt2_pi, const vec2_t* pt3_pi);
void tri2_set (tri2_t* tri_po, const vec2_t* pt1_pi, const vec2_t* pt2_pi, const vec2_t* pt3_pi);
tri2_t tri2_scale (const tri2_t* tri_pi, const double n_i);
double tri2_perimeter (const tri2_t* tri_pi);
double tri2_area (const tri2_t* tri_pi);
int tri2_is_valid (const tri2_t* tri_pi);
int tri2_is_right (const tri2_t* tri_pi);
int tri2_is_equilateral (const tri2_t* tri_pi);
int tri2_is_isosceles (const tri2_t* tri_pi);
int tri2_is_scalene (const tri2_t* tri_pi);
tri2_t tri2_rotate_deg (const tri2_t* tri_pi, const vec2_t* org_i, const double r);
tri2_t tri2_rotate_rad (const tri2_t* tri_pi, const vec2_t* org_i, const double r);
tri2_t tri2_rotate_orthogonal (const tri2_t* tri_pi, const vec2_t* org_i, const int direct);
tri2_t tri2_rotate_opposite (const tri2_t* tri_pi, const vec2_t* org_i);

#endif
