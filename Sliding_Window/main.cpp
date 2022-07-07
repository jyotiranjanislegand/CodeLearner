//
//  main.cpp
//  Sliding Window
//
//  Created by Jyoti Ranjan on 05/07/22.
//

#include "stdc++.h"
#define CHAR_RANGE 128
using namespace std;
class SlidingWindow
{
    public:
    /*Find the longest substring of a string containing `k` distinct characters
     Given a string and a positive number k, find the longest substring of the string containing k distinct characters. If k is more than the total number of distinct characters in the string, return the whole string.

     The problem differs from the problem of finding the longest subsequence with k distinct characters. Unlike subsequences, substrings are required to occupy consecutive positions within the original string.

      
     For example, consider string abcbdbdbbdcdabd.

     For k = 2, o/p is ‘bdbdbbd’
     For k = 3, o/p is ‘bcbdbdbbdcd’
     For k = 5, o/p is ‘abcbdbdbbdcdabd’*/
    string FindLongestSubStringWithKDistinctCharcters(string str, int k, int len);
    
    /*Find all substrings of a string that contains all characters of another string. In other words, find all substrings of the first string that are anagrams of the second string.Please note that the problem specifically targets substrings that are contiguous (i.e., occupy consecutive positions) and inherently maintains the order of elements.
     
     
     For example,

     The first string is 'XYYZXZYZXXYZ'
     The second string is 'XYZ'
      
     Anagram 'YZX' present at index 2
     Anagram 'XZY' present at index 4
     Anagram 'YZX' present at index 6
     Anagram 'XYZ' present at index 9*/
     void FindAllAnagrams(string X, string Y);
    
    /*Find the longest substring of a string containing distinct characters
     The problem differs from the problem of finding the longest subsequence with distinct characters. Unlike subsequences, substrings are required to occupy consecutive positions within the original string.

      
     For example,

     Input: findlongestsubstring
      
     Output: The longest substring with all distinct characters is dlongest or ubstring
      
      
     Input: longestsubstr
      
     Output: The longest substring with all distinct characters is longest
      
      
     Input: abbcdafeegh
      
     Output: The longest substring with all distinct characters is bcdafe
      
      
     Input: aaaaaa
      
     Output: The longest substring with all distinct characters is a */
    string findLongestSubstring(string str, int n);
    /*Find maximum length sequence of continuous ones (Using Sliding Window)
     Given a binary array, find the index of 0 to be replaced with 1 to get a maximum length sequence of continuous ones.

     For example, consider array { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }. The index to be replaced is 7 to get a continuous sequence of length 6 containing all 1’s.
     */
    int findIndexofZero(int arr[], int n);
    
    /*Find the maximum sequence of continuous 1’s formed by replacing at-most `k` zeroes by ones
     Given a binary array, find the maximum sequence of continuous 1’s that can be formed by replacing at most k zeroes by ones.

     For example, consider the following binary array A:

     Input: A[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 }
      
      
     For k = 0,
     The length of the longest sequence is 4 (from index 6 to 9)
      
     For k = 1,
     The length of the longest sequence is 7 (from index 3 to 9)
      
     For k = 2,
     The length of the longest sequence is 10 (from index 0 to 9)
      
     For k = 3,
     The length of the longest sequence is 11 (from index 0 to 10)

     */
    void findLongestSequence(int arr[], int n, int k);
};

string SlidingWindow::FindLongestSubStringWithKDistinctCharcters(string str, int k, int len)
{
    
    int end=0, begin=0;
    unordered_set<char> window;
    int freq[CHAR_RANGE] = {0};
    for(int low=0,high=0; high<len; high++)
    {
        window.insert(str[high]);
        freq[str[high]]++;
        if(window.size()>k)
        {
            
            if(--freq[str[low]] == 0)
            {
                window.erase(str[low]);
            }
            low++;
        }
        if((end-begin) < (high-low))
        {
            end = high;
            begin = low;
        }
    }
    return str.substr(begin,end-begin+1);
}

