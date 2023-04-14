//
// Created by FanBig on 2023/4/13.
//

#include "OutputStatus.h"

void OutputStatus::outputStatus(const std::stack<MyOpNode *> &sta_op, const std::stack<double *> &sta_od) {
    std::stack<MyOpNode *> tempSta_op2;
    std::stack<double *> tempSta_od2;

    std::stack<MyOpNode *> tempSta_op;
    std::stack<double *> tempSta_od;

    tempSta_op2 = sta_op;
    tempSta_od2 = sta_od;

    while (!tempSta_op2.empty()) {
        tempSta_op.push(tempSta_op2.top());
        tempSta_op2.pop();
    }

    while (!tempSta_od2.empty()) {
        tempSta_od.push(tempSta_od2.top());
        tempSta_od2.pop();
    }

    std::cout << "Op: ";
    while (!tempSta_op.empty()) {
        std::cout << tempSta_op.top()->op << " ";
        tempSta_op.pop();
    }

    std::cout << "    ";

    std::cout << "\tOd: ";
    while (!tempSta_od.empty()) {
        std::cout << "[" << *tempSta_od.top() << "] ";
        tempSta_od.pop();
    }

    std::cout << std::endl;
}

/*  void OutputStatus::outputStatus(const std::stack<MyOpNode *> &sta_op, const std::stack<double *> &sta_od) {
    std::stack<MyOpNode *> tempSta_op;
    std::stack<double *> tempSta_od;

    tempSta_op = sta_op;
    tempSta_od = sta_od;

    std::cout << "Op: ";
    while (!tempSta_op.empty()) {
        std::cout << tempSta_op.top()->op << " ";
        tempSta_op.pop();
    }

    std::cout << "    ";

    std::cout << "\tOd: ";
    while (!tempSta_od.empty()) {
        std::cout << "[" << *tempSta_od.top() << "] ";
        tempSta_od.pop();
    }

    std::cout << std::endl;
}*/

/*  void OutputStatus::outputTop(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
    std::cout << "Op: ";
    if (!sta_op.empty()) {
        std::cout << sta_op.top()->op << " ";
    } else {
        std::cout << "  ";
    }

    std::cout << "\t";

    std::cout << "Od: ";
    if (!sta_od.empty()) {
        std::cout << *sta_od.top() << " ";
    } else {
        std::cout << "  ";
    }

    std::cout << std::endl;
}/*/

/*
 * void OutputStatus::outputOp(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
    std::cout << "Op: ";
    if (!sta_op.empty()) {
        std::cout << sta_op.top()->op << " ";
    }
}

   void OutputStatus::outputOd(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
    std::cout << "Od: ";
    if (!sta_od.empty()) {
        std::cout << *sta_od.top() << " ";
    }
}*/
