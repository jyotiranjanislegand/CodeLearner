/*    The maximum-subarray problem: it takes as input an array of numbers, and it determines the contiguous subarray whose values have the greatest sum.The maximum-subarray problem: it takes as input an array of numbers, and it determines the contiguous subarray whose values have the greatest sum.
    
        /***************************************************************************************************************************
        *****************************************Maximum SubArray Problem***********************************************************
        ****************************************************************************************************************************
    Example:
    ----------
    Day 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    Price 100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97
    Change 13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
    
          /\
    	 /  \
    	/    \
    	 |  |
    	 |  |
    
    Information about the price of stock in the Volatile Chemical Corporation after the close
    of trading over a period of 17 days. The horizontal axis of the chart indicates the day, and the vertical
    axis shows the price. The bottom row of the table gives the change in price from the previous day.
     
    
    
    Day 01 23 4
    Price 10 11 7 10 6
    Change 1 -4 3 -4
          /\
    	 /  \
    	/    \
    	 |  |
    	 |  |
    An example showing that the maximum profit does not always start at the lowest price
    or end at the highest price. Again, the horizontal axis indicates the day, and the vertical axis shows
    the price. Here, the maximum profit of $3 per share would be earned by buying after day 2 and
    selling after day 3. The price of $7 after day 2 is not the lowest price overall, and the price of $10
    after day 3 is not the highest price overall.
    
    
    A brute-force solution
    We can easily devise a brute-force solution to this problem: just try every possible
    pair of buy and sell dates in which the buy date precedes the sell date. A period of n
    days has (n/2) such pairs of dates. Since n/2
    is (Θ)n2 and the best we can hope for
    is to evaluate each pair of dates in constant time, this approach would take Ω(n2)
    time.  We Can do better.
    
    Let’s think about how we might solve the maximum-subarray problem using
    the divide-and-conquer technique. Suppose we want to find a maximum subarray of the subarray A[Low to High]
    Divide-and-conquer suggests that we divide
    the subarray into two subarrays of as equal size as possible.That is, we find
    the midpoint, say mid, of the subarray, and consider the subarrays A[Low to mid] A[mid+1 to high] 
    any contiguous subarray A[i..j]
    of A[Low to High] must lie in exactly one of the following places
    entirely in the subarray : A[Low to mid] so that low<= i <= j <= mid
    entirely in the subarray: A[mid+1 to high] so that mid<= i <= j <= high
    crossing the midpoint, so that low <= i <= mid < j <= high.
    
    We are considering crossing the midpoint becuase there is chance that our max arry must be crosing the mid point in above exmaple max array will be 18 20 -7 12
     from inde 7 to index 10
	 
        */
        #include <iostream>
        #include <algorithm>
        #include <bits/stdc++.h>
        using namespace std;
        struct result
        {
            int m_left;
            int m_right;
            int m_LeftRightSum;
            void print()
            {
                cout<<"leftIndex:"<<m_left<<endl;
                cout<<"rightIndex:"<<m_right<<endl;
                cout<<"sum:"<<m_LeftRightSum<<endl;
            }
        };
        result maxCrossSubArray(int arr[], int low, int mid, int high);
        result maxSubArray(int arr[], int low, int high);
        
        result maxCrossSubArray(int arr[], int low, int mid, int high)
        {
            result obj;
            int leftSum = INT_MIN;
            int sum = 0;
            int maxLeft,maxRight;
            for(int i=mid;i>=low;i--)
            {
                sum +=arr[i];
                if(sum>leftSum)
                {
                    leftSum = sum;
                    maxLeft = i;
                }
            }
            sum = 0;
            int rightSum=INT_MIN;
            for(int j=mid+1;j<=high;j++)
            {
                sum +=arr[j];
                if(sum>rightSum)
                {
                    rightSum = sum;
                    maxRight = j;
                }
        
            }
            obj.m_left = maxLeft;
            obj.m_right = maxRight;
            obj.m_LeftRightSum = leftSum + rightSum;
            //obj.print();
            return obj;
        }
        result maxSubArray(int arr[], int low, int high)
        {
            result objLeft,objRight,objCross;
            if(high == low)
            {
                result obj;
                obj.m_left = low;
                obj.m_right = high;
                obj.m_LeftRightSum = arr[low];
                return obj;
            }
            else
            {
                int mid = (low + high)/2;
                objLeft =  maxSubArray(arr,low,mid);
                objRight = maxSubArray(arr,mid+1,high);
                objCross = maxCrossSubArray(arr,low,mid,high);
            }
            if(objLeft.m_LeftRightSum >= objRight.m_LeftRightSum &&  objLeft.m_LeftRightSum >= objCross.m_LeftRightSum)
                return objLeft;
            else if(objRight.m_LeftRightSum >= objLeft.m_LeftRightSum &&  objRight.m_LeftRightSum >= objCross.m_LeftRightSum)
                return objRight;
            else
                return objCross;
        
        }
        int main()
        {
            
            int arr[] = { { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};};
            for(auto i : arr)
                cout<<i<<" ";
            cout<<endl;
            cout<<sizeof(arr)/sizeof(arr[0])<<endl;
            result obj = maxSubArray(arr,0,8);
        
            cout<<"Maximum sub array will be from:"<<obj.m_left<<" to:  "<<obj.m_right<<" and sum is:"<<obj.m_LeftRightSum<<endl;
            return 0;
        }