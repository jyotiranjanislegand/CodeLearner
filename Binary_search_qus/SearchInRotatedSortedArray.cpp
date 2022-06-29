

/*
    SearchInRotatedSortedArray.cpp
    Created by Jyoti Ranjan on 28/06/22.

    There is an integer array nums sorted in ascending order (with distinct values).
    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
     Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
    You must write an algorithm with O(log n) runtime complexity.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (high+low)/2;
            if(target == nums[mid])
                return mid;
            if(nums[mid] <= nums[high])
            {
                if((target > nums[mid]) && (target <= nums[high]))
                {
                    low = mid +1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if((target >= nums[low]) && (target < nums[mid]))
                {
                    high = mid-1;
                }
                else
                {
                    low = mid +1;
                }
            }
        }
        return -1;
    }
};

int main(void)
{
    int num[] = {9, 10, 11, 2, 5, 6, 8};
    int target = 10;
    Solution s;
    vector<int> nums(num,num+6);
    int n = sizeof(nums)/sizeof(nums[0]);
    int index = s.search(nums, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}
