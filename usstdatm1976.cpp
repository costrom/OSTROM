#include "usstdatm1976.h"
#include "usstdatm1976data.h"

#include <cmath>
#include <iostream>
#include <vector>

static const double gamma = 1.4;
static const double R = 287.0;
static const double S = 110.4;
static const double beta = 1.458e-6;

static const unsigned int sz = 100001;

void usstdatm1976(double& h, double& T, double& p, double& rho, double& mu, double& a)
{
    if (h > 1e6)
    {
	h = 1e6;
	};

	if (h < 0)
	{
		h = 0.0;
	};

	unsigned int qq = 0;

	while (qq < (sz - 2) && Altitudes[qq] * 1000.0 < h)
	{
		qq++;
	};

	if (qq >= sz)
	{
		qq = sz - 1;
	};

	if (Altitudes[qq] == h)
	{
		T = Temperatures[qq];
		p = Pressures[qq];
		rho = Densities[qq];
	}
	else
	{
		qq--;
		const double hL = Altitudes[qq] * 1000.0;
		const double hU = Altitudes[qq + 1] * 1000.0;
		const double TL = Temperatures[qq];
		const double TU = Temperatures[qq + 1];
		const double pL = Pressures[qq];
		const double pU = Pressures[qq + 1];
		const double rhoL = Densities[qq];
		const double rhoU = Densities[qq + 1];
		const double ratio = (h - hL) / (hU - hL);

		T = (TU - TL)*ratio + TL;
		p = (pU - pL)*ratio + pL;
		rho = (rhoU - rhoL)*ratio + rhoL;
	};
	mu = beta*pow(T, 1.5) / (T + S);
	a = sqrt(gamma*R*T);
	return;
}
