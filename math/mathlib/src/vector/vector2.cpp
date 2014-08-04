#include "vector/vector2.h"

vec2_t vec2_new (const double x_i, double y_i)
{
    vec2_t vec;
    vec.x = x_i;
    vec.y = y_i;
    return vec;
}

void vec2_set (vec2_t* vec_po, const double x_i, const double y_i)
{
    vec_po->x = x_i;
    vec_po->y = y_i;
}

vec2_t vec2_sum (const vec2_t vec1_i, const vec2_t vec2_i)
{
    vec2_t vec;
    vec.x = vec1_i.x + vec2_i.x;
    vec.y = vec1_i.y + vec2_i.y;
    return vec;
}

vec2_t vec2_diff (const vec2_t vec1_i, const vec2_t vec2_i)
{
    vec2_t vec;
    vec.x = vec1_i.x - vec2_i.x;
    vec.y = vec1_i.y - vec2_i.y;
    return vec;
}

vec2_t vec2_scale (const vec2_t vec_i, const double n_i)
{
    vec2_t vec;
    vec.x = vec_i.x * n_i;
    vec.y = vec_i.y * n_i;
    return vec;
}

vec2_t vec2_add (const vec2_t vec_i, const double n_i)
{
    vec2_t vec;
    vec.x = vec_i.x + n_i;
    vec.y = vec_i.y + n_i;
    return vec;
}

vec2_t vec2_sub (const vec2_t vec_i, const double n_i)
{
    vec2_t vec;
    vec.x = vec_i.x - n_i;
    vec.y = vec_i.y - n_i;
    return vec;
}

double vec2_dot (const vec2_t vec1_i, const vec2_t vec2_i)
{
    return vec1_i.x * vec2_i.x + vec1_i.y * vec2_i.y;
}

int vec2_isEqual(const vec2_t vec1_i, const vec2_t vec2_i)
{
    return (vec1_i.x == vec2_i.x) && (vec1_i.y == vec2_i.y);
}

int vec2_isCollinear(const vec2_t vec1_i, const vec2_t vec2_i)
{
    return (vec1_i.x * vec2_i.y - vec1_i.y * vec2_i.x) == 0.f;
}

int vec2_isOrthogonal(const vec2_t vec1_i, const vec2_t vec2_i)
{
    return (vec1_i.x * vec2_i.x + vec1_i.y * vec2_i.y) == 0.f;
}

void vec2_copy(vec2_t* vec_to_po, const vec2_t vec_from_i)
{
    vec_to_po->x = vec_from_i.x;
    vec_to_po->y = vec_from_i.y;
}

double vec2_lengthSquared(const vec2_t vec_i)
{
    return vec_i.x * vec_i.x + vec_i.y * vec_i.y;
}
