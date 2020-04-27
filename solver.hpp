/*
 * solver.hpp
 *
 *  Created on: 28 April 2020
 *      Author: oriel malihi
 */

#ifndef SOLVER_HPP_
#define SOLVER_HPP_

#include <string>
#include <complex>
using namespace std;

namespace solver
{

class RealVariable
{
private:
    double coef_2;
    double coef_1;
    double coef_0;

public:
    RealVariable() : coef_2(0),
                     coef_1(1),
                     coef_0(0) {}

    friend RealVariable &operator*(double mul, RealVariable expr);
    RealVariable &operator^(double mul);
    RealVariable &operator+(double plus);
    RealVariable &operator+(RealVariable expr);
    RealVariable &operator-(double minus);
    RealVariable &operator-(RealVariable expr);
    RealVariable &operator==(double num);
    RealVariable &operator==(RealVariable expr);
};

class ComplexVariable
{
private:
    double coef_2;
    double coef_1;
    double coef_0;
    complex<double> comp = 0 + 0i;

public:
    ComplexVariable() : coef_2(0),
                        coef_1(0),
                        coef_0(0) {}

    friend ComplexVariable &operator*(double mul, ComplexVariable expr);
    ComplexVariable &operator^(double mul);
    ComplexVariable &operator+(double plus);
    ComplexVariable &operator+(ComplexVariable expr);
    ComplexVariable &operator+(complex<double> expr);
    ComplexVariable &operator-(complex<double> expr);
    ComplexVariable &operator-(double minus);
    ComplexVariable &operator-(ComplexVariable expr);
    ComplexVariable &operator==(double num);
    ComplexVariable &operator==(ComplexVariable expr);
};

double solve(RealVariable expr);
complex<double> &solve(ComplexVariable expr);
} // namespace solver

#endif /* SOLVER_HPP_ */