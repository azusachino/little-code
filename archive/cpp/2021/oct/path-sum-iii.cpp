#include "common.h"

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

private:
    int sumUp(TreeNode *root, int pre, int &sum)
    {
        if (!root)
        {
            return 0;
        }
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};