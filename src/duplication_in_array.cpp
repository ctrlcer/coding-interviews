#include<iostream>
#include<cstdio>
using namespace std;
bool duplicate(int numbers[],int length,int* duplication){
    if(numbers==nullptr || length <= 0)
        return false;
    for(int i = 0; i < length; i++){
        if(numbers[i] < 0 || numbers[i] > length-1)
            return false;
    }
    for(int i = 0; i < length; i++){
        while(numbers[i]!=i){
            if(numbers[i]==numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            //swap numbers[i]  numbers[temp]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}
int main(){
    //test demo
    int numbers[7] = {2,3,1,0,2,5,3};
    int dup;
    if(duplicate(numbers,7,&dup))
        printf("%d is duplication",dup);
    else
        printf("none");
    return 0;
}
