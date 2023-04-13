//
// Created by FanBig on 2023/3/27.
//

#include "ModFun.h"

double ModFun::myAbsoluteNum(double val) {
    if (val > 0) {
        return val;
    } else {
        return -val;
    }
}


double ModFun::mod(double val1, double val2) {
    double abs1 = myAbsoluteNum(val1);
    double abs2 = myAbsoluteNum(val2);

    while (abs1 >= abs2) {
        abs1 -= abs2;
    }

    if (val1 * val2 > 0) {
        return abs1;
    } else {
        return -abs1;
    }
}