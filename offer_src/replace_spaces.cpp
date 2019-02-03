//请实现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
	    if(str == nullptr || length <= 0)
            return;
        int numOfBlank = 0;
        int lenOfStr = strlen(str);
        for(int i = 0; i < lenOfStr; i++){
            if(str[i] == ' ')
                ++numOfBlank;
        }
        int newLenOfStr = lenOfStr + 2 * numOfBlank;
        if(newLenOfStr > length)
            return;
        int indexOfNewStr = newLenOfStr;
        int indexOfOldStr = lenOfStr;
        while(indexOfOldStr >=0){
            if(str[indexOfOldStr] == ' '){
                str[indexOfNewStr--] = '0';
                str[indexOfNewStr--] = '2';
                str[indexOfNewStr--] = '%';
            }else{
                str[indexOfNewStr--] = str[indexOfOldStr];
            }
            if(indexOfOldStr == indexOfNewStr)
                break;
            --indexOfOldStr;
        }
        return;
	}
};
void Test(char testName[],char str[],int length){
    Solution s = Solution();
    cout<<testName<<endl;
    cout<<"Before replace"<<endl;
    cout<<str<<endl;
    s.replaceSpace(str,length);
    cout<<"After replace"<<endl;
    cout<<str<<endl;
    cout<<endl;
}
//test demo
//str
//We Are Happy
//length 60
void Test1(){
    char testName[] = "Test1";
    char str[60] = "We Are Happy";
    int length = 60;
    Test(testName,str,length);
}
//str
//
//length 60
void Test2(){
    char *testName = "Test2";
    char str[60] = "   ";
    int length = 60;
    Test(testName,str,length);
}
//str
//
//length 60
void Test3(){
    char testName[] = "Test3";
    char str[60] = "";
    int length = 60;
    Test(testName,str,length);
}
//str
//nullptr
//length 60
void Test4(){
    char testName[] = "Test4";
    Test(testName,nullptr,0);
}
int main(){
    Test1();
    Test2();
    Test3();
    Test4();
//    output
//    Test1
//    Before replace
//    We Are Happy
//    After replace
//    We%20Are%20Happy
//
//    Test2
//    Before replace
//
//    After replace
//    %20%20%20
//
//    Test3
//    Before replace
//
//    After replace
//
//
//    Test4
//    Before replace
    return 0;
}
