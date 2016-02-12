#ifndef GETDRAG_H
#define GETDRAG_H

#include <vector>
#include "cylinder.h"
#include "rectPrism.h"
#include "sphere.h"

double getDragS(const std::vector<double>& state, const sphere& shapeobj);

double getDragP(const std::vector<double>& state, const rectPrism& shapeobj);

double getDragC(const std::vector<double>& state, const cylinder& shapeobj);

#endif

