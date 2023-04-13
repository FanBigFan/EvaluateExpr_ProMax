//
// Created by FanBig on 2023/4/13.
//

#include "OutputStatus.h"

void OutputStatus::outputStatus(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
    std::cout << "Op: ";
    while (!sta_op.empty()) {
        std::cout << sta_op.top()->op << " ";
        sta_op.pop();
    }

    std::cout << std::endl;

    std::cout << "Od: ";
    while (!sta_od.empty()) {
        std::cout << *sta_od.top() << " ";
        sta_od.pop();
    }
}

void OutputStatus::outputTop(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
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
}

//void OutputStatus::outputOp(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
//    std::cout << "Op: ";
//    if (!sta_op.empty()) {
//        std::cout << sta_op.top()->op << " ";
//    }
//}
//
//void OutputStatus::outputOd(std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od) {
//    std::cout << "Od: ";
//    if (!sta_od.empty()) {
//        std::cout << *sta_od.top() << " ";
//    }
//}