//
// Created by FanBig on 2023/4/8.
//

#include "EvaluateExpression.h"

/**
 * @brief           对中缀表达式进行求值。
 *
 * @name            evaluateExpr
 *
 * @param expr       该中缀表达式
 * @param sta_op    操作符栈
 * @param sta_od    操作数栈
 * @param calc      实现具体运算的对象
 * @param os        格式化输出对象
 *
 * @return          返回一个最后的运算结果。
 * */
double
EvaluateExpression::evaluateExpr(std::string &expr, std::stack<MyOpNode *> sta_op, std::stack<double *> sta_od,
                                 CalculateResult calc, OutputStatus os) {
    int index = 0;

    while (index < expr.length()) {
        char ch = expr.at(index);

        if (ch >= '0' && ch <= '9') {
            int tempIndex = index + 1;

            while ((tempIndex < expr.length()) &&
                   (expr.at(tempIndex) >= '0' && expr.at(tempIndex) <= '9' || expr.at(tempIndex) == '.')) {
                tempIndex++;
            }

            std::string tempStr;

            if (tempIndex >= expr.length()) {
                tempStr = expr.substr(index);
            } else {
                tempStr = expr.substr(index, tempIndex - index);
            }

            index = tempIndex;

            MyNode *tempNode = new MyOdNode(tempStr);

            auto *res = new double(((MyOdNode *) tempNode)->val);

            sta_od.push(res);
            os.outputStatus(sta_op, sta_od);
        }

        if (ch == '+' || ch == '-') {
            auto *tempOpNode = new MyOpNode(ch, 1);

            if (sta_op.empty()) {
                sta_op.push(tempOpNode);
            } else {
                MyOpNode *tempTopNode = sta_op.top();

                while ((tempTopNode != nullptr) && (tempTopNode->level >= tempOpNode->level)) {
                    double od2 = *sta_od.top();
                    sta_od.pop();
                    double od1 = *sta_od.top();
                    sta_od.pop();

                    MyOpNode *op = sta_op.top();
                    sta_op.pop();

                    double res = calc.calResult(od1, op, od2);
                    auto *result = new double(res);
                    sta_od.push(result);

                    if (sta_op.empty()) {
                        break;
                    } else {
                        tempTopNode = sta_op.top();
                    }
                }

                sta_op.push(tempOpNode);
            }

            index++;
            os.outputStatus(sta_op, sta_od);
        }

        if (ch == '*' || ch == '/' || ch == '%') {
            auto *tempOpNode = new MyOpNode(ch, 2);

            if (sta_op.empty()) {
                sta_op.push(tempOpNode);
            } else {
                MyOpNode *tempTopNode = sta_op.top();

                while ((tempTopNode != nullptr) && (tempTopNode->level >= tempOpNode->level)) {
                    double od2 = *sta_od.top();
                    sta_od.pop();
                    double od1 = *sta_od.top();
                    sta_od.pop();

                    MyOpNode *op = sta_op.top();
                    sta_op.pop();

                    double res = calc.calResult(od1, op, od2);
                    auto *result = new double(res);
                    sta_od.push(result);

                    if (sta_op.empty()) {
                        break;
                    } else {
                        tempTopNode = sta_op.top();
                    }
                }

                sta_op.push(tempOpNode);
            }

            index++;
            os.outputStatus(sta_op, sta_od);
        }

        if (ch == '(') {
            auto *tempNode = new MyOpNode(ch, -1);
            sta_op.push(tempNode);
            index++;
            os.outputStatus(sta_op, sta_od);
        }

        if (ch == ')') {
            while (sta_op.top()->op != '(') {
                double od2 = *sta_od.top();
                sta_od.pop();
                double od1 = *sta_od.top();
                sta_od.pop();

                MyOpNode *op = sta_op.top();
                sta_op.pop();

                double res = calc.calResult(od1, op, od2);
                auto *result = new double(res);
                sta_od.push(result);
            }

            sta_op.pop();
            index++;
            os.outputStatus(sta_op, sta_od);
        }
    }

    while (!sta_op.empty()) {
        double od2 = *sta_od.top();
        sta_od.pop();
        double od1 = *sta_od.top();
        sta_od.pop();

        MyOpNode *op = sta_op.top();
        sta_op.pop();

        double res = calc.calResult(od1, op, od2);
        auto *result = new double(res);
        sta_od.push(result);
    }
    return *sta_od.top();
}
/**
 * 计算表达式：\n
 *   利用两个栈，一个操作数栈 sta_od ，一个操作符栈 sta_op 。\n
 *   \n
 *   先对表达式进行扫描，记每个字符为 ch 。\n
 *   \n
 * 1. 若 ch 为数字 ，即 ch >= '0' && ch <= '9' ，则还需进行对下一个字符进行扫描，记写一个字符为 str.at(tempIndex) ，
 *      若下一个字符 str.at(tempIndex) 为数字或者为小数点 ，
 *      即 str.at(tempIndex) >= '0' && str.at(tempIndex) <= '9' || str.at(tempIndex) == '.' ，
 *      则继续对下一个字符进行扫描 ，直到 str.at(tempIndex) 不满足条件 ， 或 tempIndex >= str.length() 为止 。
 *      取出 index 到 tempIndex 的子串，将其转化为数字，并压入 sta_od 中。\n
 *   \n
 * 2. 若 ch 为操作符，则
 * */