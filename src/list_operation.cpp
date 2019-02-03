#include<cstdio>
using namespace std;
struct ListNode{
    int m_value;
    ListNode* m_pNext;
};
void AddToTail(ListNode** pHead, int value){
    ListNode* pNew = new ListNode();
    pNew->m_value = value;
    pNew->m_pNext = nullptr;
    if(*pHead == nullptr){
        *pHead = pNew;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr){
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}
void RemoveNode(ListNode** pHead,int value){
    if(pHead == nullptr || *pHead == nullptr)
        return;
    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->m_value == value){
        pToBeDeleted = *pHead;
        (*pHead) = (*pHead)->m_pNext;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_value != value){
            pNode = pNode->m_pNext;
            if(pNode->m_pNext != nullptr && pNode->m_pNext->m_value == value){
                pToBeDeleted = pNode->m_pNext;
                pNode->m_pNext = pNode->m_pNext->m_pNext;
            }
        }

    }
    if(pToBeDeleted != nullptr){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
int main(){
    return 0;
}
