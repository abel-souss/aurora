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

tri2_t tri2_move (const tri2_t* tri_pi, const vec2_t* vec_pi)
{
    tri2_t tri;
    int i;

    for (i = 0; i < 3; ++i) {
        tri.pts[i] = vec2_sum(tri_pi->pts[i], *vec_pi);
    }

    return tri;
}

double tri2_perimeter (const tri2_t* tri_pi)
{
    double sides[3];

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    return sides[0] + sides[1] + sides[2];
}

double tri2_area (const tri2_t* tri_pi)
{
    double sides[3];
    double s;

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    s = (sides[0] + sides[1] + sides[2]) / 2.0;

    return math_sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
}

tri2_t tri2_rotate_deg (const tri2_t* tri_pi, const vec2_t* org_i, const double r)
{
    double a = math_deg_to_rad(r);
    double cosa = math_cos_rad(a);
    double sina = math_sin_rad(a);
    tri2_t tri;
    int i = 0;

    if (org_i != NULL) {
        for (i = 0; i < 3; ++i) {
            tri.pts[i] = vec2_diff(tri_pi->pts[i], *org_i);
            tri.pts[i] = vec2_new(cosa * tri.pts[i].x - sina * tri.pts[i].y, sina * tri.pts[i].x + cosa * tri.pts[i].y);
            tri.pts[i] = vec2_sum(tri.pts[i], *org_i);
        }
    } else {
        for (i = 0; i < 3; ++i) {
            tri.pts[i] = vec2_new(cosa * tri_pi->pts[i].x - sina * tri_pi->pts[i].y, sina * tri_pi->pts[i].x + cosa * tri_pi->pts[i].y);
        }
    }

    return tri;
}

tri2_t tri2_rotate_rad (const tri2_t* tri_pi, const vec2_t* org_i, const double r)
{
    double a = r;
    double cosa = math_cos_rad(a);
    double sina = math_sin_rad(a);
    tri2_t tri;
    int i = 0;

    if (org_i != NULL) {
        for (i = 0; i < 3; ++i) {
            tri.pts[i] = vec2_diff(tri_pi->pts[i], *org_i);
            tri.pts[i] = vec2_new(cosa * tri.pts[i].x - sina * tri.pts[i].y, sina * tri.pts[i].x + cosa * tri.pts[i].y);
            tri.pts[i] = vec2_sum(tri.pts[i], *org_i);
        }
    } else {
        for (i = 0; i < 3; ++i) {
            tri.pts[i] = vec2_new(cosa * tri_pi->pts[i].x - sina * tri_pi->pts[i].y, sina * tri_pi->pts[i].x + cosa * tri_pi->pts[i].y);
        }
    }

    return tri;
}

tri2_t tri2_rotate_orthogonal (const tri2_t* tri_pi, const vec2_t* org_i, const int direct)
{
    tri2_t tri;
    int i = 0;

    if (direct) {
        if (org_i != NULL) {
            for (i = 0; i < 3; ++i) {
                tri.pts[i] = vec2_diff(tri_pi->pts[i], *org_i);
                tri.pts[i] = vec2_new(-1.0 * tri.pts[i].y, tri.pts[i].x);
                tri.pts[i] = vec2_sum(tri.pts[i], *org_i);
            }

        } else {
            for (i = 0; i < 3; ++i) {
                tri.pts[i] = vec2_new(-1.0 * tri_pi->pts[i].y, tri_pi->pts[i].x);
            }
        }
    } else {
        if (org_i != NULL) {
            for (i = 0; i < 3; ++i) {
                tri.pts[i] = vec2_diff(tri_pi->pts[i], *org_i);
                tri.pts[i] = vec2_new(tri.pts[i].y, -1.0 * tri.pts[i].x);
                tri.pts[i] = vec2_sum(tri.pts[i], *org_i);
            }
        } else {
            for (i = 0; i < 3; ++i) {
                tri.pts[i] = vec2_new(tri_pi->pts[i].y, -1.0 * tri_pi->pts[i].x);
            }
        }
    }

    return tri;
}

tri2_t tri2_rotate_opposite (const tri2_t* tri_pi, const vec2_t* org_i)
{
    tri2_t tri;
    int i = 0;

    if (org_i != NULL) {
        for (i = 0; i < 3; ++i) {
            tri.pts[i] = vec2_diff(tri_pi->pts[i], *org_i);
            tri.pts[i].x = -1.0 * tri.pts[i].x;
            tri.pts[i].y = -1.0 * tri.pts[i].y;
            tri.pts[i] = vec2_sum(tri.pts[i], *org_i);
        }
    } else {
        tri.pts[i].x = -1.0 * tri_pi->pts[i].x;
        tri.pts[i].y = -1.0 * tri_pi->pts[i].y;
    }

    return tri;
}

