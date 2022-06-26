/*
    FileName: SetMatrixZeroes.cpp
    Created by Jyoti Ranjan on 26/06/22.
    Description:
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do
     it in-place.
     Example 1:
     Input: [
       [1,1,1],
       [1,0,1]
       [1,1,1] ]
     Output: [
           [1,0,1],
           [0,0,0],
           [1,0,1]
     ]
     Example 2:
     Input: [
           [0,1,2,0],
           [3,4,5,2],
           [1,3,1,5]
     ]
     Output: [
           [0,0,0,0],
           [0,4,5,0],
           [0,3,1,0]
     ]
     Follow up:
         A straight forward solution using O(mn) space is probably a bad idea.
         A simple improvement uses O(m + n) space, but still not the best solution.
         Could you devise a constant space solution?
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return;
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        vector<pair<int,int>> zeros;
        vector<bool> isRowZero(nrow, true);
        vector<bool> isColZero(ncol, true);
        for(int i=0; i<nrow; i++)
        {
            for(int j=0; j<nrow; j++)
            {
                if(matrix[i][j] == 0)
                {
                    zeros.emplace_back(i,j);
                }
                else
                {
                    isRowZero[i] = false;
                    isColZero[i] = false;
                }
            }
        }
        for(auto& p: zeros)
        {
            int i = p.first, j = p.second;
            if(!isRowZero[i])
            {
                for(int k=0; k<ncol; k++)
                    matrix[i][k]=0;
                isRowZero[i]=true;
            }
            if(!isColZero[i])
            {
                for(int k=0; k<ncol; k++)
                    matrix[k][j]=0;
                isRowZero[j]=true;
            }
        }
    }
};
