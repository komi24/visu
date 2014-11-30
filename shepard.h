
#ifndef SHEPARD_H
#define SHEPARD_H


#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>
#include <fstream>
#include "Station.h"

static float ComputeShepardInterpolation(const float longitude, const float lattitude,  std::list<Station> &stations);


#endif
