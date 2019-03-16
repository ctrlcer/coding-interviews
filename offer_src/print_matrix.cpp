//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

//模拟题 正常思路
//大概想法是这样的

//→→→→→→→→→→→→→→→
//1   2   3   4 ↓
//→→→→→→→→→→→   ↓
//↑5 ↑ 6  7 ↓ 8 ↓
//↑9 ↑ 10 11↓ 12↓
//↑  ←←←←←←←←   ↓
//↑13  14  15 16↓
//↑←←←←←←←←←←←←←↓
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>result;
        //矩阵宽
        int len_of_matrix = matrix[0].size();
        //矩阵高
        int hig_of_matrix = matrix.size();
        //遍历到的坐标
        int pos_of_x = 0;
        int pos_of_y = 0;
        //圈数
        int len_of_temp = 0;
        //矩阵大小
        int size_of_matrix = len_of_matrix *hig_of_matrix;
        result.clear();
        while(true){
            if(result.size()==size_of_matrix)
                break;
            while(pos_of_x < len_of_matrix-len_of_temp){
                if(result.size()==size_of_matrix)
                    break;
                result.push_back(matrix[pos_of_y][pos_of_x++]);
            }
            pos_of_x--;
            while(pos_of_y< hig_of_matrix-len_of_temp-1){
                if(result.size()==size_of_matrix)
                    break;
                result.push_back(matrix[++pos_of_y][pos_of_x]);
            }
            while(pos_of_x > len_of_temp){
                if(result.size()==size_of_matrix)
                    break;
                result.push_back(matrix[pos_of_y][--pos_of_x]);
            }
            ++len_of_temp;
            while(pos_of_y > len_of_temp){
                if(result.size()==size_of_matrix)
                    break;
                result.push_back(matrix[--pos_of_y][pos_of_x]);
            }
            pos_of_x++;
        }
        return result;
    }
};
//test demo

void Test(char testName[],vector<int>expVec,vector<vector<int> > matrix){
    Solution s = Solution();
    vector<int>result = s.printMatrix(matrix);
    bool ans = true;
    if(expVec.size() != expVec.size())
        ans = false;
    if(!ans){
        printf("%s Failed.\n",testName);
        return;
    }
    for(int i = 0; i < expVec.size(); i++){
        if(expVec[i] != result[i]){
            printf("%s Failed.\n",testName);
            return;
        }
    }
    printf("%s Passed.\n",testName);
}
//matrix
//1  2  3  4
//5  6  7  8
//9  10 11 12
//13 14 15 16
void Test1(){
    vector<vector<int> > vec(4);
    vec[0] = {1,2,3,4};
    vec[1] = {5,6,7,8};
    vec[2] = {9,10,11,12};
    vec[3] = {13,14,15,16};
    Test("Test1",{1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10},vec);
}
//matrix
//1
void Test2(){
    vector<vector<int> >vec(1);
    vec[0] = {1};
    Test("Test2",{1},vec);
}
//matrix
//1  2  3  4 5
//6  7  8  9 10
//11 12 13 14 15
//16 17 18 19 20
//21 22 23 24 25
void Test3(){
    vector<vector<int> > vec(5);
    vec[0] = {1,2,3,4,5};
    vec[1] = {6,7,8,9,10};
    vec[2] = {11,12,13,14,15};
    vec[3] = {16,17,18,19,20};
    vec[4] = {21,22,23,24,25};
    Test("Test3",{1,2,3,4,5,10,15,20,25,24,23,22,21,16,11,6,7,8,9,14,19,18,17,12,13},vec);
}
//matrix
//1
//2
//3
//4
//5
void Test4(){
    vector<vector<int> >vec(5);
    vec[0] = {1};
    vec[1] = {2};
    vec[2] = {3};
    vec[3] = {4};
    vec[4] = {5};
    Test("Test4",{1,2,3,4,5},vec);
}
//matrix
//1 2 3 4 5
void Test5(){
    vector<vector<int> >vec(1);
    vec[0] = {1,2,3,4,5};
    Test("Test5",{1,2,3,4,5},vec);
}
int main(){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
//Test1 Passed.
//Test2 Passed.
//Test3 Passed.
//Test4 Passed.
//Test5 Passed.
    return 0;
}
