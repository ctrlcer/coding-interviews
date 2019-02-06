//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�
//���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·����
//���Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
//a b c e
//s f c s
//a d e e
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
class Solution {
public:

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int dirx[4] = {1,0,0,-1};
        int diry[4] = {0,1,-1,0};
        bool* vis = new bool[rows * cols];
        memset(vis,0,rows*cols);
        if(strlen(str) > strlen(matrix) || matrix == nullptr || str == nullptr || rows < 1 || cols <1)
            return false;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i * cols + j] == str[0]){
                    if(dfs(i,j,1,matrix,str,rows,cols,dirx,diry,vis))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(int row,int col,int step, char* matrix,char* str,int rows,int cols,int dirx[],int diry[],bool *vis){
        if(step == strlen(str))
            return true;
        vis[row * cols + col] = true;
        for(int i = 0; i < 4; i++){
            int newRow = row + diry[i];
            int newCol = col + dirx[i];
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow*cols+newCol]==str[step]&& vis[newRow*cols+newCol] == false){
                if(step == strlen(str)-1)
                    return true;
                vis[newRow*cols+newCol] = true;
                return dfs(newRow,newCol,++step,matrix,str,rows,cols,dirx,diry,vis);
                vis[newRow*cols+newCol] = false;
            }
        }
        vis[row * cols + col] = false;
        return false;
    }
};
//test demo
void Test(char testName[],char* matrix, int rows, int cols, char* str,bool expectAns){
    Solution s = Solution();
    if(s.hasPath(matrix,rows,cols,str) == expectAns)
        printf("%s Passed.\n",testName);
    else
        printf("%s Failed.\n",testName);
}
void Test1(){
    Test("Test1","abcesfcsadee",3,4,"bcced",true);
}
void Test2(){
    Test("Test2","abcesfcsadee",3,4,"abcb",false);
}
void Test3(){
    Test("Test3","ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS",5,8,"SGGFIECVAASABCEHJIGQEMS",false);
}
void Test4(){
    Test("Test4","ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS",5,8,"SGGFIECVAASABCEHJIGQEM",true);
}
void Test5(){
    Test("Test5","A",1,1,"A",true);
}
int main(){
    Solution s = Solution();
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
//    Test5 Passed.
    return 0;
}
