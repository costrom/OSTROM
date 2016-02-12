#ifndef SHAPE_H
#define SHAPE_H

class shape
{
public:
	double mass, len1, len2, len3, internalEnergy, density;
	double cp, hf, Tmelt, rho;
	const int type = 0;
};

#endif