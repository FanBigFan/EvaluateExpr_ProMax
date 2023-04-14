//
// Created by FanBig on 2023/4/8.
//

#ifndef EVALUATEEXPRESSION_PLUS_EVALUATEEXPRESSION_H
#define EVALUATEEXPRESSION_PLUS_EVALUATEEXPRESSION_H

#include <string>
#include <stack>

#include "MyOpNode.h"
#include "MyOdNode.h"
#include "CalculateResult.h"
#include "OutputStatus.h"

class EvaluateExpression {
public:
    double
    evaluateExpr(std::string &expr, std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od, CalculateResult calc,
                 OutputStatus os);
};


#endif //EVALUATEEXPRESSION_PLUS_EVALUATEEXPRESSION_H
