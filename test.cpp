#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<math.h>
#include<ext/hash_map>
#include<list>
#include<stdio.h>
#include<map> 
#include<unordered_map>
#include<numeric>
using namespace std;

class Solution{

public:
    int jump(vector<int>& nums) {
        //45 medium
        int res=INT_MAX;
        int cur=0;
        backtrack_45(nums,res,0,cur);
        return res;
    }

    void backtrack_45(vector<int>& nums,int &res, int pos, int &cur)
    {
        if(nums[cur]==0)
            return ;
        if(pos>res)   
        {
            return ;
        }
        if(cur==nums.size()-1)
        {
            if(pos<res)
                res=pos;
            return ;
        }
        for(int i=1;i<=nums[cur] && cur+i<nums.size();++i)
        {
            cur=cur+i;
            backtrack_45(nums,res,pos+1,cur);
            cur=cur-i;
        }
    }
};


    int main()
    {
        Solution s;
        vector<int> res={5,9,3,2,1,0,2,3,3,1,0,0};
        s.jump(res);
    }