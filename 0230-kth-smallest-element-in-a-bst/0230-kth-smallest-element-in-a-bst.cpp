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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        inorder=getinorder(root,inorder);
        int count=0;
        for(int i=0;i<inorder.size();i++){
            count++;
            if(count==k){
                return inorder[i];
            }
        }
        return -1;
    }

    vector<int> getinorder(TreeNode*root,vector<int>&inorder){
        TreeNode*cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode*prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};