//
//  evaluate.hpp
//  CodeCompilTest
//
//  Created by Jyoti Ranjan on 01/06/22.
//
#ifndef evaluate_hpp
#define evaluate_hpp
#include "stdc++.hpp"
int precedence(char op);
int applyOp(int a, int b, char op);
int evaluate(string tokens);
bool testEvaluteExpression();
bool isOperand(char c);
int value(char c);
int evaluateSimple(char *exp=nullptr);
bool print(int expected, int got);
bool testEvaluteSampleExpression();
#endif /* evaluate_hpp */
