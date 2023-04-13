//
// Created by FanBig on 2023/3/19.
//

#ifndef EVALUATEEXPRESSION_NODE_MYODNODE_H
#define EVALUATEEXPRESSION_NODE_MYODNODE_H

#include <string>

#include "MyNode.h"

class MyOdNode : public MyNode {
public:
    double val;

    MyOdNode() {}

    MyOdNode(const std::string &str);
};

#endif //EVALUATEEXPRESSION_NODE_MYODNODE_H
