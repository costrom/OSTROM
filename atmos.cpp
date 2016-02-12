#include "atmos.h"
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

extern vector<double> Altitudes;
extern vector<double> Temperatures;
extern vector<double> Pressures;
extern vector<double> Densities;
extern const double gamma;
extern const double R;
static const double S = 110.4;
static const double beta = 1.458e-6;

extern thread th;
extern bool t_done;

static const unsigned int sz = 100001;

void atmos(double& h, double& T, double& p, double& rho, double& mu, double& a)
{
	if (!t_done)
	{
		th.join();
		t_done = true;
		cout << "\nAtmos loaded!\n";
	};

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
};
