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
    
    void buildPaths(TreeNode* node, string path, vector<string>& paths) {
        
        if(node == nullptr)
            return;
        
        if(path.length() == 0)
            path = to_string(node -> val);
        else
            path += "->" + to_string(node -> val);
        
        if(node -> left == nullptr && node -> right == nullptr) 
            paths.push_back(path);
        
        buildPaths(node -> left, path, paths);
        buildPaths(node -> right, path, paths);
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> paths;
        
        if(root == nullptr)
            return paths;
                
        buildPaths(root, "", paths);
        
        return paths;
        
    }
    
};