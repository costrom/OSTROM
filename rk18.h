#ifndef RK18_H
#define RK18_H

#include <vector>
#include "cylinder.h"
#include "rectPrism.h"
#include "sphere.h"

void rk18S(const double& tf, const std::vector<double>& state0, sphere& shapeobj, std::vector<double>& statef);

void rk18P(const double& tf, const std::vector<double>& state0, rectPrism& shapeobj, std::vector<double>& statef);

void rk18C(const double& tf, const std::vector<double>& state0, cylinder& shapeobj, std::vector<double>& statef);

#endif