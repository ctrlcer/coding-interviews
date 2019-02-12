//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    bool g_InvalidInput = false;
    double Power(double base, int exponent) {
        if(equal(base,0.0) && exponent < 0){
            g_InvalidInput = true;
            return 0.0;
        }
        unsigned int absExponent = (unsigned int)(exponent);
        if(exponent < 0)
            absExponent = (unsigned int)(-exponent);
        double result = PowerWithUnsignedExponent(base,absExponent);
        if(exponent < 0)
            result = 1.0 / result;
        return result;
    }
    double PowerWithUnsignedExponent(double base, int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double result = PowerWithUnsignedExponent(base,exponent>>1);
        result *= result;
        if(exponent & 0x1 == 1)
            result *= base;
        return result;
    }
    bool equal(double num1,double num2){
        if(num1 - num2 > -0.000001 && num1 - num2 < 0.000001)
            return true;
        return false;
    }
};
//test demo
void Test(char testName[],double base, int exponent,double expectAns,bool expect_InvalidInput){
    Solution s = Solution();
    if(s.equal(s.Power(base,exponent),expectAns) && expect_InvalidInput == s.g_InvalidInput)
        printf("%s Passed.\n",testName);
    else
        printf("%s Failed.\n",testName);
}
void Test1(){
    Test("Test1",2,3,8,false);
}
void Test2(){
    Test("Test2",2,-1,0.5,false);
}
void Test3(){
    Test("Test3",111,0,1,false);
}
void Test4(){
    Test("Test4",0,-3,0,true);
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
