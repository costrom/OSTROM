#ifndef GETHX_H
#define GETHX_H

#include <vector>
#include "cylinder.h"
#include "rectPrism.h"
#include "sphere.h"

double getHXS(const std::vector<double>& state, const sphere& shapeobj);

double getHXP(const std::vector<double>& state, const rectPrism& shapeobj);

double getHXC(const std::vector<double>& state, const cylinder& shapeobj);

#endif