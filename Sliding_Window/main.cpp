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
    
    /*Find minimum sum subarray of size `k`
     
     Given an integer array, find the minimum sum subarray of size k, where k is a positive integer.

     For example,

     Input: {10, 4, 2, 5, 6, 3, 8, 1}, k = 3
      
     Output: Minimum sum subarray of size 3 is (1, 3)
     */
     void findSubarray(int arr[], int n, int k);
    
     /*
      Find a subarray having the given sum in an integer array
      Given an integer array, find a subarray having a given sum in it.

      For example,

      Input: nums[] = {2, 6, 0, 9, 7, 3, 1, 4, 1, 10}, target = 15
      Output: {6, 0, 9}
       
       
      Input: nums[] = {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10}, target = 15
      Output: {1, -4, 7, 6, 1, 4} or {4, 1, 10}
       
       
      Input: nums[] = {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10}, target = -3
      Output: {1, -4} or {-7, 1, -4, 7}
      */
     void findSubArrayGivenSum(int nums[], int n, int target);
    
    /*
     Find the smallest subarray length whose sum of elements is greater than `k`
     Given an array of positive integers, find the smallest subarray’s length whose sum of elements is greater than a given number k.

     For example,

     Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 20
     Output: The smallest subarray length is 3
     Explanation: The smallest subarray with sum > 20 is {6, 7, 8}
      
      
     Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 7
     Output: The smallest subarray length is 1
     Explanation: The smallest subarray with sum > 7 is {8}
      
      
     Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 21
     Output: The smallest subarray length is 4
     Explanation: The smallest subarray with sum > 21 is {5, 6, 7, 8}
      
      
     Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 40
     Output: No subarray exists
     */
    int findSmallestSubarrayLen(int arr[], int n, int k);
    
    /*
     Find the count of distinct elements in every subarray of size `k`
     Given an array and an integer k, find the count of distinct elements in every subarray of size k.
     Input:
      
     arr[] = { 2, 1, 2, 3, 2, 1, 4, 5 };
     k = 5;
      
     Output:
      
     The count of distinct elements in subarray { 2, 1, 2, 3, 2 } is 3
     The count of distinct elements in subarray { 1, 2, 3, 2, 1 } is 3
     The count of distinct elements in subarray { 2, 3, 2, 1, 4 } is 4
     The count of distinct elements in subarray { 3, 2, 1, 4, 5 } is 5
    */
    void findDistinctCountUsingSet(vector<int> const &input,int k);
    void findDistinctCountUsingMap(vector<int> const &input,int k);
    
    /*
     Print all subarrays of an array having distinct elements
     Given an integer array, print all maximum size subarrays having all distinct elements in them.

     For example,

     Input: A[] = { 5, 2, 3, 5, 4, 3 }
      
     Output: The largest subarrays with all distinct elements are:
      
     { 5, 2, 3 }
     { 2, 3, 5, 4 }
     { 5, 4, 3 }
    */
    
    void printSubarray(int A[], int i, int j, int n);
    void calculate(int A[], int n);
    /*
     Count distinct absolute values in a sorted array
     Given an array of sorted integers that may contain several duplicate elements, count the total number of distinct absolute values in it.

     For example,

     Input: { -1, -1, 0, 1, 1, 1 }
     Output: The total number of distinct absolute values is 2 (0 and 1)
      
      
     Input: { -2, -1, 0, 1, 2, 3 }
     Output: The total number of distinct absolute values is 4 (0, 1, 2 and 3)
      
      
     Input: { -1, -1, -1, -1 }
     Output: The total number of distinct absolute values is 1 (only 1)

     */
    int findDistinctCountUsingSet(vector<int> &input);
    int findDistinctCountWitUsingSet(vector<int> const &input);
    
    /*Given an array and a positive number k, check whether the array contains any duplicate elements within the range k. If k is more than the array’s size, the solution should check for duplicates in the complete array.
     
     For example,

     Input:
      
     nums[] = { 5, 6, 8, 2, 4, 6, 9 }
     k = 4
      
     Output: Duplicates found
      
     (element 6 repeats at distance 4 which is <= k)
      
      
     Input:
      
     nums[] = { 5, 6, 8, 2, 4, 6, 9 }
     k = 2
      
     Output: No duplicates were found
      
     (element 6 repeats at distance 4 which is > k)
      
      
     Input:
      
     nums[] = { 1, 2, 3, 2, 1 }
     k = 7
      
     Output: Duplicates found
      
     (element 1 and 2 repeats at distance 4 and 2, respectively which are both <= k)*/
    bool contains(unordered_set<int> const &set, int x);
    bool hasDuplicate(vector<int> &input, int k);
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

