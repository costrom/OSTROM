#ifndef VECTOROPS_H
#define VECTOROPS_H

#include <vector>

std::vector<double> addArrays(const std::vector<double> A, const std::vector<double> B);

std::vector<double> multArrays(const std::vector<double> A, const double scalarMult);

std::vector<double> operator+(const std::vector<double>& A, const std::vector<double>& B);

std::vector<double> operator*(const std::vector<double>& A, const double& c);

std::vector<double> operator*(const double& c, const std::vector<double>& A);

double calcerr(const std::vector<double>& A, const std::vector<double>& B);

std::vector<double> inputVecCalc(const double& h, const std::vector<std::vector<double>>& f, const std::vector<std::vector<double>>& betaKL, const unsigned int& k, const std::vector<double>& x0);

void fillbetaKL(std::vector<std::vector<double>>& betaKL);

std::vector<double> cross(const std::vector<double>& A, const std::vector<double>& B);

double norm(const std::vector<double>& A);

double dot(const std::vector<double> A, const std::vector<double>& B);

#endif