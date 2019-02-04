//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
     TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0){
            return NULL;
        }
        int rootIndex = 0;
        TreeNode* rootNode = new TreeNode(pre[0]);
        for(int i = 0; i < vin.size();i++){
            if(pre[0] == vin[i]){
                rootIndex = i;
                break;
            }
        }
        vector<int>Lpre;
        vector<int>Lvin;
        vector<int>Rpre;
        vector<int>Rvin;
        for(int i = 1; i < rootIndex + 1; i++)
            Lpre.push_back(pre[i]);

        for(int i = rootIndex + 1; i < pre.size();i++){
            Rpre.push_back(pre[i]);
        }
        for(int i = 0; i < rootIndex; i++)
            Lvin.push_back(vin[i]);
        for(int i = rootIndex+1; i < vin.size();i++)
            Rvin.push_back(vin[i]);
        rootNode->left = reConstructBinaryTree(Lpre,Lvin);
        rootNode->right = reConstructBinaryTree(Rpre,Rvin);

        return rootNode;
    }
};
//test demo
void Lrd(TreeNode *root,vector<int> &vec);
void Test(char testName[],vector<int> pre,vector<int> vin,vector<int>exceptLrd){
    Solution s = Solution();
    TreeNode *rootNode = s.reConstructBinaryTree(pre,vin);
    vector<int>temp;
    Lrd(rootNode,temp);
    for(int i = 0; i < temp.size(); i++)
        if(exceptLrd[i] != temp[i]){
            printf("%s Failed.\n",testName);
            return;
        }
    printf("%s Passed.\n",testName);
}
void Lrd(TreeNode *root,vector<int> &vec){
    if(root == NULL)
        return;
    Lrd(root->left,vec);
    Lrd(root->right,vec);
    vec.push_back(root->val);
}
void Test1(){
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    vector<int> exceptLrd = {7,4,2,5,8,6,3,1};
    Test("Test1",pre,vin,exceptLrd);
}
void Test2(){
    vector<int> pre = {1};
    vector<int> vin = {1};
    vector<int> exceptLrd = {1};
    Test("Test2",pre,vin,exceptLrd);
}
void Test3(){
    vector<int> pre = {};
    vector<int> vin = {};
    vector<int> exceptLrd ={};
    Test("Test3",pre,vin,exceptLrd);
}
int main(){
    Test1();
    Test2();
    Test3();
//    Test1 Passed.
//    Test2 Passed.
//    Test3 Passed.
    return 0;
}
