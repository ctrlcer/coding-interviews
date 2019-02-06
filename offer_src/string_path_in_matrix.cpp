//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
//例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
//但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
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
