//  Two_Sum.cpp
//  
//
//  Created by Jyoti Ranjan on 26/06/22.
/*Given an array of integers, return indices of the two numbers such that they add
up to a specific target.
You may assume that each input would have exactly one solution, and you may not
use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int end = nums.size()-1,i=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return {i,mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
int main()
{
    Solution s;
    vector<int> vres = {3,2,4};
    vector<int> vres_=s.twoSum(vres,6);
    for(auto v:vres_)
        cout<<v<<endl;
    return 0;
}

