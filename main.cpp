#pragma once

#include <iostream>
#include <string>
#include <stack>

#include "MyOpNode.h"
#include "EvaluateExpression.h"
#include "CalculateResult.h"
#include "OutputStatus.h"
#include "StrTest.h"

int main() {
    EvaluateExpression ee;
    std::stack<MyOpNode *> sta_op;
    std::stack<double *> sta_od;
    CalculateResult calc;
    OutputStatus os;
    StrTest st;

    std::string str = st.strTest();

    double res = ee.evaluateExpr(str, sta_op, sta_od, calc, os);
    std::cout << "\nResult: " << res;
}
