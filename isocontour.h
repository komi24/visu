#ifndef DEF_ISOCONTOUR
#define DEF_ISOCONTOUR

#include <iostream>
#include "Segment.h"

std::vector<Segment> computeElementary(const float *coorx, const float *coory, const float *val,
    const float step, float(*interp)(float, float));
std::vector<Segment> computeIsoContour(const float xmin, const float xmax,
    const float ymin, const float ymax,
    const float step, float(*interp)(float, float));
#endif
