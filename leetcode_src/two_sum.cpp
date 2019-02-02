#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    map<int,int>imap;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ivec;
        if(nums.size() < 2)
            return ivec;
        for(int i = 0; i < nums.size();i++)
            imap[nums[i]] = i + 1;
        for(int i = 0; i < nums.size();i++){
            int temp = target - nums[i];
            if(imap[temp] > 0 && imap[temp]-1 != i){
                ivec.push_back(i);
                ivec.push_back(imap[temp]-1);
                break;
            }
        }
        return ivec;
    }
};
int main(){
    Solution s = Solution();
//    vector<int>ivec = {0,4,3,0};
//    int target = 0;

//    vector<int>ivec = {-1,-2,-3,-4,-5};
//    int target = -8;

//    vector<int>ivec = {3,2,4};
//    int target = 6;
    vector<int>townum = s.twoSum(ivec,target);
    cout<<townum[0]<<townum[1]<<endl;
    return 0;
}
