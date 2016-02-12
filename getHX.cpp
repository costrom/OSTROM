#include "getHX.h"

#include "atmos.h"
#include "cylinder.h"
#include "rectPrism.h"
#include "sphere.h"
#include "vectorOps.h"

#include <iostream>
#include <vector>

using namespace std;
static const double sigma = 5.67036713e-8; // Stefan-Boltzmann constant
static const double eps = 0.43808139; // emissivity, geometric mean of many materials

extern const double pi;
extern const double gamma;
extern const double R;

double getHXS(const vector<double>& state, const sphere& shapeobj)
{
	double alt, v, Qdot, S;
	double p, T, rho, mu, a;
	const double radius = shapeobj.len1;
	const double C = 0.000183;

	alt = norm({ state[0], state[1], state[2] }) - 6378000; // meters above spherical earth
	v = norm({ state[3], state[4], state[5] }); // m/s

	atmos(alt, T, p, rho, mu, a);
	
	const double qs = C * sqrt(rho / radius) * v*v*v;
	Qdot = 0.674456486133287L * qs;
	S = 4 * pi * radius*radius;

	const double Tbody = state[7] / (shapeobj.mass*shapeobj.cp);
	const double radout = pow(Tbody, 4.0);
	const double radin = pow(300.0, 4.0); //replace with surface temperature

	const double Qradout = eps*sigma*( radout - radin );
	const double Qnet = (Qdot - Qradout) * S;
	
	return Qnet;
};

double getHXP(const vector<double>& state, const rectPrism& shapeobj)
{
	const long double Ch = 0.349872023242161L;
	double alt, v, q, Qdot, S;
	double p, T, rho, mu, a;
	const double side = shapeobj.len1;
	alt = sqrt(state[0] * state[0] + state[1] * state[1] + state[2] * state[2]) - 6378000;
	v = sqrt(state[3] * state[3] + state[4] * state[4] + state[5] * state[5]);

	atmos(alt, T, p, rho, mu, a);

	q = 0.5 * Ch* rho * v*v*v;
	S = 2 * side*side + 4 * side * shapeobj.len2;
	Qdot = q * side*side;

	const double Tbody = state[7] / (shapeobj.mass*shapeobj.cp);
	const double radout = pow(Tbody, 4.0);
	const double radin = pow(300.0, 4.0); //replace with surface temperature

	const double Qradout = eps*sigma*(radout - radin);
	const double Qnet = (Qdot - Qradout) * S;

	return Qnet;
};

double getHXC(const vector<double>& state, const cylinder& shapeobj)
{
	double alt, v, q, Qdot, S;
	alt = norm({ state[0], state[1], state[2] }) - 6378000; // meters above spherical earth
	v = norm({ state[3], state[4], state[5] }); // m/s

	double p, T, rho, mu, a;
	atmos(alt, T, p, rho, mu, a);

	const double radius = shapeobj.len1;
	const long double Ch = 0.347281189736511L;
	q = 0.5 * Ch * v*v*v;
	S = 2 * pi * radius * radius + 2 * pi*radius*shapeobj.len2;
	Qdot = q * pi * radius * radius;

	const double Tbody = state[7] / (shapeobj.mass*shapeobj.cp);
	const double radout = pow(Tbody, 4.0);
	const double radin = pow(300.0, 4.0); //replace with surface temperature

	const double Qradout = eps*sigma*(radout - radin);
	const double Qnet = (Qdot - Qradout) * S;

	return Qnet;
};