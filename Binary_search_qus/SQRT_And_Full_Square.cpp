/*  SQRT(X).cpp
    Created by Jyoti Ranjan on 30/06/22.
    1.
    Given a non-negative integer x, compute and return the square root of x.

     Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

     Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

      

     Example 1:

     Input: x = 4
     Output: 2
     Example 2:

     Input: x = 8
     Output: 2
     Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
     2.
     Given a positive integer num, write a function which returns True if num is a perfect square else False.

     Follow up: Do not use any built-in library function such as sqrt.

      

     Example 1:

     Input: num = 16
     Output: true
     Example 2:

     Input: num = 14
     Output: false
 
     3.
     Arranging Coins
     You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

     Given the integer n, return the number of complete rows of the staircase you will build.
    */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x)
    {
        int low = 0;
        int high = x;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            long long s = mid * mid;
            if(s == x)
            {
                return mid;
            }
            else if(s > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
    bool isPerfectSquare(int num)
    {
            int low = 0;
            int high = num;
            while(low<=high)
            {
                long long mid = low + (high-low)/2;
                long long s = mid * mid;
                if(s == num)
                {
                    return true;
                }
                else if(s > num)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return false;
        }
};

int main()
{
    int val ;
    Solution s1;
    while(1)
    {
        cout<<"Enter the value: "<<endl;
        cin>>val;
        cout<<val<<" is Perfect Square: "<<(s1.isPerfectSquare(val)?"YES":"NO")<<endl;
        if(val == -1)
        {
            cout<<"Exiting .....\n";
            break;
        }
        cout<<"Square root of "<<val<<" is : "<<s1.mySqrt(val)<<endl<<endl;
    }
    
}
