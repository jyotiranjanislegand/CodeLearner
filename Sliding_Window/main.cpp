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
    
    /*Find the longest substring of a string containing distinct characters*/
    
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
        cout<<"Anagram of "<<X.substr(n-m,m)<<" is prsent at index"<<n-m<<endl;
    }
    
}

int main(int argc, const char * argv[])
{
    SlidingWindow s;
    /*Find the longest substring of a string containing `k` distinct characters*/
    string str = "abcbdbdbbdcdabd";
    int k = 2;
    int len = (int)str.length();
    cout<<"String: "<<str<<" K: "<<k<<" Length: "<<len<<endl;
    std::cout << s.FindLongestSubStringWithKDistinctCharcters(str, k, len)<<endl;
    
    /*find all substrings of a string that contains all characters of another string*/
    string X = "XYYZXZYZXXYZ";
    string Y = "XYZ";
    s.FindAllAnagrams(X, Y);
    
    return 0;
}
