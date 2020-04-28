/*
 * solver.cpp
 *
 *  Created on: 28 April 2020
 *      Author: oriel malihi
 */
#include <string>
#include <iostream>
#include <cmath>
#include "solver.hpp"
using namespace std;

namespace solver
{

//*************** friend real **************************

RealVariable &operator*(double num, RealVariable &x)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(0, num, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 *= num;
        x.coef_1 *= num;
        x.coef_0 *= num;
        return x;
    }
}

RealVariable &operator^(RealVariable &x, double num)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(1, 0, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 = x.coef_1 * x.coef_1;
        x.coef_1 = 0;
        x.coef_0 *= x.coef_0;
        return x;
    }
}
RealVariable &operator/(RealVariable &x, double num)
{
    if (x.add == NULL)
    {
        double t = 1 / num;
        RealVariable *temp = new RealVariable(0, t, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 /= num;
        x.coef_1 /= num;
        x.coef_0 /= num;
        return x;
    }
}
RealVariable &operator+(RealVariable &x, double num)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(0, 1, num);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_0 += num;
        return x;
    }
}
    RealVariable &operator+(double num, RealVariable &x){
        return x + num;
    }

RealVariable &operator-(RealVariable &x, double num)
{
    return x + (-1) * num;
}
RealVariable &operator+(RealVariable &x, RealVariable &y)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(y.coef_2, y.coef_1 + 1, y.coef_0);
        temp->add = temp;
        delete y.add;
        return *temp;
    }
    else
    {
        x.coef_2 += y.coef_2;
        x.coef_1 += y.coef_1;
        x.coef_0 += y.coef_0;
        delete y.add;
        return x;
    }
}
RealVariable &operator-(RealVariable &x, RealVariable &y)
{
    return x + ((-1)*y);
}

RealVariable &operator==(RealVariable &x, RealVariable &y)
{
    return x - y;
}
RealVariable &operator==(RealVariable& x, double num){
    return x - num;
}

double solve(RealVariable &x){
    double ans = -1;
    if (x.coef_2 != 0)
    {
        int a = x.coef_2;
        int b = x.coef_1;
        int c = x.coef_0;
        // cout << "a = " << coef_2 << ", b = " << coef_1 << ", c = " << coef_0 << endl;
        int t = b * b - 4 * a * c;
        if (t < 0)
        {
            // cout << "a = " << coef_2 << ", b = " << coef_1 << ", c = " << coef_0 << endl;
            delete x.add;
            throw runtime_error("There is no real solution");
        }
        ans = sqrt(t) - b;
        ans /= a * 2;
        delete x.add;
    }
    else if (x.coef_1 != 0)
    {
        ans = (x.coef_0 / x.coef_1) * (-1);
        delete x.add;
    }
    else
    {
        throw runtime_error("ERR: cant do this math. wrong input");
    }
    return ans;
}

// to do!!!!!

// ************** friend comp **********************************************

// ComplexVariable &operator*(double num, ComplexVariable& x)
// {
//     if(x.ind == 0){
//        ComplexVariable *temp = new ComplexVariable(0, num, 'c');
//     temp->adr[temp->ind++] = temp;
//     return *temp;
//     }
//     else{
//         x.coef_2 *= num;
//         x.coef_1 *= num;
//         x.comp *= num;
//         return x;
//     }

// }

// ComplexVariable &operator^(ComplexVariable& x, double num)
// {
//     ComplexVariable *temp = new ComplexVariable(1, 0, 'c');
//     temp->adr[temp->ind++] = temp;
//     return *temp;
// }
// ComplexVariable &operator/(ComplexVariable& x, double num)
// {
//     double t = 1 / num;
//     ComplexVariable *temp = new ComplexVariable(0, t, 'c');
//     temp->adr[temp->ind++] = temp;
//     return *temp;
// }

} // namespace solver
