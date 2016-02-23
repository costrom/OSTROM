#include "getDrag.h"
#include "atmos.h"
#include "cylinder.h"
#include "rectPrism.h"
#include "sphere.h"
#include "vectorOps.h"

#include "atmprops.h"

#include <cmath>
#include <vector>

using namespace std;
static const long double kb = 1.380648813e-23L; // Boltzmann constant	
static const double fact = 2.71877E-05;

extern const double pi;
extern const double gamma;
extern const double R;

double po2_po1(const double& M1)
{
	if (M1 > 1)
	{
		const double num1 = 1.2*M1*M1;
		const double den1 = 1.0 + 0.20*M1*M1;
		const double num2 = 1.0;
		const double den2 = 2.8 / 2.4*M1*M1 - 0.4 / 2.4;
		const double term1 = pow((num1 / den1), 3.5);
		const double term2 = pow((num2 / den2), 2.5);
		return term1*term2;
	}
	else
	{
		return 1.0;
	};
};

double po_p(const double& M1)
{
	return pow(1.0 + 0.2*M1*M1, 3.5);
};

double transition(const double& Cdc, const double& Cdfm, const double& Kn)
{
	return Cdc + (Cdfm - Cdc)*log10(1000.0*Kn) / 5.0;
};

double getDragS(const vector<double>& state, const sphere& shapeobj)
{
	static const double radius = shapeobj.len1;

	double alt = norm({ state[0], state[1], state[2] }) - 6378000; // meters
	const double v = norm({ state[3], state[4], state[5] }); // m/s
	double T, p, rho, mu, a, CD;
	atmprops atmProperties(1);

	atmos(atmProperties);

	double q = 0.5*rho*v*v;
	double M_inf = v / a;
	double Kn = fact * T / (p * radius);
	double ps = po2_po1(M_inf)*po_p(M_inf)*p;
	double cps = (ps - p) / (q);

	const double S = pi * radius*radius;
	if (Kn > 1)
	{
		CD = 2.10;
	}
	else if (Kn > 0.01)
	{
		const double CDc = cps*0.5;
		static const double CDfm = 2.10;
		CD = transition(CDc, CDfm, Kn);
	}
	else
	{
		CD = cps*0.5;
	};

	return CD * q * S;
};

double getDragP(const vector<double>& state, const rectPrism& shapeobj)
{
	double alt = sqrt(state[0] * state[0] + state[1] * state[1] + state[2] * state[2]) - 6378000; // meters
	const double v = sqrt(state[3] * state[3] + state[4] * state[4] + state[5] * state[5]); // m/s
	double T, p, rho, mu, a, CD;
	atmprops atmProperties(1);

	atmos(atmProperties);
	const double q = 0.5*rho*v*v;
	const double M_inf = v / a;
	const double Kn = fact * T / (p * shapeobj.len2);
	const double ps = po2_po1(M_inf)*po_p(M_inf)*p;
	const double cps = (ps - p) / (q);

	const double S = shapeobj.len1*shapeobj.len1;
	if (Kn > 1)
	{
		CD = 2.15;
	}
	else if (Kn > 0.01)
	{
		const double CDc = cps;
		static const double CDfm = 2.15;
		CD = transition(CDc, CDfm, Kn);
	}
	else
	{
		CD = cps;
	};

	return CD * q * S;
};

double getDragC(const vector<double>& state, const cylinder& shapeobj)
{
	double alt = norm({ state[0], state[1], state[2] }) - 6378000; // meters
	const double v = norm({ state[3], state[4], state[5] }); // m/s // m/s
	double T, p, rho, mu, a, CD;
	atmprops atmProperties(1);

	atmos(atmProperties);
	const double q = 0.5*rho*v*v;
	const double M_inf = v / a;
	const double Kn = fact * T / (p * shapeobj.len2);
	const double ps = po2_po1(M_inf)*po_p(M_inf)*p;
	const double cps = (ps - p) / q;
	
	const double radius = shapeobj.len1;

	const double S = pi * radius*radius;
	if (Kn > 1)
	{
		CD = 3.06;
	}
	else if (Kn > 0.01)
	{
		const double CDc = cps;
		static const double CDfm = 3.06;
		CD = transition(CDc, CDfm, Kn);
	}
	else
	{
		CD = cps;
	};

	return CD * q * S;
};