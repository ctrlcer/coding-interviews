//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
     int NumberOf1(int n) {
         int count = 0;
         unsigned int flag = n;
         while(flag){
            if(flag & 1)
                count++;
            flag>>=1;
         }
         return count;
     }
     int NumberOf1_2(int n){
        int count = 0;
        while(n){
            ++count;
            n = (n-1) & n;
        }
        return count;
     }
};
//test demo
void Test(char testName[],int n,int expectAns){
    Solution s = Solution();
    if(s.NumberOf1(n) == expectAns)
        printf("%s Passed.\n",testName);
    else
        printf("%s Failed.\n",testName);

}
void Test1(){
    Test("Test1",3,2);
}
void Test2(){
    Test("Test2",0,0);
}
void Test3(){
    Test("Test3",-1,32);
}
int main(){
    Test1();
    Test2();
    Test3();
//    output
//    Test1 Passed.
//    Test2 Passed.
//    Test3 Passed.
    return 0;
}
