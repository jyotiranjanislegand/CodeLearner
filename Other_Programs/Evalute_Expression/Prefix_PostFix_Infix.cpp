/*
//  Prefix_PostFix_Infix.cpp
//  Created by Jyoti Ranjan on 16/06/22.
    INFIX TO POSTFIX    :
        Infix is A+(B-C)^(F*G) Postfix is : ABC-FG*^+
    INFIX TO PREFIX    :
        Infix is A+(B-C)^(F*G) Prefix is : +A^-BC*FG
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

bool isArithmeticAperator(char ch)
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
string infixToPrefix(string str)
{
    if(str.empty())
        return "Empty string";
    reverse(str.begin(),str.end());
    stack<char> operators;
    string output="";
    for(auto ch:str)
    {
        if(isArithmeticAperator(ch) || isEndingBracket(ch))
            operators.push(ch);
        else if(isStartingBracket(ch))
        {
            char c = getCombination(ch);
            char top = operators.top();
            while(!operators.empty() &&  c != top)
            {
                output += top;
                operators.pop();
                top = operators.top();
            }
            operators.pop();
        }
        else
            output += ch;
    }
    while(!operators.empty())
    {
        output += operators.top();
        operators.pop();
    }
    reverse(output.begin(),output.end());
    return output;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    stack<char> char_stack;
    string output;
    for(auto c:infix)
    {
        if(isalpha(c) || isdigit(c))
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
    reverse(infix.begin(),infix.end());
    for(int i = 0;i<infix.length();i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }
    string output = infixToPostfix(infix);
    reverse(output.begin(),output.end());
    return output;
}

int main()
{
    string str = "A+(B-C)^(F*G)";
    cout<<"Prifix: "<< str <<" is : "<<infixToPreFix(str)<<endl;
    cout<<"Postfix: "<< str <<" is : "<<infixToPostfix(str)<<endl;
    return 0;
}
