//
// Created by FanBig on 2023/4/8.
//

#include "CalculateResult.h"

double CalculateResult::calResult(double od1, MyOpNode *op, double od2) {
    ModFun mf;
    switch (op->op) {
        case '+':
            return od1 + od2;
        case '-':
            return od1 - od2;
        case '*':
            return od1 * od2;
        case '/':
            return od1 / od2;
        case '%':
            return mf.mod(od1, od2);
        default:
            std::cout << "Error ! [ '" << op->op << "' ] " << std::endl;
            exit(0);
    }
}
