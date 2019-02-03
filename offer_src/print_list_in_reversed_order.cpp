//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
 };
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>vectorOfNum = {};
        if(head == NULL)
            return vectorOfNum;
        stack<int>istack;
        while(head->next!=NULL){
            istack.push(head->val);
            head = head->next;
        }
        istack.push(head->val);
        while(istack.size()){
            vectorOfNum.push_back(istack.top());
            istack.pop();
        }
        return vectorOfNum;
    }
};
//test demo
void Test(char testName[],ListNode* head){
    printf("%s\n",testName);
    printf("printListFromHeadToTail\n");
    ListNode* listNode = head;
    while(listNode){
        printf("%d",listNode->val);
        if(listNode->next != NULL)
            printf(" ");
        listNode = listNode->next;
    }
    printf("\n");
    Solution sol = Solution();
    vector<int>testVector;
    testVector = sol.printListFromTailToHead(head);
    printf("printListFromTailToHead\n");
    for(int i = 0; i < testVector.size(); i++){
        printf("%d",testVector[i]);
        if(i != testVector.size()-1)
            printf(" ");
    }
    printf("\n\n");
}
void Test1(){
    ListNode *head = new ListNode(1);
    ListNode *pNode1 = new ListNode(2);
    ListNode *pNode2 = new ListNode(3);
    ListNode *pNode3 = new ListNode(4);
    head->next = pNode1;
    pNode1->next = pNode2;
    pNode2->next = pNode3;
    Test("Test1",head);
}
void Test2(){
    ListNode *head = new ListNode(1);
    Test("Test2",head);

}
void Test3(){
    ListNode *head = NULL;
    Test("Test3",head);

}
int main(){
    Test1();
    Test2();
    Test3();
//    output
//    Test1
//    printListFromHeadToTail
//    1 2 3 4
//    printListFromTailToHead
//    4 3 2 1
//
//    Test2
//    printListFromHeadToTail
//    1
//    printListFromTailToHead
//    1
//
//    Test3
//    printListFromHeadToTail
//
//    printListFromTailToHead

    return 0;
}
