#include "rk18.h"
#include "cylinder.h"
#include "rectPrism.h"
#include "s2sdot.h"
#include "sphere.h"
#include "vectorOps.h"

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

static const double rE = 6378000.0;
static vector<vector<double>> betaKL(13);
static const vector<double> alpha = { 0.0, 2.0 / 27.0, 1.0 / 9.0, 1.0 / 6.0, 5.0 / 12.0, 1.0 / 2.0, 5.0 / 6.0, 1.0 / 6.0, 2.0 / 3.0, 1.0 / 3.0, 1.0, 0.0, 1.0 };
static const vector<double> chat = { 0.0, 0.0, 0.0, 0.0, 0.0, 34.0 / 105.0, 9.0 / 35.0, 9.0 / 35.0, 9.0 / 280.0, 9.0 / 280.0, 0.0, 41.0 / 840.0, 41.0 / 840.0 };

void rk18S(const double& tf, const vector<double>& S, sphere& shapeobj, std::vector<double>& statef)
{
	cout << "\nSphere Started";
	cout.precision(6);
	fillbetaKL(betaKL);
	double h = 5.0;
	const double hmin = 0.01;
	double t = 0.0;
	double err = 5;
	const double eMax = 1e-7;
	const double eMin = eMax*1e-3;
	unsigned int nSteps = 0;
	const size_t vecSize = S.size();
	vector<double> Y0 = S, y(vecSize), yhat(vecSize), Y(vecSize), Yhat(vecSize);
	vector<double> inputVec, fkchatk;
	double nits = 0;
	
	vector<vector<double>> f (13);
	for (unsigned int ii = 0; ii <= 12; ii++)
	{
		f[ii].resize(vecSize);
	};

	double r = norm({ Y0[0], Y0[1], Y0[2] });

	while (t < tf && r > rE && Y0[6] > 0 && r < (rE+2e5))
	{
		if (err < eMax) {
			if (Y0[6] + yhat[6] < -0.001)
			{
				h *= 0.5;
				nits++;
				err = eMax *2.0;
			}
			else
			{
				Y0 = Yhat;
				r = norm({ Y0[0], Y0[1], Y0[2] });
				if (t + h > tf)
				{
					h = tf - t;
					t = tf;
				}
				else if (t == tf) {
					break;
				}
				else {
					t += h;
				};

				if (err < eMin)
				{
					h *= pow(eMin / err, 1.0 / 9.0);
				}
				else
				{
					h *= pow(eMax / err, 1.0 / 9.0);
				};
				
				if (nSteps % 200 == 0)
				{
					cout << "\n\t" << nSteps << " , " << 0.001*(r-rE) << " km";
				};

				nSteps++;
				nits = 1;
				//shapeobj.setLen1(pow(shapeobj.mass / (shapeobj.density*4.0*pi / 3.0), (1.0 / 3.0)));
				//shapeobj.setIntEnergy(Y0[7]);
			};
		}
		else
		{
			nits++;
			h *= pow(eMax / err, 1.0 / 9.0);
		};

		std::fill(y.begin(), y.end(), 0);
		std::fill(yhat.begin(), yhat.end(), 0);

		for (int k = 0; k <= 12; k++)
		{
			inputVec = inputVecCalc(h, f, betaKL, k, Y0);
			f[k] = s2sdotS(inputVec, shapeobj); // row vector for each f_k
			fkchatk = f[k] * chat[k];
			yhat = yhat + fkchatk;
		};

		y = f[0] * h;
		yhat = yhat * h;
		Y = Y0 + y;
		Yhat = Y0 + yhat;
		err = calcerr(Yhat, Y);
	};
	statef = Yhat;
};

