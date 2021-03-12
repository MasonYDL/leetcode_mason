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
  
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



class Solution 
{
    public:

    int findTilt(TreeNode* root) {
        //563 easy
        int tilt=0;
        helper_563(root,tilt);
        return tilt;
    }
    

    int helper_563(TreeNode* root,int & tilt)
    {
        if(root==nullptr)
            return 0;
        int leftsum=helper_563(root->left,tilt);
        int rightsum=helper_563(root->right,tilt);
        return root->val+leftsum+rightsum;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //669 medium
        if (!root) return root;
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        if (low <= root->val && root->val <= high) return root;
        return root->val < low ? root->right : root->left;
    }
    TreeNode* pre=nullptr;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool left=isValidBST(root->left);
        if(pre!=nullptr && pre->val>=root->val)
        {
            return false;
        }
        bool right=isValidBST(root->right);
        pre=root;
        return left && right;
    }




};


int main()
{
    TreeNode root(1);
    Solution s;
    cout<<s.findTilt(&root)<<endl;
}