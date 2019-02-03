//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
//判断数组中是否含有该整数。
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int lengthOfMatrix = array[0].size();
        int hightOfMatrix = array.size();
        if(lengthOfMatrix == 0 || hightOfMatrix == 0)
            return false;
        for(int i = 0; i < hightOfMatrix; i++){
            for(int j = lengthOfMatrix-1; j >= 0; j--){
                if(array[i][j] == target)
                    return true;
                else if(array[i][j] < target){
                    lengthOfMatrix= j + 1;
                    break;
                }
                else
                    continue;
            }
        }
        return false;
    }
};
//test demo
void Test(char* testName,int target,vector<vector<int> > array,bool expected){
    Solution s = Solution();
    if(s.Find(target,array) == expected){
        printf("%s Passed.\n",testName);
    }else{
        printf("%s Failed.\n",testName);
    }
}

//array
//1 2 8 9
//2 4 9 12
//4 7 10 13
//6 8 11 15
//
//target 7
void Test1(){
    vector<vector<int> > array = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Test("Test1",7,array,true);
}
//array
//1 2 8 9
//2 4 9 12
//4 7 10 13
//6 8 11 15
//
//target 5
void Test2(){
    vector<vector<int> > array = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Test("Test2",5,array,false);
}

//robust test
void Test3(){
    vector<vector<int> > array;
    Test("Test3",5,array,false);
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
