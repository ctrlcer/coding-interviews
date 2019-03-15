#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        //若该节点为空直接返回
        if(pRoot == NULL)
            return;
        //若该节点的左节点和右节点都为空，直接返回
        if(pRoot->left==NULL && pRoot->right == NULL)
            return;
        //将以该节点的左节点为树根的二叉树 将其变换为源二叉树的镜像
        Mirror(pRoot->left);
        //将以该节点的右节点为树根的二叉树 将其变换为源二叉树的镜像
        Mirror(pRoot->right);
        //左右节点交换
        TreeNode *pTemp = NULL;
        pTemp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = pTemp;
    }
};
//测试只要我们得到的二叉树的镜像前序 中序 后序跟我们设想的一致 那么就证明结果正确的

//前序遍历
vector<int>pre_vec;
//中序遍历
vector<int>in_vec;
//后序遍历
vector<int>las_vec;

void pre_binaryT(TreeNode* pRoot){
    if(pRoot==NULL)
        return;
    pre_vec.push_back(pRoot->val);
    pre_binaryT(pRoot->left);
    pre_binaryT(pRoot->right);
}


void in_binaryT(TreeNode* pRoot){
    if(pRoot==NULL)
        return;
    in_binaryT(pRoot->left);
    in_vec.push_back(pRoot->val);
    in_binaryT(pRoot->right);
}

void las_binaryT(TreeNode* pRoot){
    if(pRoot==NULL)
        return;
    las_binaryT(pRoot->left);
    las_binaryT(pRoot->right);
    las_vec.push_back(pRoot->val);

}
//test demo
void Test(char testName[],TreeNode* pRoot1,vector<int>exp_pre,vector<int>exp_in,vector<int>exp_las){
    pre_vec.clear();
    in_vec.clear();
    las_vec.clear();
    Solution s = Solution();
    s.Mirror(pRoot1);
    pre_binaryT(pRoot1);
    in_binaryT(pRoot1);
    las_binaryT(pRoot1);
    bool exp_ans = true;
    if(exp_pre.size()!= pre_vec.size() || exp_in.size() != in_vec.size() || exp_las.size() != las_vec.size()){
        printf("%s Failed.\n",testName);
        return;
    }
    for(int i = 0; i < exp_pre.size(); i++){
        if(pre_vec[i] != exp_pre[i]){
            exp_ans = false;
            break;
        }
    }
    for(int i = 0; i < exp_in.size();  i++){
        if(in_vec[i] != exp_in[i]){
            exp_ans = false;
            break;
        }
    }
    for(int i = 0; i < exp_las.size();  i++){
        if(las_vec[i] != exp_las[i]){
            exp_ans = false;
            break;
        }
    }
    if(!exp_ans){
        printf("%s Failed.\n",testName);
    }else{
        printf("%s Passed.\n",testName);
    }
}
//
//    4
//   / \
//  1   5
// / \ / \
// 2 3 6 7

//mirror_of_binaryTree
//    4
//   / \
//  5   1
// / \ / \
// 7 6 3 2


//pre  4 5 7 6 1 3 2
//in   7 5 6 4 3 1 2
//las  7 6 5 3 2 1 4
void Test1(){
    TreeNode *listNode1  = new TreeNode(4);
    TreeNode *listNode2  = new TreeNode(1);
    TreeNode *listNode3  = new TreeNode(5);
    TreeNode *listNode4  = new TreeNode(2);
    TreeNode *listNode5  = new TreeNode(3);
    TreeNode *listNode6  = new TreeNode(6);
    TreeNode *listNode7  = new TreeNode(7);
    listNode1->left = listNode2;
    listNode1->right = listNode3;
    listNode2->left  = listNode4;
    listNode2->right = listNode5;
    listNode3->left = listNode6;
    listNode3->right = listNode7;
    Test("Test1",listNode1,{4,5,7,6,1,3,2},{7,5,6,4,3,1,2},{7,6,5,3,2,1,4});
}
//
//    NULL
//

//mirror_of_binaryTree
//    NULL
//


//pre  NULL
//in   NULL
//las  NULL
void Test2(){
    TreeNode *listNode1  = NULL;
    Test("Test2",listNode1,{},{},{});
}
//
//      4
//     /
//    1
//   /
//  5
// /
//2
//mirror_of_binaryTrees

//      4
//       \
//        1
//         \
//          5
//           \
//            2
//pre  4 1 5 2
//in   4 1 5 2
//las  2 5 1 4
void Test3(){
    TreeNode *listNode1  = new TreeNode(4);
    TreeNode *listNode2  = new TreeNode(1);
    TreeNode *listNode3  = new TreeNode(5);
    TreeNode *listNode4  = new TreeNode(2);
    listNode1->left = listNode2;
    listNode2->left = listNode3;
    listNode3->left = listNode4;
    Test("Test3",listNode1,{4,1,5,2},{4,1,5,2},{2,5,1,4});
}
//      4
//       \
//        1
//         \
//          5
//           \
//            2

//mirror_of_binaryTrees

//      4
//     /
//    1
//   /
//  5
// /
//2
//pre  4 1 5 2
//in   2 5 1 4
//las  2 5 1 4
void Test4(){
    TreeNode *listNode1  = new TreeNode(4);
    TreeNode *listNode2  = new TreeNode(1);
    TreeNode *listNode3  = new TreeNode(5);
    TreeNode *listNode4  = new TreeNode(2);
    listNode1->right = listNode2;
    listNode2->right = listNode3;
    listNode3->right = listNode4;
    Test("Test4",listNode1,{4,1,5,2},{2,5,1,4},{2,5,1,4});
}
int main(){
    Test1();
    Test2();
    Test3();
    Test4();
//output
//Test1 Passed.
//Test2 Passed.
//Test3 Passed.
//Test4 Passed.
    return 0;
}
