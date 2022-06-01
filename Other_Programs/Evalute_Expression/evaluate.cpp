//
//  evaluate.cpp
//  CodeCompilTest
//
//  Created by Jyoti Ranjan on 01/06/22.
//

#include "evaluate.hpp"
int precedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    if(op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}
int applyOp(int a, int b, char op)
{
    int res = 0;
    switch(op)
    {
        case '+': res = a+b; break;
        case '-': res = a-b; break;
        case '*': res = a*b; break;
        case '/': res = a/b; break;
    }
    return res;
}
int evaluate(string tokens)
{
    stack<int> values;
    stack<int> ops;
    for(int i=0; i<tokens.size();i++)
    {
        if(tokens[i] == ' ')
            continue;
        else if(tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }
        else if(isdigit(tokens[i]))
        {
            int val = 0;
            while(i<tokens.length() && isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty())
            {
                ops.pop();
            }
        }
        else
        {
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
        
    }
    while(!ops.empty())
    {
        int val2 = values.top();
        values.pop();
        
        int val1 = values.top();
        values.pop();
        
        char op = ops.top();
        ops.pop();
        
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}
bool print(int expected, int got)
{
    cout<<"Expcected:"<<expected<<" Got:"<<got<<endl;
    if(expected == got)
    {
        cout<<"Test Passed...\n";
        return true;
    }
    else
    {
        cout<<"Test Failed!\n";
        return false;
    }
}
bool testEvaluteExpression()
{
    bool res = false;
    res = print(evaluate("10 + 2 * 6"), 22);
    res = print(evaluate("100 * 2 + 12"), 212);
    res = print(evaluate("100 * ( 2 + 12 )"), 1400);
    res = print(evaluate("100 * ( 2 + 12 ) / 14"), 100);
    return res;
}

bool isOperand(char c)
{
    return (c>='0' && c<='9');
}

int value(char c)
{
    return c-'0';
}

int evaluateSimple(char *exp)
{
    if(*exp == '\0')
        return -1;
    int res = value(exp[0]);
    for(int i=1; exp[i]; i+=2)
    {
        char opr = exp[i], opd = exp[i+1];
        if(!isOperand(opd)) return -1;
        if(opr == '+')
            res += value(opd);
        else if(opr == '-')
            res -= value(opd);
        else if(opr == '*')
            res *= value(opd);
        else if(opr == '/')
            res /= value(opd);
        else return -1;
    }
    return res;
}

bool testEvaluteSampleExpression()
{
    bool res = false;
    char t1[] = "1+2*5+3";
    res = print(evaluateSimple(t1), 18);
    char t2[] = "1+2*3";
    res = print(evaluateSimple(t2), 9);
    char t3[] = "4-2+6*3";
    res = print(evaluateSimple(t3), 24);
    char t4[] = "1++2";
    res = print(evaluateSimple(t4), -1);
   
    return res;
}
