// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int m=nums.size();
        sort(nums.begin(),nums.end());
        
        if(nums[0]+2*k>nums[m-1])
        {
           return 0;
        }
        else
        {
            return nums[m-1]-2*k-nums[0] ;
        }


    }
};
// @lc code=end

/*******************************************int main()*********************************************/
/**************************************************************************************************/
int main()
{
    Solution S;
    vector<int> nums={1,3,5,4,8,4,3,5};
    int s=S.smallestRangeI(nums,2);
    return 0;
}
