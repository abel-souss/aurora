#ifndef math_vecor_2_h
#define math_vecor_2_h

#include "functions/functions.h"
#include "constants/constants.h"

typedef struct vector2
{
    double x, y;
} vec2_t;

vec2_t vec2_new (const double x_i, double y_i);
vec2_t vec2_null ();
void vec2_set (vec2_t* vec_po, const double x_i, const double y_i);
vec2_t vec2_sum (const vec2_t vec1_i, const vec2_t vec2_i);
vec2_t vec2_diff (const vec2_t vec1_i, const vec2_t vec2_i);
vec2_t vec2_scale (const vec2_t vec_i, const double n_i);
vec2_t vec2_add (const vec2_t vec_i, const double n_i);
vec2_t vec2_sub (const vec2_t vec_i, const double n_i);
double vec2_dot (const vec2_t vec1_i, const vec2_t vec2_i);
vec2_t vec2_rotate_deg(const vec2_t vec_i, const double r);
vec2_t vec2_rotate_rad(const vec2_t vec_i, const double r);
vec2_t vec2_rotate_orthogonal(const vec2_t vec_i, const int direct);
int vec2_is_equal(const vec2_t vec1_i, const vec2_t vec2_i);
int vec2_is_collinear(const vec2_t vec1_i, const vec2_t vec2_i);
int vec2_is_orthogonal(const vec2_t vec1_i, const vec2_t vec2_i);
void vec2_copy(vec2_t* vec_to_po, const vec2_t vec_from_i);
double vec2_length_squared(const vec2_t vec_i);
double vec2_length(const vec2_t vec_i);
vec2_t vec2_normalize(const vec2_t vec_i);

#endif
