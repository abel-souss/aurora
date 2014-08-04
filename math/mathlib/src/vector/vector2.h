#ifndef math_vecor_2_h
#define math_vecor_2_h

typedef struct vector2
{
    double x, y;
} vec2_t;

vec2_t vec2_new (const double x_i, double y_i);
void vec2_set (vec2_t* vec_po, const double x_i, const double y_i);
vec2_t vec2_sum (const vec2_t vec1_i, const vec2_t vec2_i);
vec2_t vec2_diff (const vec2_t vec1_i, const vec2_t vec2_i);
vec2_t vec2_scale (const vec2_t vec_i, const double n_i);
vec2_t vec2_add (const vec2_t vec_i, const double n_i);
vec2_t vec2_sub (const vec2_t vec_i, const double n_i);
double vec2_dot (const vec2_t vec1_i, const vec2_t vec2_i);
int vec2_isEqual(const vec2_t vec1_i, const vec2_t vec2_i);
int vec2_isCollinear(const vec2_t vec1_i, const vec2_t vec2_i);
int vec2_isOrthogonal(const vec2_t vec1_i, const vec2_t vec2_i);
void vec2_copy(vec2_t* vec_to_po, const vec2_t vec_from_i);
double vec2_lengthSquared(const vec2_t vec_i);

#endif
