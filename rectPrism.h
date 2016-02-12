#ifndef RECTPRISM_H
#define RECTPRISM_H

#include "material.h"
#include "shape.h"
#include <string>

class rectPrism : public shape
{
public:
	double mass, len1, len2, len3, internalEnergy, density;
	double cp, hf, Tmelt, rho;
	const int type = 1;

	rectPrism(const std::string matName, const double& length1, const double& length2, const double& T0)
	{
		material(matName, cp, hf, Tmelt, rho);
		len1 = length1; // side length of ram face
		len2 = length2; // length in ram direction
		len3 = 0; // not used, could be for non-square ram-facing face
		setMass();
		internalEnergy = mass*cp*T0;
		density = rho;
	};

	~rectPrism(){};

	void setMass()
	{
		mass = rho * len1*len1 * len2; // rho * s^3
	};
};

#endif