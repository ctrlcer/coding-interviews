//������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
//ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38����
//��Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
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
