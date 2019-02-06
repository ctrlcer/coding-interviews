//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution{
public:
    //O(logn)
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        int index1 = 0;
        int index2 = rotateArray.size()-1;
        int midIndex = index1;
        while(rotateArray[index1] >= rotateArray[index2]){
            if(index2 - index1 == 1){
                midIndex = index2;
                break;
            }
            midIndex = (index1 + index2)/2;
            if(rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[midIndex])
                return minNumberInOrder(rotateArray,index1,index2);
            if(rotateArray[midIndex] >= rotateArray[index1]){
                index1 = midIndex;
            }else if(rotateArray[midIndex] <= rotateArray[index2]){
                index2 = midIndex;
            }

        }
        return rotateArray[midIndex];
    }
    int minNumberInOrder(vector<int> rotateArray,int index1,int index2){
        int minNum = rotateArray[index1];
        for(int i = index1; i <= index2; i++){
            minNum = min(minNum,rotateArray[i]);
        }
        return minNum;
    }
    //O(n)
    int minNumberInRotateArray2(vector<int> rotateArray) {
        int lastIndex = rotateArray.size();
        if(lastIndex == 0)
            return 0;
        int minNum = rotateArray[lastIndex-1];
        for(int i = lastIndex - 1; i >= 1; i--){
            if(rotateArray[i-1]>rotateArray[i]){
                break;
            }else{
                minNum = rotateArray[i-1];
            }
        }
        return minNum;
    }
};
//test demo
void Test(char testName[],vector<int>rotateArray,int expectAns){
    Solution s = Solution();
    if(s.minNumberInRotateArray(rotateArray) == expectAns)
        printf("%s Passed.\n",testName);
    else
        printf("%s Failed.\n",testName);
}
void Test1(){
    vector<int>rotateArray = {3,4,5,1,2};
    Test("Test1",rotateArray,1);
}
void Test2(){
    vector<int>rotateArray = {1};
    Test("Test2",rotateArray,1);
}
void Test3(){
    vector<int>rotateArray = {1,0,1,1,1,1,1,1,1};
    Test("Test3",rotateArray,0);
}
void Test4(){
    vector<int>rotateArray = {};
    Test("Test4",rotateArray,0);
}
void Test5(){
    vector<int>rotateArray = {6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335};
    Test("Test5",rotateArray,154);
}
int main(){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
//    output
//    Test1 Passed.
//    Test2 Passed.
//    Test3 Passed.
//    Test4 Passed.

    return 0;
}
