cmake_minimum_required(VERSION 3.24)
project(EvaluateExpr_ProMax)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        EvaluateExpr_ProMax
        main.cpp
        EvaluateExpression.h
        EvaluateExpression.cpp
        MyOdNode.cpp
        ModFun.cpp
        ModFun.h
        MyNode.h
        MyOpNode.cpp
        CalculateResult.cpp
        CalculateResult.h
        #        mainTest.cpp
        OutputStatus.cpp
        OutputStatus.h
        StrTest.cpp
        StrTest.h)