void rk18P(const double& tf, const vector<double>& S, rectPrism& shapeobj, std::vector<double>& statef)
{
	cout << "\nPrism Started";
	cout.precision(15);
	fillbetaKL(betaKL);
	double h = 5.0;
	const double hmin = 0.01;
	double t = 0.0;
	double err = 5;
	const double eMax = 1e-4;
	const double eMin = eMax*1e-2;
	unsigned int nSteps = 0;
	const size_t vecSize = S.size();
	vector<double> Y0 = S, y(vecSize), yhat(vecSize), Y(vecSize), Yhat(vecSize);
	vector<double> inputVec, fkchatk;
	double nits = 0;

	vector<vector<double>> f(13);
	for (unsigned int ii = 0; ii <= 12; ii++)
	{
		f[ii].resize(vecSize);
	};

	double r = norm({ Y0[0], Y0[1], Y0[2] });

	while (t < tf && r > rE && Y0[6] > 0 && r < (rE + 2e5))
	{
		if (err < eMax) {
			if (Y0[6] + yhat[6] < -0.001)
			{
				h *= 0.5;
				nits++;
				err = eMax *2.0;
			}
			else
			{
				Y0 = Yhat;
				r = norm({ Y0[0], Y0[1], Y0[2] });
				if (t + h > tf)
				{
					h = tf - t;
					t = tf;
				}
				else if (t == tf) {
					break;
				}
				else {
					t += h;
				};

				if (err < eMin)
				{
					h *= pow(eMin / err, 1.0 / 9.0);
				}
				else
				{
					h *= pow(eMax / err, 1.0 / 9.0);
				};

				if (nSteps % 100 == 0 && nSteps > 0)
				{
					cout << "\n\t" << nSteps;
				};

				nSteps++;
				nits = 1;
				//shapeobj.setLen1(pow(shapeobj.mass / (shapeobj.density*4.0*pi / 3.0), (1.0 / 3.0)));
				//shapeobj.setIntEnergy(Y0[7]);
			};
		}
		else
		{
			nits++;
			h *= pow(eMax / err, 1.0 / 9.0);
		};

		std::fill(y.begin(), y.end(), 0);
		std::fill(yhat.begin(), yhat.end(), 0);

		for (int k = 0; k <= 12; k++)
		{
			inputVec = inputVecCalc(h, f, betaKL, k, Y0);
			f[k] = s2sdotP(inputVec, shapeobj); // row vector for each f_k
			fkchatk = f[k] * chat[k];
			yhat = yhat + fkchatk;
		};

		y = f[0] * h;
		yhat = yhat * h;
		Y = Y0 + y;
		Yhat = Y0 + yhat;
		err = calcerr(Yhat, Y);
	};
	statef = Yhat;
};

void rk18C(const double& tf, const vector<double>& S, cylinder& shapeobj, std::vector<double>& statef)
{
	cout << "\nCylinder Started";
	cout.precision(15);
	fillbetaKL(betaKL);
	double h = 5.0;
	const double hmin = 0.01;
	double t = 0.0;
	double err = 5;
	const double eMax = 1e-7;
	const double eMin = eMax*1e-3;
	unsigned int nSteps = 0;
	const size_t vecSize = S.size();
	vector<double> Y0 = S, y(vecSize), yhat(vecSize), Y(vecSize), Yhat(vecSize);
	vector<double> inputVec, fkchatk;
	double nits = 0;

	vector<vector<double>> f(13);
	for (unsigned int ii = 0; ii <= 12; ii++)
	{
		f[ii].resize(vecSize);
	};

	double r = norm({ Y0[0], Y0[1], Y0[2] });

	while (t < tf && r > rE && Y0[6] > 0 && r < (rE + 2e5))
	{
		std::fill(y.begin(), y.end(), 0);
		std::fill(yhat.begin(), yhat.end(), 0);

		for (int k = 0; k <= 12; k++)
		{
			inputVec = inputVecCalc(h, f, betaKL, k, Y0);
			f[k] = s2sdotC(inputVec, shapeobj); // row vector for each f_k
			fkchatk = f[k] * chat[k];
			yhat = yhat + fkchatk;
		};

		y = f[0] * h;
		yhat = yhat * h;
		Y = Y0 + y;
		Yhat = Y0 + yhat;
		err = calcerr(Yhat, Y);

		if (err < eMax) {
			if (Y0[6] + yhat[6] < -0.001)
			{
				h *= 0.5;
				nits++;
				err = eMax *2.0;
			}
			else
			{
				Y0 = Yhat;
				r = norm({ Y0[0], Y0[1], Y0[2] });
				if (t + h > tf)
				{
					h = tf - t;
					t = tf;
				}
				else if (t == tf) {
					break;
				}
				else {
					t += h;
				};

				if (err < eMin)
				{
					h *= pow(eMin / err, 1.0 / 9.0);
				}
				else
				{
					h *= pow(eMax / err, 1.0 / 9.0);
				};

				cout << "\n\t" << nSteps;
				cout << "\n" << (norm({ Y0[0], Y0[1], Y0[2] })-rE)*0.001;

				nSteps++;
				nits = 1;
				//shapeobj.setLen1(pow(shapeobj.mass / (shapeobj.density*4.0*pi / 3.0), (1.0 / 3.0)));
				//shapeobj.setIntEnergy(Y0[7]);
			};
		}
		else
		{
			nits++;
			h *= pow(eMax / err, 1.0 / 9.0);
		};
	};
	statef = Yhat;
};
