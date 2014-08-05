#include "functions/functions.h"

double math_sqrt(const double n)
{
    return sqrt(n);
}

double math_deg_to_rad(const double deg)
{
    return deg * MATH_DEG_IN_RAD;
}

double math_rad_to_deg(const double rad)
{
    return rad * MATH_RAD_IN_DEG;
}

double math_cos_rad(const double rad)
{
    return cos(rad);
}

double math_cos_deg(const double deg)
{
    return cos(deg * MATH_DEG_IN_RAD);
}

double math_sin_rad(const double rad)
{
    return sin(rad);
}

double math_sin_deg(const double deg)
{
    return sin(deg * MATH_DEG_IN_RAD);
}
