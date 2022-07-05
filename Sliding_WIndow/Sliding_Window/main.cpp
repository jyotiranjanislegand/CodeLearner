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
    string FindLongestSubStringWithKDistinctCharcters(string str, int k, int len);
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

int main(int argc, const char * argv[])
{
    SlidingWindow s;
    string str = "abcbdbdbbdcdabd";
    int k = 2;
    int len = (int)str.length();
    cout<<"--------Parameter Passed--------"<<endl;
    cout<<"String: "<<str<<" K: "<<k<<" Length: "<<len<<endl;
    std::cout << s.FindLongestSubStringWithKDistinctCharcters(str, k, len)<<endl;
    return 0;
}
