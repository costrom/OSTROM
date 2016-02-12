#ifndef S2SDOT_H
#define S2SDOT_H

#include <vector>
#include "cylinder.h"
#include "rectPrism.h"
#include "sphere.h"

std::vector<double> s2sdotS(const std::vector<double>& state, const sphere& shapeobj);

std::vector<double> s2sdotP(const std::vector<double>& state, const rectPrism& shapeobj);

std::vector<double> s2sdotC(const std::vector<double>& state, const cylinder& shapeobj);

#endif