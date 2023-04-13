//
// Created by FanBig on 2023/3/19.
//

#ifndef EVALUATEEXPRESSION_NODE_MYOPNODE_H
#define EVALUATEEXPRESSION_NODE_MYOPNODE_H

#include "MyNode.h"

class MyOpNode : public MyNode {
public:
    char op;
    int level;

    MyOpNode() {}

    MyOpNode(char op, int level);
};


#endif //EVALUATEEXPRESSION_NODE_MYOPNODE_H
