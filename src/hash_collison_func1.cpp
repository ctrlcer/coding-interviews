//1.开放定址法
//冲突发生时，顺序查看表中下一单元，直到找出一个空单元或查遍全表。
#include<iostream>
#include<map>
using namespace std;
map<int,int>imap;
const int MAX_N = 1e5 +10;
int value[MAX_N];
int d[MAX_N];
int main(){
    int m;
    cin>>m;
    //9
    for(int i = 1; i <= m; i++)
        cin>>value[i];
    //5 28 19 15 20 33 12 17 10
    for(int i = 1; i <= m; i++)
        d[i] = i;
    //1 2 3 4 5 6 7 8 9
    //线性探测再散列
    for(int i = 1; i <= m; i++){
        int temp = value[i] % m;
        if(!imap[temp]){
            imap[temp] = value[i];
            continue;
        }

        for(int j = 1; j <= m; j++){
            temp = (value[i] + d[j]) % m;
            if(!imap[temp]){
                imap[temp] = value[i];
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        cout<<imap[i];
        if(i != m-1)
            cout<<" ";
        else
            cout<<endl;
    }
    //10 28 19 20 12 5 15 33 17
    return 0;

}
