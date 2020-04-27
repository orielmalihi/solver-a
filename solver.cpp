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

// *************** friends methods ***********************

RealVariable &operator*(double mul, RealVariable &expr)
{
    expr.coef_2 *= mul;
    expr.coef_1 *= mul;
    expr.coef_0 *= mul;
    return expr;
}
RealVariable &operator+(double num, RealVariable &expr)
{
    expr.coef_0 += num;
    return expr;
}
RealVariable &operator-(double num, RealVariable &expr)
{
    return (num * -1) + expr;
}
// ******************* class methods ********************

double RealVariable::Mysolve(RealVariable expr){
    return 0;
}
RealVariable &RealVariable::operator^(double pow)
{
    coef_2 = coef_1 * coef_1;
    coef_1 = 0;
    coef_0 *= coef_0;
    return *this;
}
RealVariable &RealVariable::operator/(double div)
{
    coef_2 /= div;
    coef_1 /= div;
    coef_0 /= div;
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
    return this->operator-(num);
}
RealVariable &RealVariable::operator==(RealVariable expr)
{
    return this->operator-(expr);
}
//**********************************************************************************
// ***************************** ComplexVariable ***********************************
//**********************************************************************************

// *************** friends methods ***********************

ComplexVariable &operator*(double mul, ComplexVariable &expr)
{
    expr.coef_2 *= mul;
    expr.coef_1 *= mul;
    expr.comp *= mul;
    return expr;
}
ComplexVariable &operator+(double num, ComplexVariable &expr)
{
    expr.comp += num;
    return expr;
}
ComplexVariable &operator-(double num, ComplexVariable &expr)
{
    return (-1 * num) + expr;
}
// ******************* class methods ********************

    complex<double> ComplexVariable::Mysolve(ComplexVariable expr){
        return expr.comp;
    }
ComplexVariable &ComplexVariable::operator^(double pow)
{
    coef_2 = coef_1 * coef_1;
    coef_1 = 0;
    comp *= comp;
    return *this;
}
ComplexVariable &ComplexVariable::operator/(double div)
{
    coef_2 /= div;
    coef_1 /= div;
    comp /= div;
    return *this;
}
ComplexVariable &ComplexVariable::operator+(double plus)
{
    comp += plus;
    ;
    return *this;
}
ComplexVariable &ComplexVariable::operator+(complex<double> expr)
{
    comp += expr;
    return *this;
}
ComplexVariable &ComplexVariable::operator-(complex<double> expr)
{
    comp -= expr;
    return *this;
}
ComplexVariable &ComplexVariable::operator+(ComplexVariable expr)
{
    coef_2 += expr.coef_2;
    coef_1 += expr.coef_1;
    comp += expr.comp;
    return *this;
}
ComplexVariable &ComplexVariable::operator-(double minus)
{
    return this->operator+(-1 * minus);
}
ComplexVariable &ComplexVariable::operator-(ComplexVariable expr)
{
    coef_2 -= expr.coef_2;
    coef_1 -= expr.coef_1;
    comp -= expr.comp;
    return *this;
}
ComplexVariable &ComplexVariable::operator==(double num)
{
    return this->operator-(num);
}
ComplexVariable &ComplexVariable::operator==(ComplexVariable expr)
{
    return this->operator-(expr);
}

double solve(RealVariable expr)
{
    return expr.Mysolve(expr);
}
complex<double> solve(ComplexVariable expr)
{
    return expr.Mysolve(expr);
}
} // namespace solver