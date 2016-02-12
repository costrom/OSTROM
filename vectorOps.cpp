#include "vectorOps.h"

std::vector<double> addArrays(const std::vector<double> A, const std::vector<double> B)
{
	std::vector<double> C(A.size());
	for (unsigned int ii = 0; ii < A.size(); ii++)
	{
		C[ii] = A[ii] + B[ii];
	};
	return C;
}

std::vector<double> multArrays(const std::vector<double> A, const double scalarMult)
{
	std::vector<double> C(A.size());
	for (unsigned int ii = 0; ii < A.size(); ii++)
	{
		C[ii] = A[ii] * scalarMult;
	};
	return C;
}

std::vector<double> operator+(const std::vector<double>& A, const std::vector<double>& B)
{
	return addArrays(A, B);
};

std::vector<double> operator*(const std::vector<double>& A, const double& c)
{
	return multArrays(A, c);
};

std::vector<double> operator*(const double& c, const std::vector<double>& A)
{
	return multArrays(A, c);
};

double calcerr(const std::vector<double>& A, const std::vector<double>& B)
{
	double c = -1.0;
	double d;
	for (unsigned int ii = 0; ii < A.size(); ii++)
	{
		d = abs(A[ii] - B[ii]) / abs(A[ii]);
		if (d > c)
		{
			c = d;
		};
	};
	return c;
};

std::vector<double> inputVecCalc(const double& h, const std::vector<std::vector<double>>& f, const std::vector<std::vector<double>>& betaKL, const unsigned int& k, const std::vector<double>& x0)
{
	std::vector<double> time0(f[0].size(), 0);
	std::vector<double> time1(f[0].size(), 0);
	unsigned int lambda;
	if (k >= 1)
	{
		for (lambda = 0; lambda < k; lambda++)
		{
			time1 = f[lambda]*betaKL[k][lambda];
			time0 = time0 + time1;
		};

		time0 = time0*h;
	};

	return time0+x0;
};

void fillbetaKL(std::vector<std::vector<double>>& betaKL)
{
	betaKL[0] = { 0.0 };
	betaKL[1] = { 2.0 / 27.0 };
	betaKL[2] = { 1.0 / 36.0, 1.0 / 12.0 };
	betaKL[3] = { 1.0 / 24.0, 0.0, 1.0 / 8.0 };
	betaKL[4] = { 5.0 / 12., 0.0, -25.0 / 16.0, 25.0 / 16.0 };
	betaKL[5] = { 1.0 / 20., 0.0, 0.0, 1.0 / 4.0, 1.0 / 5.0 };
	betaKL[6] = { -25.0 / 108.0, 0.0, 0, 125.0 / 108., -65.0 / 27., 125.0 / 54.0 };
	betaKL[7] = { 31.0 / 300.0, 0.0, 0, 0, 61.0 / 225., -2.0 / 9., 13.0 / 900.0 };
	betaKL[8] = { 2.0, 0.0, 0.0, -53.0 / 6., 704.0 / 45., -107.0 / 9., 67.0 / 90., 3.0 };
	betaKL[9] = { -91.0 / 108.0, 0.0, 0.0, 23.0 / 108., -976.0 / 135., 311.0 / 54., -19.0 / 60., 17.0 / 6., -1.0 / 12.0 };
	betaKL[10] = { 2383.0 / 4100.0, 0.0, 0.0, -341.0 / 164., 4496.0 / 1025., -301.0 / 82., 2133.0 / 4100., 45.0 / 82, 45.0 / 164., 18.0 / 41.0 };
	betaKL[11] = { 3.0 / 205.0, 0.0, 0.0, 0.0, 0.0, -6.0 / 41., -3.0 / 205., -3.0 / 41., 3.0 / 41., 6.0 / 41., 0 };
	betaKL[12] = { -1777.0 / 4100.0, 0.0, 0.0, -341.0 / 164., 4496.0 / 1025., -289.0 / 82., 2193.0 / 4100., 51.0 / 82., 33.0 / 164., 12.0 / 41., 0, 1 };
}

std::vector<double> cross(const std::vector<double>& A, const std::vector<double>& B)
{
	std::vector<double> c(3);
	c[0] = A[1] * B[2] - B[1] * A[2];
	c[1] = -(A[0] * B[2] - B[0] * A[2]);
	c[2] = A[0] * B[1] - B[0] * A[1];
	return c;
}

double dot(const std::vector<double>& A, const std::vector<double>& B)
{
	double val = 0;
	for (auto qq = 0; qq < A.size(); qq++)
	{
		val += A[qq] * B[qq];
	};
	return val;
}

double norm(const std::vector<double>& A)
{
	double aNorm = 0;
	for (unsigned int ii = 0; ii < A.size(); ii++)
	{
		aNorm += A[ii] * A[ii];
	};
	return sqrt(aNorm);
}