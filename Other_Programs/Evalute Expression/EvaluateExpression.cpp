/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

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
    int res = 0;
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

int test()
{
    cout << ((evaluate("10 + 2 * 6") == 22)?"PASS":"FAIL") << "\n";
    cout << evaluate("10 + 2 * 6")<<endl;
    cout << ((evaluate("100 * 2 + 12") == 212)?"PASS":"FAIL") << "\n";
    cout << evaluate("100 * 2 + 12")<<endl;
    cout << ((evaluate("100 * ( 2 + 12 )") == 1400)?"PASS":"FAIL") << "\n";
    cout << evaluate("100 * ( 2 + 12 )")<<endl;
    cout << ((evaluate("100 * ( 2 + 12 ) / 14") == 100)?"PASS":"FAIL") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14")<<endl;
    return 0;
}

int main()
{
    test();
    return 0;
}
