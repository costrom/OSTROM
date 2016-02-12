#ifndef SPHERE_H
#define SPHERE_H

#include "material.h"
#include "shape.h"
#include <string>

extern const double pi;

class sphere: public shape
{
public:
	double mass, len1, len2, len3, internalEnergy;
	double cp, hf, Tmelt, rho;
	const int type = 0;

	sphere(const std::string matName, const double& length1, const double& length2, const double& T0)
	{
		material(matName, cp, hf, Tmelt, rho);
		setLen1(length1); // radius
		len2 = length2; // not used now, could be implemented for a oblate spheroid
		len3 = 0; // not used, could be implemented for an ellipsoid
		setMass();
		setIntEnergy(mass*cp*T0);
	};

	void setLen1(double newlen1)
	{
		len1 = newlen1;
		setMass();
	};

	void setIntEnergy(double newenergy)
	{
		internalEnergy = newenergy;
	};

	~sphere(){};

	void setMass()
	{
		mass = rho * 4.0/3.0 * pi * len1*len1*len1; // rho * 4/3 * pi *r^3
	};

};

#endif