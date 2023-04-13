//
// Created by FanBig on 2023/4/13.
//

#ifndef EVALUATEEXPR_PROMAX_OUTPUTSTATUS_H
#define EVALUATEEXPR_PROMAX_OUTPUTSTATUS_H

#include <stack>
#include <iostream>
#include <iomanip>

#include "MyOpNode.h"

class OutputStatus {
public:
    void outputStatus(const std::stack<MyOpNode *> &sta_op, const std::stack<double *> &sta_od);

//    void outputTop(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od);

//    void outputOp(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od);
//
//    void outputOd(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od);
};


#endif //EVALUATEEXPR_PROMAX_OUTPUTSTATUS_H
