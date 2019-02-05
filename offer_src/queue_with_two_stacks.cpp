//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<exception>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int popNode;
        if(stack2.size()){
            popNode = stack2.top();
            stack2.pop();
        }else{
            while(stack1.size()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            popNode = stack2.top();
            stack2.pop();
        }
        return popNode;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
//test demo
void Test(char testName[],vector<int>testPop,vector<int>expectPop){
    if(testPop.size() != expectPop.size()){
        printf("%s Failed\n",testName);
        return;
    }
    for(int i = 0; i < testPop.size(); ++i){
        if(testPop[i] != expectPop[i]){
            printf("%s Failed\n",testName);
            return;
        }
    }
    printf("%s Passed\n",testName);
    return;
}
void Test1(){
    Solution s = Solution();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    vector<int>testPop;
    testPop.push_back(s.pop());
    testPop.push_back(s.pop());
    testPop.push_back(s.pop());
    testPop.push_back(s.pop());
    vector<int>expectPop = {1,2,3,4};
    Test("Test1",testPop,expectPop);
}
void Test2(){
    Solution s = Solution();
    s.push(1);
    vector<int>testPop;
    testPop.push_back(s.pop());
    vector<int>expectPop = {1};
    Test("Test2",testPop,expectPop);
}
void Test3(){
    Solution s = Solution();
    s.push(1);
    vector<int>testPop;
    testPop.push_back(s.pop());
    s.push(2);
    testPop.push_back(s.pop());
    s.push(1);
    testPop.push_back(s.pop());
    vector<int>expectPop = {1,2,1};
    Test("Test3",testPop,expectPop);
}
int main(){
    Test1();
    Test2();
    Test3();
//    output
//    Test1 Passed
//    Test2 Passed
//    Test3 Passed
    return 0;
}
