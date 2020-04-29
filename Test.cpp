/*
 * Test.cpp
 *
 *  Created on: 29 April 2020
 *      Author: oriel malihi
 */
#include "doctest.h"
#include <string>
#include <complex>
#include "solver.hpp"
using namespace std;
using namespace solver;

static RealVariable x;
static ComplexVariable y;

TEST_CASE("linear equation - real")
{
    CHECK(solve(x == 3) == 3);
    CHECK(solve(3 == x) == 3);
    CHECK((int)(solve(3 * x == 10) * 10000) / 10000.0 == 3.3333);
    CHECK(solve(44 == 4 * x) == 11);
    CHECK(solve(0.5 * x == 6) == 12);
    CHECK(solve(34 == 0.1 * x) == 340);
    CHECK(solve(5 * x == 1) == 0.2);
    CHECK(solve(16 == 8 * x) == 2);
    CHECK(solve(x + x + 2 * x == 4) == 1);
    CHECK(solve(3 == x + 2 * x) == 1);
    CHECK(solve(x - 7 * x + 2 * x == 40) == -10);
    CHECK(solve(3 == x / 3) == 9);
    CHECK(solve(x / 2 - 2 * x / 2 == 3) == -6);
    CHECK(solve(3 == x / 2 + 2 * x + x / 2) == 1);
    CHECK(solve(x == 0) == 0);
    CHECK(solve(x / 0.1 == 1) == 0.1);
    CHECK(solve(2 * x / 2 + x == 3) == 1.5);
    CHECK(solve(x / 5 == 0.2) == 1);
    CHECK_THROWS(solve(3 == x - x));
    CHECK_THROWS(solve(-2 * x + 2 * x == 3));
    CHECK_THROWS(solve(3 == 0 * x));
    CHECK_THROWS(solve(0 * x + 10 == 3));
}

TEST_CASE("linear equation - complex")
{
    CHECK(solve(y == 3) == 3. + 0i);
    CHECK(solve(3 == y) == 3. + 0i);
    CHECK(solve(y == 3i) == 0. + 3i);
    CHECK(solve(y == 3i + 5i) == 0. + 8i);
    CHECK(solve(3i * 5i * 2. == 2 * y) == -15. + 0i);
    CHECK(solve(3i * 5i * 2. == 2 * y + y) == -10. + 0i);
    CHECK(solve(y == 2. + 3i) == 2. + 3i);
    CHECK(solve(2. * 3i + 4. == y) == 4. + 6i);
    CHECK(solve(2 * y == 3) == 1.5 + 0i);
    CHECK(solve(y / 2 == 3) == 6. + 0i);
    CHECK(solve(3 * y - 2 * y == 3) == 3. + 0i);
    CHECK(solve(y == 3i - 2i) == 0. + 1i);
    CHECK(solve(2 * y == 4i) == 0. + 2i);
    CHECK(solve(y + 4. + 1i == 3) == -1. - 1i);
    CHECK(solve(y + y / 2 == -1 * y / 2 + 4. + 4i) == 2. + 2i);
    CHECK(solve(6 * y / 6 + y == 6. + 6i) == 3. + 3i);
    CHECK(solve(y + 3. + 3i == 2) == -1. - 3i);
    CHECK(solve(y + y - y == 3) == 3. + 0i);
    CHECK(solve(y / 10 - 2i == 1) == 10. + 20i);
    CHECK(solve(10 * y == 2) == 0.2 + 0i);
    CHECK(solve(10 * y + 2i == -2) == -0.2 - 0.2i);
    CHECK(solve(y / 3 == 3. + 2i) == 9. + 6i);
    CHECK(solve(3. + 2i == y / 3) == 9. + 6i);
    CHECK(solve(2 * y == 10000. + 1i) == 5000. + 0.5i);
    CHECK_THROWS(solve(y - y == 3i));
    CHECK_THROWS(solve(2 * y / 2 - y == 3. + 6i));
    CHECK_THROWS(solve(0 * y == 0));
    CHECK_THROWS(solve(0 * y + 8 == 3));
}

TEST_CASE("Quadratic equation - real")
{
    double ans = solve((x ^ 2) == 4);
    CHECK((ans == 2 || ans == -2));
    ans = solve((x ^ 2) == 9);
    CHECK((ans == 3 || ans == -3));
    ans = solve((x ^ 2) -7 == 9);
    CHECK((ans == 4 || ans == -4));
    ans = solve((x ^ 2)/2 == 8);
    CHECK((ans == 4 || ans == -4));
    ans = solve(2*(x ^ 2) == 18);
    CHECK((ans == 3 || ans == -3));
    ans = solve((x ^ 2) + 5*x == -6);
    CHECK((ans == -2 || ans == -3));
    ans = solve(-6 + x + (x ^ 2) == 0);
    CHECK((ans == 2 || ans == -3));
    ans = solve((x ^ 2) + 2*x == 8);
    CHECK((ans == 2 || ans == -4));
    ans = solve(16 == 2*(x ^ 2) + 4*x);
    CHECK((ans == 2 || ans == -4));
    ans = solve(2*(x ^ 2) + 4*x -16  == 0);
    CHECK((ans == 2 || ans == -4));
    //************ works **************
    ans = solve((x ^ 2)  == 5*x +6);
    CHECK((ans == -1 || ans == 6));
    ans = solve((x ^ 2) == 100);
    CHECK((ans == 10 || ans == -10));
    ans = solve((x ^ 2) == 25);
    CHECK((ans == 5 || ans == -5));
    ans = solve((x ^ 2) == 36);
    CHECK((ans == 6 || ans == -6));
    //********************
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -6), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -25), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -100), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) +100 == -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) +25 == -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) +6*x -8 == -100), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2)/2 +x -5== -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -16), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -1000), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -0.01), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == 3*x -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve(4 ==(x ^ 2) -7*x +100), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve(4*(x ^ 2) +4*x/2 == -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2)/2 +3*x == -9), "There is no real solution");
    CHECK_THROWS_MESSAGE(solve((x ^ 2) == -81), "There is no real solution");
}
