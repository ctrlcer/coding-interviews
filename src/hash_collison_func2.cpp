//2.二次探测再散列
//冲突发生时，在表的左右进行跳跃式探测，比较灵活。
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
    int j = 1;
    for(int i = 1; i <= m/2; i++){
        d[j++] = i * 10 + 2;
        d[j++] = -i *10 - 2;
    }
    //12 -12 22 -22 32 -32 42 -42
    //二次探测再散列
    for(int i = 1; i <= m; i++){
        int temp = value[i] % m;
        if(!imap[temp]){
            imap[temp] = value[i];
            continue;
        }

        for(int j = 1; j <= m; j++){
            temp = (value[i] + d[j]) % m;
            if(!imap[temp] && temp >= 0){
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
    //33 28 20 12 19 5 15 10 17
    return 0;

}
