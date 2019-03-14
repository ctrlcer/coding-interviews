#include<iostream>
#include<cstdio>
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
    //pRoot1 A树 pRoot2 B树
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
//        cout<<"pRoot1 val:"<<pRoot1->val<<endl;
//        cout<<"pRoot2 val:"<<pRoot2->val<<endl;

        //若有空树直接不满足flase
        if(pRoot2==NULL || pRoot1==NULL) return false;
        bool result = false;
        //如果遍历到的A B树根节点值相等,则以该A,B树根节点进行判断
        if(pRoot1->val == pRoot2->val)
            result =  DoseTree1HasTree2(pRoot1,pRoot2);
        //如果不满足,遍历A的左子节点为根节点,是否包含B树
        if(!result){
            result = HasSubtree(pRoot1->left,pRoot2);
        }
        //如果不满足,遍历A的右子节点为根节点,是否包含B树
        if(!result){
            result = HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
    bool DoseTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        //如果B树节点为NULL，则B树的所有节点都遍历过了 满足条件
        if(pRoot2==NULL)
            return true;
        //如果A树节点为NULL，则B树的所有节点还没遍历完 A就遍历完了 不满足条件
        if(pRoot1==NULL)
            return false;
        bool result = true;
        //如果当前A树节点 不等于 B树节点 不满足条件
        if(pRoot1->val != pRoot2->val)
            result =  false;
        //分别遍历树的左右节点
        //递归
        if(result)
            result = DoseTree1HasTree2(pRoot1->left,pRoot2->left);
        if(result)
            result = DoseTree1HasTree2(pRoot1->right,pRoot2->right);
        return result;
    }
};
//test demo
void Test(char testName[],TreeNode* pRoot1,TreeNode* pRoot2,bool exp){
    Solution s = Solution();
    if(s.HasSubtree(pRoot1,pRoot2) == exp)
        printf("%s Passed.\n",testName);
    else
        printf("%s Failed.\n",testName);
}
//A:
//    4
//   / \
//  1   5
// / \ / \
// 2 3 6 7
//B:
//    1
//   / \
//  2   3

//exp:true
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
    //
    TreeNode *rlistNode1  = new TreeNode(1);
    TreeNode *rlistNode2  = new TreeNode(2);
    TreeNode *rlistNode3  = new TreeNode(3);
    rlistNode1->left = rlistNode2;
    rlistNode1->right = rlistNode3;

    Test("Test1",listNode1,rlistNode1,true);
}
//A:
//    4
//   / \
//  1   5
// /
// 2
//B:
//    NULL
//
//

//exp:false
void Test2(){
    TreeNode *listNode1  = new TreeNode(4);
    TreeNode *listNode2  = new TreeNode(1);
    TreeNode *listNode3  = new TreeNode(5);
    TreeNode *listNode4  = new TreeNode(2);
    listNode1->left = listNode2;
    listNode1->right = listNode3;
    listNode2->left  = listNode4;
    //
    TreeNode *rlistNode1  = NULL;

    Test("Test2",listNode1,rlistNode1,false);
}
//A:
//    NULL
//B:
//    NULL
//exp:false
void Test3(){
    TreeNode *listNode1  =  NULL;
    TreeNode *rlistNode1  = NULL;

    Test("Test3",listNode1,rlistNode1,false);
}
//A:
//    4
//   / \
//  1   5
// / \ / \
// 2 3 6 7
//B:
//    5
//   / \
//  6   7

//exp:true
void Test4(){
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

    TreeNode *rlistNode1  = new TreeNode(5);
    TreeNode *rlistNode2  = new TreeNode(6);
    TreeNode *rlistNode3  = new TreeNode(7);
    rlistNode1->left = rlistNode2;
    rlistNode1->right = rlistNode3;

    Test("Test4",listNode1,rlistNode1,true);
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