int tri2_is_valid (const tri2_t* tri_pi)
{
    double sides[3];

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    return ((sides[0] + sides[1]) > sides[2]) &&
           ((sides[0] + sides[2]) > sides[1]) &&
           ((sides[1] + sides[2]) > sides[0]);
}

int tri2_is_right (const tri2_t* tri_pi)
{
    double sides[3];

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    sides[0] *= sides[0];
    sides[1] *= sides[1];
    sides[2] *= sides[2];

    return ((sides[0] + sides[1]) == sides[2]) ||
           ((sides[0] + sides[2]) == sides[1]) ||
           ((sides[1] + sides[2]) == sides[0]);
}

int tri2_is_equilateral (const tri2_t* tri_pi)
{
    double sides[3];

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    return (sides[0] == sides[1]) && (sides[0] == sides[2]);
}

int tri2_is_isosceles (const tri2_t* tri_pi)
{
    double sides[3];

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    return (sides[0] == sides[1]) ||
           (sides[0] == sides[2]) ||
           (sides[1] == sides[2]);
}

int tri2_is_scalene (const tri2_t* tri_pi)
{
    double sides[3];

    sides[0] = vec2_distance(tri_pi->pts[0], tri_pi->pts[1]);
    sides[1] = vec2_distance(tri_pi->pts[1], tri_pi->pts[2]);
    sides[2] = vec2_distance(tri_pi->pts[2], tri_pi->pts[0]);

    return (sides[0] != sides[1]) &&
           (sides[0] != sides[2]) &&
           (sides[1] != sides[2]);
}

int tri2_is_congruent (const tri2_t* tri1_pi, const tri2_t* tri2_pi)
{
    double sides1[3], sides2[3];
    int i, j, idx1, idx2;
    int congruent;

    sides1[0] = vec2_distance(tri1_pi->pts[0], tri1_pi->pts[1]);
    sides1[1] = vec2_distance(tri1_pi->pts[1], tri1_pi->pts[2]);
    sides1[2] = vec2_distance(tri1_pi->pts[2], tri1_pi->pts[0]);

    sides2[0] = vec2_distance(tri2_pi->pts[0], tri2_pi->pts[1]);
    sides2[1] = vec2_distance(tri2_pi->pts[1], tri2_pi->pts[2]);
    sides2[2] = vec2_distance(tri2_pi->pts[2], tri2_pi->pts[0]);

    congruent = 0;

    for (i = 0; i < 3; ++i) {
        if (sides1[0] == sides2[i]) {
            congruent = 1;
            idx1 = i;
            break;
        }
    }

    if (!congruent) {
        return 0;
    }

    congruent = 0;

    for (i = 0; i < 3, i != idx1; ++i) {
        if (sides1[1] == sides2[i]) {
            congruent = 1;
            idx2 = i;
            break;
        }
    }

    if (!congruent) {
        return 0;
    }

    congruent = 0;

    for (i = 0; i < 3, i != idx1, i != idx2; ++i) {
        if (sides1[2] == sides2[i]) {
            congruent = 1;
            break;
        }
    }

    return congruent;
}

int tri2_is_similar (const tri2_t* tri1_pi, const tri2_t* tri2_pi)
{
    double sides1[3], sides2[3];
    double ratios[9];
    int i, j;

    sides1[0] = vec2_distance(tri1_pi->pts[0], tri1_pi->pts[1]);
    sides1[1] = vec2_distance(tri1_pi->pts[1], tri1_pi->pts[2]);
    sides1[2] = vec2_distance(tri1_pi->pts[2], tri1_pi->pts[0]);

    sides2[0] = vec2_distance(tri2_pi->pts[0], tri2_pi->pts[1]);
    sides2[1] = vec2_distance(tri2_pi->pts[1], tri2_pi->pts[2]);
    sides2[2] = vec2_distance(tri2_pi->pts[2], tri2_pi->pts[0]);

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            ratios[(3 * i) + j] = sides1[i] / sides2[j];
        }
    }

    if ((ratios[0] == ratios[4] == ratios[8])
        || (ratios[0] == ratios[5] == ratios[7])
        || (ratios[1] == ratios[3] == ratios[8])
        || (ratios[1] == ratios[5] == ratios[6])
        || (ratios[2] == ratios[3] == ratios[7])
        || (ratios[2] == ratios[4] == ratios[6])) {
        return 1;
    }

    return 0;
}
