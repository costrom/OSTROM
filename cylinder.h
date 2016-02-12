#ifndef CYLINDER_H
#define CYLINDER_H

#include "material.h"
#include "shape.h"
#include <string>

extern const double pi;

class cylinder: public shape
{
public:
	double mass, len1, len2, len3, internalEnergy, density;
	double cp, hf, Tmelt, rho;
	const int type = 2;

	cylinder(const std::string matName, const double& length1, const double& length2, const double& T0)
	{
		material(matName, cp, hf, Tmelt, rho);
		len1 = length1; // radius
		len2 = length2; // height
		len3 = 0; //not used, could be for an elliptical cylinder
		setMass();
		internalEnergy = mass*cp*T0;
		density = rho;
	};

	~cylinder(){};

	void setMass()
	{
		mass = rho * pi * len1*len1 * len2; // rho * pi * r^2 * h
	};
};

#endif