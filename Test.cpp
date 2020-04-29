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
}

TEST_CASE("linear equation - complex")
{
    CHECK(solve(y == 3) == 3.+0i);
    CHECK(solve(3 == y) == 3.+0i);
    CHECK(solve(y == 3i) == 0.+3i);
    CHECK(solve(y == 3i + 5i) == 0.+8i);
    CHECK(solve( 3i * 5i * 2. == 2*y) == -15.+0i);
    CHECK(solve( 3i * 5i * 2. == 2*y + y) == -10.+0i);
    CHECK(solve(y == 2.+3i) == 2.+3i);
    CHECK(solve(2.*3i + 4. == y) == 4.+6i);
}
