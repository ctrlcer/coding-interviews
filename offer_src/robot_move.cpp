//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
//因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Solution {
public:
    int getNum(int num){
        int ans = 0;
        while(num){
            ans += (num%10);
            num /= 10;
        }
        return ans;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0)
            return 0;
        int dirx[4] = {0,0,1,-1};
        int diry[4] = {1,-1,0,0};
        int countNum = 0;
        bool* vis = new bool[rows * cols];
        memset(vis,0,rows*cols);
        dfs(0,0,vis,dirx,diry,countNum,threshold,rows,cols);
        delete vis;
        return countNum;
    }
    void dfs(int row,int col,bool* vis,int dirx[],int diry[],int& countNum,int threshold,int rows, int cols){
        if(row >= 0 && row < rows &&col >= 0 && col < cols&& vis[row*cols + col] == false && getNum(row) + getNum(col) <= threshold){
            ++countNum;
            vis[row*cols + col] = true;
            for(int i = 0; i < 4; i++){
                int newRow = row + diry[i];
                int newCol = col + dirx[i];
                dfs(newRow,newCol,vis,dirx,diry,countNum,threshold,rows,cols);
            }
        }
    }
};
//test demo
void Test(char testName[],int threshold, int rows, int cols,int exceptAns){
    Solution  s = Solution();
    if(s.movingCount(threshold,rows,cols) == exceptAns)
        printf("%s Passed.\n",testName);
    else
        printf("%s Failed.\n",testName);
}
void Test1(){
    Test("Test1",2,3,3,6);
}
void Test2(){
    Test("Test2",2,1,1,1);
}
void Test3(){
    Test("Test3",0,1,1,1);
}
void Test4(){
    Test("Test4",-1,1,1,0);
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