void SlidingWindow::findSubarray(int arr[], int n, int k)
{
    int left_index = 0;
    int sum=0, start_index=-1;
    int min_sum=INT_MAX;
    
    if(k>n)
    {
        cout<<"Invalid Array Size:"<<endl;
        return ;
    }
    
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if((i-k) == left_index)
        {
            sum -= arr[left_index];
            //cout<<"SUM: "<<sum<<endl;
            left_index++;
            if(sum<min_sum)
            {
                min_sum = sum;
                start_index = left_index;
            }
        }
        
    }
    cout<<"Minimum sum is: "<<min_sum<<endl;
    cout<<"Minimum sum subarray of a given size "<<k<<" starts from "<<start_index<<" to "<<start_index+k-1<<endl;
}

void SlidingWindow::findSubArrayGivenSum(int nums[], int n, int target)
{
    int windowsum = 0;
    //int low = 0, high=0;
    for(int high=0,low=0; low <n ;low++)
    {
        while((windowsum < target) && (high < n))
        {
            windowsum += nums[high];
            high++;
        }
        if(windowsum == target)
        {
            cout<<"Subarray Found from "<<low<<" to "<<high-1<<endl;
        }
        windowsum -= nums[low];
    }
}

int SlidingWindow::findSmallestSubarrayLen(int arr[], int n, int k)
{
    int left_index=0;
    int len = INT_MAX;
    int sum = 0;
    for(int right_index=0; right_index < n; right_index++)
    {
        sum += arr[right_index];
        while((sum > k) && (left_index <= right_index))
        {
            len = min(len,(right_index - left_index) + 1);
            sum -= arr[left_index];
            left_index++;
        }
    }
    if(len == INT_MAX)
        return 0;
    return len;
}

void SlidingWindow::findDistinctCountUsingSet(vector<int> const &input,int k)
{
    for(int i=0; i<input.size(); i++)
    {
        unordered_set<int> distinct(input.begin()+i ,input.begin()+i+k);
        cout<<"The count of distinct element of sub array ["<< i <<", "<<(i+k - 1)<<"] is "<<distinct.size()<<endl;
    }
}
void SlidingWindow::findDistinctCountUsingMap(vector<int> const &input,int k)
{
    unordered_map<int,int> freq;
    int distinct=0;
    for(int i=0; i<input.size(); i++)
    {
        if(i>=k)
        {
            freq[input[i-k]]--;
            if(freq[input[i-k]] == 0)
            {
                distinct--;
            }
        }
        freq[input[i]]++;
        if(freq[input[i]] == 1)
        {
            distinct++;
        }
        if(i >= k-1)
        {
            cout<<"The count of distinct elements in subarray [" <<(i-k+1)<<", "<<i<<"] is "<<distinct<<endl;
        }
    }
}

void SlidingWindow::printSubarray(int A[], int i, int j, int n)
{
    if (i < 0 || i > j || j >= n) {        // invalid input
            return;
    }
    for (int index = i; index < j; index++) {
            cout << A[index] << ", ";
        }
    cout << A[j] << endl;
}

void  SlidingWindow::calculate(int A[], int n)
{
    unordered_map<int,bool> visited;
    int right = 0 , left = 0;
    while(right < n)
    {
        while(right < n && !visited[A[right]])
        {
            visited[A[right]] = true;
            right ++;
        }
        printSubarray(A, left, right-1, n);
        while(right<n && visited[A[right]])
        {
            visited[A[left]] = false;
            left++;
        }
    }
}