void SlidingWindow::FindAllAnagrams(string X, string Y)
{
    int m,n;
    if((m = (int)Y.length()) > (n = (int)X.length()))
    {
        return;
    }
    
    unordered_multiset<char> window;
    unordered_multiset<char> set;
    for(auto c:Y)
    {
        set.insert(c);
    }

    for(int i=0;i<n;i++)
    {
        if(i<m)
        {
            window.insert(X[i]);
        }
        else
        {
            if(window == set)
            {
                cout<<"Anagram of "<<X.substr(i-m,m)<<" is prsent at index"<<i-m<<endl;
            }
            auto itr  = window.find(X[i-m]);
            if(itr != window.end())
            {
                window.erase(itr);
            }
            window.insert(X[i]);
        }
    }
    if(window == set)
    {
        cout<<"Anagram of "<<X.substr(n-m,m)<<" is prsent at index: "<<n-m<<endl;
    }
    
}

string SlidingWindow::findLongestSubstring(string str, int n)
{
    vector<bool> window(CHAR_RANGE);
    int begin=0, end=0;
    for(int low=0, high=0; high<n; high++)
    {
        if(window[str[high]])
        {
            while(str[low] != str[high])
                window[str[low++]] = false;
            low++;
        }
        else
        {
            window[str[high]]=true;
            if((end-begin)<(high-low))
            {
                end = high;
                begin = low;
            }
        }
    }
    return str.substr(begin,end-begin+1);
}

int SlidingWindow::findIndexofZero(int arr[], int n)
{
    int left = 0;
    int count = 0;
    int max_count=0;
    int max_index=-1;
    int prev_zero_index=0;
    //{ 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            prev_zero_index = i;
            count++;
        }
        if(count == 2)
        {
            while(arr[left])
                left++;
            left++;
            count = 1;
        }
        if((i-left+1) > max_count)
        {
            max_count = i-left+1;
            max_index = prev_zero_index;
        }
    }
    return max_index;
}

void SlidingWindow::findLongestSequence(int arr[], int n, int k)
{
    int left=0;
    int count=0;
    int window=0;
    int leftindex=0;
    for(int right=0;right<n;right++)
    {
        if(arr[right]==0)
        {
            count++;
        }
        while(count>k)
        {
            if(arr[left] == 0)
            {
                count--;
            }
            left++;
        }
        if(right-left+1 > window)
        {
            window = right-left+1;
            leftindex = left;
        }
    }
    if(window == 0)
    {
        return;
    }
    printf("The longest sequence has length %d from index %d to %d", window, leftindex, (leftindex + window - 1));
}

int main(int argc, const char * argv[])
{
    SlidingWindow s;
    /*Find the longest substring of a string containing `k` distinct characters*/
    cout<<"\n\nFind the longest substring of a string containing `k` distinct characters\n\n";
    string str = "abcbdbdbbdcdabd";
    int k = 2;
    int len = (int)str.length();
    cout<<"String: "<<str<<" K: "<<k<<" Length: "<<len<<endl;
    std::cout << s.FindLongestSubStringWithKDistinctCharcters(str, k, len)<<endl;

    /*find all substrings of a string that contains all characters of another string*/
    cout<<"\n\nFind all substrings of a string that contains all characters of another string\n\n";
    string X = "XYYZXZYZXXYZ";
    string Y = "XYZ";
    s.FindAllAnagrams(X, Y);
    
    /*Find the longest substring of a string containing distinct characters*/
    cout<<"\n\nFind the longest substring of a string containing distinct characters\n\n";
    string str1 = "abbcdafeegh";
    int n = (int)str1.length();
    cout << s.findLongestSubstring(str1, n)<<endl;
    
    /*Find maximum length sequence of continuous ones (Using Sliding Window)*/
    cout<<"\n\nFind maximum length sequence of continuous ones (Using Sliding Window)\n\n";
    int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    n = sizeof(arr) / sizeof(arr[0]);
     
    int index = s.findIndexofZero(arr, n);
     
    if (index != -1) {
        printf("Index to be replaced is %d\n", index);
    }
    else {
            printf("Invalid input");
    }
    //Find the maximum sequence of continuous 1’s formed by replacing at-most `k` zeroes by ones
    cout<<"\n\nFind the maximum sequence of continuous 1’s formed by replacing at-most `k` zeroes by ones\n\n";
    int arr1[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
    k = 2;
     
    n = sizeof(arr1) / sizeof(arr1[0]);
     
    s.findLongestSequence(arr1, n, k);
    cout<<"\n";
    return 0;
}
