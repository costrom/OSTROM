#include "s2sdot.h"
#include "atmos.h"
#include "cylinder.h"
#include "getDrag.h"
#include "getHX.h"
#include "rectPrism.h"
#include "sphere.h"
#include "vectorOps.h"

#include <iostream>
#include <vector>

using namespace std;
static const double mu = 398600.4418;

vector<double> s2sdotS(const vector<double>& state, const sphere& shapeobj)
{
	vector<double> sdot(state.size());
	const double h_melt = state[6] * (shapeobj.cp*shapeobj.Tmelt + shapeobj.hf);
	const double r = norm({ state[0], state[1], state[2] }); // meters
	const double v = norm({ state[3], state[4], state[5] }); // m/s

	sdot[0] = state[3]; //vx
	sdot[1] = state[4]; //vy
	sdot[2] = state[5]; //vz

	const double Qdot = getHXS(state, shapeobj);
	const double d = getDragS(state, shapeobj) / state[6]; // acceleration due to drag
	const double grav = -mu / pow(r/1000.0, 3.0);
	
	const double vxOv = state[3] / v;
	const double vyOv = state[4] / v;
	const double vzOv = state[5] / v;

	sdot[3] = grav*state[0] - d*vxOv;
	sdot[4] = grav*state[1] - d*vyOv;
	sdot[5] = grav*state[2] - d*vzOv;

	(h_melt <= state[7] && Qdot > 0) ? (sdot[6] = -Qdot / shapeobj.hf) : (sdot[6] = 0);
	(h_melt <= state[7]) ? (sdot[7] = sdot[6] * shapeobj.hf) : (sdot[7] = Qdot);
	
	return sdot;
};

vector<double> s2sdotP(const vector<double>& state, const rectPrism& shapeobj)
{
	vector<double> sdot(state.size());
	const double h_melt = state[6] * (shapeobj.cp*shapeobj.Tmelt + shapeobj.hf);
	const double r = norm({ state[0], state[1], state[2] }); // meters
	const double v = norm({ state[3], state[4], state[5] }); // m/s

	sdot[0] = state[3]; //vx
	sdot[1] = state[4]; //vy
	sdot[2] = state[5]; //vz

	const double Qdot = getHXP(state, shapeobj);
	const double d = getDragP(state, shapeobj) / state[6]; // acceleration due to drag, normalized by speed
	const double grav = -mu / pow(r / 1000.0, 3.0);
	
	const double vxOv = state[3] / v;
	const double vyOv = state[4] / v;
	const double vzOv = state[5] / v;

	sdot[3] = grav*state[0] - d*vxOv;
	sdot[4] = grav*state[1] - d*vyOv;
	sdot[5] = grav*state[2] - d*vzOv;

	(h_melt <= state[7] && Qdot > 0) ? (sdot[6] = -Qdot / shapeobj.hf) : (sdot[6] = 0);
	(h_melt <= state[7]) ? (sdot[7] = sdot[6] * shapeobj.hf) : (sdot[7] = Qdot);

	return sdot;
};

vector<double> s2sdotC(const vector<double>& state, const cylinder& shapeobj)
{
	vector<double> sdot(state.size());
	const double h_melt = state[6] * (shapeobj.cp*shapeobj.Tmelt + shapeobj.hf);
	const double r = norm({ state[0], state[1], state[2] }); // meters
	const double v = norm({ state[3], state[4], state[5] }); // m/s

	sdot[0] = state[3]; //vx
	sdot[1] = state[4]; //vy
	sdot[2] = state[5]; //vz

	const double Qdot = getHXC(state, shapeobj);
	const double d = getDragC(state, shapeobj) / state[6]; // acceleration due to drag
	const double grav = -mu / pow(r / 1000.0, 3.0);
	
	const double vxOv = state[3] / v;
	const double vyOv = state[4] / v;
	const double vzOv = state[5] / v;

	sdot[3] = grav*state[0] - d*vxOv;
	sdot[4] = grav*state[1] - d*vyOv;
	sdot[5] = grav*state[2] - d*vzOv;

	(h_melt <= state[7] && Qdot > 0) ? (sdot[6] = -Qdot / shapeobj.hf) : (sdot[6] = 0);
	(h_melt <= state[7]) ? (sdot[7] = sdot[6] * shapeobj.hf) : (sdot[7] = Qdot);

	return sdot;
};