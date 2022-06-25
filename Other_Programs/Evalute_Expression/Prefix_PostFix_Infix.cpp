/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//
//  Prefix_PostFix_Infix.cpp
//  Created by Jyoti Ranjan on 16/06/22.
//
/*

   STRING :A+(B-C)^(F*G)
    Infix : A+(B-C)^(F*G) to Prefix: +A^-BC*FG
    Infix: A+(B-C)^(F*G) to Postfix : ABC-FG*^+
    PostFix: "ABC-FG*^+" to Infix: "(A+((B-C)^(F*G)))"
    
    PreFix: "+A^-BC*FG" to Infix: "(A+((B-C)^(F*G)))"
    
    PostFix: "ABC-FG*^+" to Prefix: "+A^-BC*FG"
 */

#include <bits/stdc++.h>
using namespace std;
int getPriority(char ch)
{
    if(ch == '-' || ch == '+')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

bool isArithmeticOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return true;
    return false;
}

bool isStartingBracket(char ch)
{
    if(ch == '(' || ch == '[' || ch == '{')
        return true;
    return false;
}

char getCombination(char ch)
{
    
    char c;
    if(isStartingBracket(ch))
    {
        if(ch == '(')
            c = ')';
        else if(ch == '[')
            c = ']';
        else if(ch == '{')
            c = '{';
        return c;
    }
    else
    {
        if(ch == ')')
            c = '(';
        else if(ch == ']')
            c = '[';
        else if(ch == '}')
            c = '{';
    }
    return c;
}
bool isEndingBracket(char ch)
{
    if(ch == ')' || ch == ']' || ch == '}')
        return true;
    return false;
}

string infixToPostfix(string infix)                 //              (A+(B*D)-E-F)
{
    infix = '(' + infix + ')';
    stack<char> char_stack;
    string output;
    for(auto c:infix)
    {
        if(isalpha(c) || isdigit(c))                //   ABD*+E-F-                 stack
        {
            output += c;
        }
        else if(isStartingBracket(c))
        {
            char_stack.push(c);
        }
        else if(isEndingBracket(c))
        {
            
            char tc = getCombination(c);
            while(char_stack.top() != tc)
            {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        }
        else
        {
            if(!char_stack.empty())
            {
                    while(getPriority(c) <= getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
            }
            char_stack.push(c);
        }
    }
    return output;
}
string infixToPreFix(string infix)
{
    //A+(C*D)+E
    reverse(infix.begin(),infix.end());        //E+)D*C(+A
    for(int i = 0;i<infix.length();i++)
    {
        if(infix[i] == '(')                     // E+(D*C)+A E+DC*A+ +A*CD+E
            infix[i] = ')';
        else if(infix[i] == ')')                // E+DC*A+
            infix[i] = '(';
        else if(infix[i] == '[')
            infix[i] = ']';
        else if(infix[i] == ']')
            infix[i] = '[';
        if(infix[i] == '{')
            infix[i] = '}';
        else if(infix[i] == '}')
            infix[i] = '{';
    }
    string output = infixToPostfix(infix);      // E+DC*A+
    reverse(output.begin(),output.end());       // +A*CD+E
    return output;
}
string postfixToinfix(string _postFixExp)
{
    stack<string> operands;
    
    for(auto ch:_postFixExp)
    {
        if(isalpha(ch) || isdigit(ch))
        {
            string op(1,ch);
            operands.push(op);
        }
        else if(isArithmeticOperator(ch) || (ch == '^'))
        {
                string c1 = operands.top();
                operands.pop();
                string c2 = operands.top();
                operands.pop();
                string temp = '(' + c2 + ch + c1 +')' ;
                operands.push(temp);
        }
    }
    string res = operands.top();
    return res;
}

string prefixToinfix(string _preFixExp)
{
    reverse(_preFixExp.begin(),_preFixExp.end());
    _preFixExp = postfixToinfix(_preFixExp);
    reverse(_preFixExp.begin(),_preFixExp.end());
    for(int i = 0;i<_preFixExp.length();i++)
    {
        if(_preFixExp[i] == '(')                     // E+(D*C)+A E+DC*A+ +A*CD+E
            _preFixExp[i] = ')';
        else if(_preFixExp[i] == ')')                // E+DC*A+
            _preFixExp[i] = '(';
        else if(_preFixExp[i] == '[')
            _preFixExp[i] = ']';
        else if(_preFixExp[i] == ']')
            _preFixExp[i] = '[';
        if(_preFixExp[i] == '{')
            _preFixExp[i] = '}';
        else if(_preFixExp[i] == '}')
            _preFixExp[i] = '{';
    }
    return _preFixExp;
}

int main()
{
    string str = "A+(B-C)^(F*G)";
    
    cout<<"STRING :"<< str <<endl;
    
    
    cout<<"Infix : "<< str <<" to Prefix: "<<infixToPreFix(str)<<endl;
    
    cout<<"Infix: "<< str <<" to Postfix : "<<infixToPostfix(str)<<endl;
    
    cout<<"PostFix: \""<<infixToPostfix(str)<<"\" to Infix: \""<<postfixToinfix(infixToPostfix(str))<<"\"\n"<<endl;
    
    cout<<"PreFix: \""<<infixToPreFix(str)<<"\" to Infix: \""<<prefixToinfix(infixToPreFix(str))<<"\"\n"<<endl;
    
    cout<<"PostFix: \""<<infixToPostfix(str)<<"\" to Prefix: \""<<infixToPreFix(postfixToinfix(infixToPostfix(str)))<<"\"\n"<<endl;
   
    cout<<"PreFix: \""<<infixToPreFix(str)<<"\" to Postfix: \""<<postfixToinfix(infixToPreFix(str))<<"\"\n"<<endl;

    return 0;
}
