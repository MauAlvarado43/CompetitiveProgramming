/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        vector<int> temp;
        bool isBST = true;
        
        while(s.size() || node != nullptr) {
            
            while(node != nullptr) {
                s.push(node);
                node = node -> left;
            }
            
            node = s.top();
            s.pop();
            
            if(temp.size() > 0 && (node -> val) <= temp.back()) {
                isBST = false;
                break;
            }
            
            temp.push_back(node -> val);
            
            node = node -> right;            
            
        }
        
        return isBST;
        
    }
};