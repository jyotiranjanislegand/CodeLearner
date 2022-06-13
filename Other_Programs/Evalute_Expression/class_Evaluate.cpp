#include<stdc++.hpp>
using namespace std;

class Evaluate {
public:
    int calculate(string s)
    {
        int ans=0;
        int intermediate=0;
        char op = '+';
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
                continue;
            else if(!isdigit(s[i]))
                op = s[i];
            else
            {
                 int num = 0;
                 while((i<s.size()) && isdigit(s[i]))  
                     num = (num*10)+(s[i++]-'0');
                 if(op == '*')
                     intermediate *= num;
                 else if(op == '/')
                     intermediate /= num;  
                 else
                 {
                     ans += intermediate;
                     intermediate = num*(op == '+'?1:-1);
                 }
                 i--;  
            }  
        }
        ans += intermediate;
        return ans;
    }
    int calc(string str)
    {
        if(str.empty())
                return 0;
        int n = str.length();
        stack<int> st;
        int sign = 1;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '+')
                    sign = 1;
            else if(str[i] == '-')
                    sign = -1;
            else if(isdigit(str[i]))
            {
                long long int val = 0;
                while(i<n && isdigit(str[i]))
                {
                        val = val*10 + str[i]-'0';
                        i++;
                }
                i--;
                res = res+val*sign;
            }
            else if(str[i] == '(')
            {
                    st.push(res);
                    st.push(sign);
                    res = 0;
                    sign = 1;
            }
            else if(str[i] == ')')
            {
                    int curr_sign = st.top();
                    st.pop();
                    int curr_val = st.top();
                    st.pop();
                    res = curr_val + res*curr_sign;
            }
        }
        return res;
    }
};
int main()
{
    Evaluate obj;
    cout<<obj.calculate("2+9*5/15")<<endl;
    cout<<obj.calculate("2+9/3")<<endl;
    cout<<obj.calc("2+9/3")<<endl;
    cout<<obj.calc("(2+9)/3")<<endl;
    cout<<obj.calc("(2-9)/3")<<endl;
    cout<<obj.calc("-(2+9)-3")<<endl;
    return 0;
}
