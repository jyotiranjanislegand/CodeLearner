/*
  CountBits.cpp
  Created by Jyoti Ranjan on 28/06/22.
  1>   Given a non negative integer number num. For every numbers i in the range 0 ≤ i
         ≤ num calculate the number of 1's in their binary representation and return them
         as an array.
         Example 1:
         Input: 2
         Output: [0,1,1]
         Example 2:
         Input: 5
         Output: [0,1,1,2,1,2]
         Follow up:
         It is very easy to come up with a solution with run time O(n*sizeof(integer)).
         But can you do it in linear time O(n) /possibly in a single pass?
         Space complexity should be O(n).
         Can you do it like a boss? Do it without using any builtin function like
         __builtin_popcount in c++ or in any other language.
 2>    Given an integer n, return true if it is a power of four. Otherwise, return false.
 
         An integer n is a power of four, if there exists an integer x such that n == 4x.
         Example 1:

         Input: n = 16
         Output: true
         Example 2:

         Input: n = 5
         Output: false
         Example 3:

         Input: n = 1
         Output: true
 3>Given an integer n, return true if it is a power of two. Otherwise, return false.
 
 An integer n is a power of two, if there exists an integer x such that n == 2x.

     Example 1:

     Input: n = 1
     Output: true
     Explanation: 20 = 1
     Example 2:

     Input: n = 16
     Output: true
     Explanation: 24 = 16
     Example 3:

     Input: n = 3
     Output: false
 4> Given an integer n, return true if it is a power of three. Otherwise, return false.
 
 An integer n is a power of three, if there exists an integer x such that n == 3x.

  

 Example 1:

 Input: n = 27
 Output: true
 Example 2:

 Input: n = 0
 Output: false
 Example 3:

 Input: n = 9
 Output: true
 
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

 Given two integers x and y, return the Hamming distance between them.

  

 Example 1:

 Input: x = 1, y = 4
 Output: 2
 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
        ↑   ↑
 The above arrows point to positions where the corresponding bits are different.
 Example 2:

 Input: x = 3, y = 1
 Output: 1
  

 Constraints:

 0 <= x, y <= 231 - 1
 

 5> Given a positive integer, output its complement number. The complement strategy
 is to flip the bits of its binary representation.
 Example 1:
 Input: 5
 Output: 2
 Explanation: The binary representation of 5 is 101 (no leading zero bits), and
 its complement is 010. So you need to output 2.
 Example 2:
 Input: 1
 Output: 0
 Explanation: The binary representation of 1 is 1 (no leading zero bits), and its
 complement is 0. So you need to output 0.
 Note:
 The given integer is guaranteed to fit within the range of a 32-bit signed
 integer.
 You could assume no leading zero bit in the integer’s binary representation.
 This question is the same as 1009: https://leetcode.com/problems/complement-of-
 base-10-integer/
 
 6>You are given an integer n and an integer start.

 Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

 Return the bitwise XOR of all elements of nums.

  

 Example 1:

 Input: n = 5, start = 0
 Output: 8
 Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
 Where "^" corresponds to bitwise XOR operator.
 Example 2:

 Input: n = 4, start = 3
 Output: 8
 Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> countBits(int num)
{
    vector<int> ret(num + 1, 0);
    for (int i = 1; i <= num; ++i)
    {
      ret[i] = ret[i & (i - 1)] + 1;
    }
    return ret;
}
vector<int> count_Bits(int num)
{
    vector<int> ret;
    for (int i = 0; i <= num; ++i) {
      ret.push_back(__builtin_popcount(i));
    }
    
    return ret;
}

vector<int> countB(int num) {
    vector<int> dp(num + 1, 0);
    for (int i = 1, m = 1; i <= num; ++i) {
      if (i == m << 1) m <<= 1;
      dp[i] = dp[i % m] + 1;
    }
return dp; }

void printVec(vector<int> v){
        cout<<"[ ";
        for(int i=0; i<v.size(); ++i)
        {
            cout<<v[i]<<" ";
            if(i+1 != v.size())
              cout<<", ";
        }
        cout<<" ]"<<endl;
    }
    bool isPowerOfFour(int n)
    {
        int _nc = __builtin_popcount(n);
        if( _nc!=1 || _nc<=0)
                return false;
        while(n !=0 && (n&1) != 1)
            n>>=2;
        return n == 1;
    }
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        if((n&n-1) == 0)
            return true;
        return false;
    }
    bool isPowerOfThree(int n)
    {
        /*-------solution 1--------*/
        /*if(n == 0) return false;
        if(n == 1) return true;

        return n % 3 == 0 and isPowerOfThree(n/3);*/
        
        /*-------solution 2--------*/
        // 1162261467 is the largest power of 3 in integer range and if this number is divisible by input, we are good to go.
        //return n > 0 && 1162261467 % n == 0;

        /*-------solution 3--------*/
        if(n < 1) return false;
        while(n % 3 == 0) n /= 3;
        return n == 1;
    }
    int hammingDistance(int x, int y)
    {
        int ret = 0;
        for(int i=x^y;i!=0;i/=2)
        {
            ret += i%2;
        }
        return ret;
    }
    int findComplement(int num)
    {
        int ret = 0, bits = 0;
        for (; num != 0; num /= 2, ++bits)
        {
          if (num % 2 == 0)
          {
            ret += 1 << bits;
          }
        }
        return ret;
    }
    int xorOperation(int n, int start)
    {
        int ret = 0;
        for (int i = 0; i < n; ++i) ret ^= start + 2 * i;
        return ret;
    }
    
};

int main()
{
    Solution s;
    vector<int> v = s.countBits(3);
    s.printVec(v);
    vector<int> _v = s.count_Bits(5);
    s.printVec(_v);
    vector<int> _v1 = s.countB(5);
    s.printVec(_v1);
    int val = 66;
    int val1 = 27;
    cout<<"Is "<<val<<" Power of 4 ?"<<(s.isPowerOfFour(val)?": YES":": NO")<<endl;
    cout<<"Is "<<val<<" Power of 2 ?"<<(s.isPowerOfTwo(val)?": YES":": NO")<<endl;
    cout<<"Is "<<val1<<" Power of 2 ?"<<(s.isPowerOfThree(val1)?": YES":": NO")<<endl;
    int x = 1, y = 16;
    cout<<"Hamming Distance "<<x<<" And "<<y <<s.hammingDistance(x,y)<<endl;
    val = 9;
    cout<<"Compliment of "<< val << "is" <<s.findComplement(val)<<endl;
    cout<<"XOR Operation in an Array "<<s.xorOperation(5,0)<<endl;
    return 0;
}
