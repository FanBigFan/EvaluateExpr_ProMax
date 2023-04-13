//
// Created by FanBig on 2023/4/8.
//

#ifndef EVALUATEEXPRESSION_PLUS_CALCULATERESULT_H
#define EVALUATEEXPRESSION_PLUS_CALCULATERESULT_H

#include <iostream>

#include "MyOpNode.h"
#include "ModFun.h"

class CalculateResult {
public:
    double calResult(double od1, MyOpNode *op, double od2);

};


#endif //EVALUATEEXPRESSION_PLUS_CALCULATERESULT_H
