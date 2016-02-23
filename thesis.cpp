#include "atmos.h"
#include "cylinder.h"
#include "materialsList.h"
#include "rectPrism.h"
#include "rk18.h"
#include "sphere.h"
#include "vectorOps.h"

#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

extern const double pi = 3.141592653589793;
extern const double gamma = 1.4;
extern const double R = 287.0;

vector<double> readCasefile(void)
{
	vector<double> state(8);
	state[0] = 3251500.100388;
	state[1] = 0.0;
	state[2] = -5631763.37468732;
	state[3] = 0.0;
	state[4] = 7825.18308691933;
	state[5] = 0.0;
	state[6];
	state[7];
	return state;
};

void main(int argc, char* argv[])
{
	cout.precision(15);
	const vector<double> state = readCasefile();
	const double T_orbit = 5211.10753786394; // need to change later when "real" casefile used
	const double radius = 0.5;
	const double len1 = 0.5;
	const double len2 = 1.5;
	const double T0 = 300.0;
	const double tf = 50.0*T_orbit;
	double alt;

	string matName;
	string fname;

	for (unsigned int ii = 0; ii < materialsList.size(); ii++)
	{
		matName = materialsList[ii]; 
		fname = matName + ".txt";
		fstream fid;
		fid.open(fname, fstream::out);
		fid.precision(15);
		fid << "Initial State: ";
		for (int ii = 0; ii < 6; ii++)
		{
			fid << "\n" << state[ii];
		};
		double alt0 = norm({ state[0], state[1], state[2] }) - 6378000;
		fid << "\nInitial Altitude (km): " << alt0*0.001;

		sphere sphereobj(matName, radius, radius, T0);
		vector<double> sphere0 = state;
		sphere0[6] = sphereobj.mass;
		sphere0[7] = sphereobj.internalEnergy;

		rectPrism prismobj(matName, len1, len2, T0);
		vector<double> prism0 = state;
		prism0[6] = prismobj.mass;
		prism0[7] = prismobj.internalEnergy;

		cylinder cylobj(matName, radius, len2, T0);
		vector<double> cyl0 = state;
		cyl0[6] = cylobj.mass;
		cyl0[7] = cylobj.internalEnergy;

		vector<double> spheref(sphere0.size());
		vector<double> prismf(sphere0.size());
		vector<double> cylf(sphere0.size());

		system("CLS");
		cout << "\nRunning " << matName << " cases..." << endl;

		rk18S(tf, sphere0, sphereobj, spheref);

		cout << "\nSphere Complete!";

		rk18P(tf, prism0, prismobj, prismf);

		cout << "\nPrism Complete!";
		/*
		rk18C(tf, cyl0, cylobj, cylf);

		cout << "\nCylinder Complete!";
		*/

		cout << "\n" << matName << " complete!" << endl;
		fid << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << matName << ":";
		
		fid << "\n\nSphere:";
		fid << "\nInitial Mass (kg): " << sphere0[6];
		for (int ii = 0; ii < 6; ii++)
		{
			fid << "\n" << spheref[ii];
		};
		alt = norm({ spheref[0], spheref[1], spheref[2] }) - 6378000;
		fid << "\nFinal Altitude (km): " << alt*0.001;
		fid << "\nFinal Mass (kg): " << spheref[6];

		fid << "\n\nPrism:";
		fid << "\nInitial Mass (kg): " << prism0[6];
		for (int ii = 0; ii < 6; ii++)
		{
			fid << "\n" << prismf[ii];
		};
		alt = norm({ prismf[0], prismf[1], prismf[2] }) - 6378000;
		fid << "\nFinal Altitude (km): " << alt*0.001;
		fid << "\nFinal Mass (kg): " << prismf[6];
		
		/*
		cout << "\n\nCylinder:";
		for (int ii = 0; ii < 6; ii++)
		{
		cout << "\n" << cylf[ii];
		};
		alt = norm({ cylf[0], cylf[1], cylf[2] }) - 6378000;
		cout << "\nFinal Altitude (km): " << alt*0.001;
		cout << "\nFinal Mass (kg): " << cylf[6] << endl;
		*/
		fid.close();
	};


	system("PAUSE");

	return;
}

