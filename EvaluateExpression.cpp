//
// Created by FanBig on 2023/4/8.
//

#include "EvaluateExpression.h"

/**
 * @brief           对中缀表达式进行求值。
 *
 * @name            evaluateExpr
 *
 * @param expr      该中缀表达式
 * @param sta_op    操作符栈
 * @param sta_od    操作数栈
 * @param calc      实现具体运算的对象
 * @param os        格式化输出对象
 *
 * @return          返回最后的运算结果。
 *
 * @details         利用两个栈，一个操作数栈 sta_od ，一个操作符栈 sta_op 。\n
 *                  \n
 *                  先对表达式进行扫描，记每个字符为 ch 。\n
 *                  \n
 *                  1. 若 ch 为数字 ，即 ch >= '0' && ch <= '9' ：\n
 *                     则还需进行对下一个字符进行扫描，记下一个字符为 str.at(tempIndex) ，\n
 *                     若下一个字符 str.at(tempIndex) 为数字或者为小数点 ，\n
 *                     即 str.at(tempIndex) >= '0' && str.at(tempIndex) <= '9' || str.at(tempIndex) == '.' ，\n
 *                     则继续对下一个字符进行扫描 ，直到 str.at(tempIndex) 不满足条件 ， 或 tempIndex >= str.length() 为止 。\n
 *                     取出 index 到 tempIndex 的子串，将其转化为数字，并压入 sta_od 中。\n
 *                     ch 后移一位 。\n
 *                  \n
 *                  2. 若 ch 为操作符 ( '+' '-' '*' '/' '%' ) ：\n
 *                     MyOpNode* 类型的变量 tempOpNode ，并将其优先级设为：\n
 *                     '+' '-'     : 1 , \n
 *                     '*' '/' '%' : 2 , \n
 *                     若操作符栈为空 ， 即 sta_op.isEmpty() ，则将操作符入栈 。\n
 *                     若不为空 ，则新建一个 MyOpNode* 类型的变量 tempTopNode ，并赋值为 sta_op.top() 。\n
 *                     随后与操作符栈顶元素比较优先级，\n
 *                     若该操作符优先级 >  操作符栈顶元素优先级，则直接入操作符栈 。\n
 *                     若该操作符优先级 <= 操作符栈顶元素优先级，\n
 *                     则先从操作数栈中取出两个元素 ，记为 od2 od1 ，再从操作符栈中取出一个元素 ，记为 op ，然后调用 calResult 函数，实现具体运算，并将该函数返回的值放入堆区，随后入操作数栈。 \n
 *                     ch 后移一位 。\n
 *                  \n
 *                  3. 若 ch 为 '(' ：\n
 *                     记为一个 MyOpNode 类型的操作符，并将其优先级设为 '-1'，ch 后移一位。 \n
 *                  \n
 *                  4. 若 ch 为 ')' ：\n
 *                     若操作符栈顶元素不为 '(' ，则先从操作数栈中取出两个元素 ，记为 od2 od1 ，再从操作符栈中取出一个元素 ，记为 op ，调用 calResult 函数，实现具体运算，并将该函数返回的值放入堆区，随后入操作数栈。\n
 *                     最后 pop 掉 '(' ，ch 后移一位。 \n
 *                  \n
 *                  若 ch 把表达式 expr 扫描完毕 ：\n
 *                     则先判断操作符栈是否为空 ，\n
 *                     若不为空 ，则先从操作数栈中取出两个元素 ，记为 od2 od1 ，再从操作符栈中取出一个元素 ，记为 op ，调用 calResult 函数，实现具体运算，并将该函数返回的值放入堆区，随后入操作数栈。\n
 *                     若为空 ，则返回最后结果 。
 *
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