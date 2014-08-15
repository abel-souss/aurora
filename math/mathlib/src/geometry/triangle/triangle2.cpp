#include "geometry/triangle/triangle2.h"

tri2_t tri2_new (const vec2_t* pt1_pi, const vec2_t* pt2_pi, const vec2_t* pt3_pi)
{
    tri2_t tri;

    vec2_copy(&(tri.pts[0]), *pt1_pi);
    vec2_copy(&(tri.pts[1]), *pt2_pi);
    vec2_copy(&(tri.pts[2]), *pt3_pi);

    return tri;
}

void tri2_set (tri2_t* tri_po, const vec2_t* pt1_pi, const vec2_t* pt2_pi, const vec2_t* pt3_pi)
{
    vec2_copy(&(tri_po->pts[0]), *pt1_pi);
    vec2_copy(&(tri_po->pts[1]), *pt2_pi);
    vec2_copy(&(tri_po->pts[2]), *pt3_pi);
}

tri2_t tri2_scale (const tri2_t* tri_pi, const double n_i)
{
    tri2_t tri;
    vec2_t center;
    int i;

    center.x = (tri_pi->pts[0].x + tri_pi->pts[1].x + tri_pi->pts[2].x) / 3.0;
    center.y = (tri_pi->pts[0].y + tri_pi->pts[1].y + tri_pi->pts[2].y) / 3.0;

    for (i = 0; i < 3; ++i) {
        tri.pts[i] = vec2_sum(center, vec2_scale(vec2_diff(tri_pi->pts[i], center), n_i));
    }

    return tri;
}
