//David Lau
//Two Sum Problem using Hash Tables
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
 
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int,vector<int>> hashMap;
    for(unsigned int i=0; i<nums.size(); i++){
        hashMap[nums[i]].push_back(i);
    }
    int diff;
    for(unsigned int i=0; i<nums.size(); i++){
        diff = target-nums[i];
        if(hashMap.count(diff)){
            for(int j=0; j<hashMap[diff].size(); j++){
                if(hashMap[diff][j] == i) continue; //don't want same index
                else return vector <int> {i+1, hashMap[diff][j]+1};
            }
        }
    }
}

int main(){
    vector <int> test{3,2,4};
    vector<int> r = twoSum(test, 6);
    for(unsigned int i=0; i<r.size(); i++){
        cout << r[i] << endl;
    }
    return 0;
}
