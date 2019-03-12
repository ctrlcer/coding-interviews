//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
//0 两个链表进行遍历,将值存入vector进行维护,经过排序后,构造合成的list
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        vector<int> vec_of_all_lists;
        int i = 0;
        while(pHead1){
            vec_of_all_lists.push_back(pHead1->val);
            pHead1 = pHead1->next;
        }
        while(pHead2){
            vec_of_all_lists.push_back(pHead2->val);
            pHead2 = pHead2->next;
        }
        sort(vec_of_all_lists.begin(),vec_of_all_lists.end());
        ListNode *list_of_all_lists = new ListNode(NULL);
        if(vec_of_all_lists.size()==0)
            return nullptr;
        list_of_all_lists->val = vec_of_all_lists[0];
        ListNode *temp_node = list_of_all_lists;
        for(vector<int>::iterator iter = vec_of_all_lists.begin()+1;iter != vec_of_all_lists.end();++iter){//!避免vector.size()大于整数级别
            list_of_all_lists->next = new ListNode(NULL);
            list_of_all_lists->next->val = *iter;
            list_of_all_lists = list_of_all_lists->next;
        }
        return temp_node;
    }
};
//1 非递归写法
class Solution1{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        //定义temp为合成后的表头
        //pHead3为表临时节点
        ListNode* pHead3 = NULL;
        ListNode* temp = NULL;
        //若pHead1和pHead2为空链表，返回空链表
        if(pHead1== NULL && pHead2== NULL)
            return pHead3;
        //若pHead1与pHead2其中一个链表为空链表，则合成的链表就是另一个链表
        if(pHead1== NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        while(pHead1 != NULL && pHead2 != NULL){

            if(pHead1->val >= pHead2->val){
                if(temp == NULL){
                    pHead3 = temp = pHead2;
                }else{
                    pHead3->next = pHead2;
                    pHead3 = pHead3->next;

                }
                pHead2 = pHead2->next;
            }else{
                if(temp == NULL){
                    pHead3 = temp = pHead1;
                }else{
                    pHead3->next = pHead1;
                    pHead3 = pHead3->next;

                }
                pHead1 = pHead1->next;
            }
        }
        //剩余的链表直接连接
        if(pHead1 == NULL){
            pHead3->next = pHead2;
        }
        if(pHead2 == NULL){
            pHead3->next = pHead1;
        }
        return temp;
    }

};
//2 递归写法
class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* result = NULL;
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        if(pHead1->val <= pHead2->val){
            result = pHead1;
            result->next = Merge(pHead1->next,pHead2);
        }else{
            result = pHead2;
            result->next = Merge(pHead1,pHead2->next);
        }
        return result;
    }
};
//test demo

//vector转list
ListNode* vecTolist(vector<int> testlist){
    ListNode* result = NULL;
    for(int i = 0; i < testlist.size(); i++){
        ListNode* temp = new ListNode(testlist[i]);
        if(result == NULL){
            result = temp;
        }else{
            result->next = temp;
        }
        result = result->next;
    }
    return result;
}
void Test(char testName[],vector<int> list1, vector<int> list2, vector<int>explist){
    bool ans = true;
    Solution s = Solution();
    Solution s1 = Solution();
    Solution s2 = Solution();
    ListNode* ans1 = s.Merge(vecTolist(list1),vecTolist(list2));
    ListNode* ans2 = s1.Merge(vecTolist(list1),vecTolist(list2));
    ListNode* ans3 = s2.Merge(vecTolist(list1),vecTolist(list2));
    for(int i = 0; i < explist.size() && ans1 != NULL; i++){
        if(ans1->val != explist[i])
            ans = false;
        ans1= ans1->next;
    }
    for(int i = 0; i < explist.size() && ans2 != NULL; i++){
        if(ans2->val != explist[i])
            ans = false;
        ans2= ans2->next;
    }
    for(int i = 0; i < explist.size() && ans3 != NULL; i++){
        if(ans3->val != explist[i])
            ans = false;
        ans3= ans3->next;
    }
    if(ans){
        printf("%s Passed.\n",testName);
    }else
        printf("%s Failed.\n",testName);
}
void Test1(){
    vector<int> list1 = {1,2,4};
    vector<int> list2 = {1,5};
    vector<int> explist = {1,1,2,4,5};
    Test("Test1",list1,list2,explist);
}
void Test2(){
    vector<int> list1 = {1,1,1,1};
    vector<int> list2 = {1,1,1,1};
    vector<int> explist = {1,1,1,1,1,1,1,1};
    Test("Test2",list1,list2,explist);
}
void Test3(){
    vector<int> list1 = {NULL};
    vector<int> list2 = {NULL};
    vector<int> explist = {NULL};
    Test("Test3",list1,list2,explist);
}
void Test4(){
    vector<int> list1 = {NULL};
    vector<int> list2 = {1,2,2,3,4};
    vector<int> explist = {1,2,2,3,4};
    Test("Test4",list1,list2,explist);
}
int main(){
    Test1();
    Test2();
    Test3();
    Test4();
//    output
//    Test1 Passed.
//    Test2 Passed.
//    Test3 Passed.
//    Test4 Passed.
    return 0;
}