bool SlidingWindow::contains(unordered_set<int> const &set, int x)
{
    return set.find(x) != set.end();
}

bool SlidingWindow::hasDuplicate(vector<int> &input, int k)
{
    unordered_set<int> window;
    for(int i=0; i<input.size(); i++)
    {
        if(contains(window, input[i]))
        {
            return true;
        }
        window.insert(input[i]);
        if(i>=k)
        {
            window.erase(input[i-k]);
        }
    }
    return false;
}

int SlidingWindow::findDistinctCountUsingSet(vector<int> &input)
{
    unordered_set<int> distinctSet;
    for(int const &i: input)
    {
        distinctSet.insert(abs(i));
    }
    return (int)distinctSet.size();
}
int  SlidingWindow::findDistinctCountWitUsingSet(vector<int> const &input)
{
   
    int distinct_count = (int)input.size();

    int left = 0;
    int right = (int)input.size() - 1;

    while (left < right)
    {

        while (left < right && input[left] == input[left + 1])
        {
            distinct_count--;
            left++;
        }
        while (right > left && input[right] == input[right - 1])
        {
            distinct_count--;
            right--;
        }
 
  
        if (left == right) {
            break;
        }
 
        int sum = input[left] + input[right];

        if (sum == 0)
        {
            distinct_count--;
            left++;
            right--;
        }
     
        else if (sum < 0) {
            left++;
        }

        else {
            right--;
        }
    }
 
    return distinct_count;
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
    
    /*Find minimum sum subarray of size `k`*/
    cout<<"\n\nFind Find minimum sum subarray of size `k`\n\n";
    int arr2[] = { 10, 4, 2, 5, 6, 3, 8, 1 };
    k = 3;
    n = sizeof(arr2)/sizeof(arr2[0]);
    s.findSubarray(arr, n, k);
    
    //Find a subarray having the given sum in an integer array
    int nums[] = { 2, 6, 0, 9, 7, 3, 1, 4, 1, 10 };
    int target = 15;
    cout<<"\n\nFind a subarray having the given sum "<<target<<" in an integer array\n\n";
    n = sizeof(nums)/sizeof(nums[0]);
     
    s.findSubArrayGivenSum(nums, n, target);
    
    
    /*
        Find the smallest subarray length whose sum of elements is greater than `k`
     */
   
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    k = 21;
     
    n = sizeof(array) / sizeof(array[0]);
    cout<<"\n\nFind a subarray having the given sum "<<k<<" in an integer array\n\n";
    len = s.findSmallestSubarrayLen(array, n, k);
    
    if (len != INT_MAX) {
            printf("The smallest subarray length is %d\n\n\n", len);
    }
    else {
            printf("No subarray exists\n");
    }
    
    /*
      Find the count of distinct elements in every subarray of size `k`
     */
    vector<int> input = { 2, 1, 2, 3, 2, 1, 4, 5 };
    k = 5;
    cout<<"\n\nFind the count of distinct elements in every subarray of size"<<k<<" in an integer Vector\n\n";
    s.findDistinctCountUsingSet(input, k);
    s.findDistinctCountUsingMap(input, k);
    
    /*
     Print all subarrays of an array having distinct elements
     */
    cout<<"\n\nPrint all subarrays of an array having distinct elements \n\n";
    int A[] = { 5, 2, 3, 5, 4, 3 };
    n = sizeof A / sizeof A[0];
    s.calculate(A, n);
    
    vector<int> input1 = { -1, -1, 0, 1, 1, 1 };
    cout << "The total number of distinct absolute values is " << s.findDistinctCountUsingSet(input1)<<endl;
    cout << "The total number of distinct absolute values is " << s.findDistinctCountWitUsingSet(input1)<<endl;
    
    /*
     Find duplicates within a range `k` in an array
     */
    vector<int> input2 = { 5, 6, 8, 2, 4, 6, 9 };
    k = 4;
    
    cout << "Find duplicates within a range `k` in an array"<<endl;
    if (s.hasDuplicate(input2, k))
    {
            cout << "Duplicates found\n";
    }
    else
    {
            cout << "No duplicates were found\n";
    }
    return 0;
}
