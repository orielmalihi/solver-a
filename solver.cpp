/*
 * solver.cpp
 *
 *  Created on: 28 April 2020
 *      Author: oriel malihi
 */
#include <string>
#include <iostream>
#include "solver.hpp"
using namespace std;

namespace solver
{

friend RealVariable &operator*(double mul, RealVariable expr)
{
    expr.coef_2 *= mul;
    expr.coef_1 *= mul;
    expr.coef_0 *= mul;
    return expr;
}
RealVariable &RealVariable::operator^(double mul)
{
    coef_2 = coef_1 * coef_1;
    coef_1 = 0;
    coef_0 *= coef_0;
    return *this;
}
RealVariable &RealVariable::operator+(double plus)
{
    coef_0 += plus;
    return *this;
}
RealVariable &RealVariable::operator+(RealVariable expr)
{
    coef_0 += expr.coef_0;
    coef_1 += expr.coef_1;
    coef_2 += expr.coef_2;
    return *this;
}
RealVariable &RealVariable::operator-(double minus)
{
    return this->operator+(-1 * minus);
}
RealVariable &RealVariable::operator-(RealVariable expr)
{
    coef_0 -= expr.coef_0;
    coef_1 -= expr.coef_1;
    coef_2 -= expr.coef_2;
    return *this;
}
RealVariable &RealVariable::operator==(double num)
{
    return -(num);
}
RealVariable &RealVariable::operator==(RealVariable expr)
{
    return -(expr);
}
//**********************************************************************************
// ***************************** ComplexVariable ***********************************
//**********************************************************************************

friend ComplexVariable &ComplexVariable::operator*(double mul, ComplexVariable expr)
{

}
ComplexVariable &ComplexVariable::operator^(double mul)
{

}
ComplexVariable &ComplexVariable::operator+(double plus)
{

}
ComplexVariable &ComplexVariable::operator+(complex<double> expr)
{

}
ComplexVariable &ComplexVariable::operator-(complex<double> expr)
{

}
ComplexVariable &ComplexVariable::operator+(ComplexVariable expr)
{

}
ComplexVariable &ComplexVariable::operator-(double minus)
{

}
ComplexVariable &ComplexVariable::operator-(ComplexVariable expr)
{

}
ComplexVariable &ComplexVariable::operator==(double num)
{

}
ComplexVariable &ComplexVariable::operator==(ComplexVariable expr)
{
    
}

double solve(RealVariable expr)
{
    return 0;
}
complex<double> &solve(ComplexVariable expr)
{
    complex c;
    return c;
}
} // namespace solver