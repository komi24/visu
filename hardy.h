
#ifndef HARDY_H
#define HARDY_H


#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>
#include <fstream>
#include "Station.h"

static float ComputeMeanValues(std::vector<Station> &stations);
static Vector3f ComptuteHardyCoefficient(std::vector<Station> &stations, float R);

static float ComputeHardyInterpolation(const float longitude, const float latitude,  std::vector<Station> &stations,float R, Vector3f x);
#endif
