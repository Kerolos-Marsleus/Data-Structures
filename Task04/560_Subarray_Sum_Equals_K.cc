#include <iostream>
#include <vector>
#include <unordered_map>


int subarraySum(std::vector<int> &nums, int k)
    {
        int count=0, sum=0;
        std::unordered_map<int, int> mp;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum-k;
            if(mp.find(find) != mp.end()){
                count += mp[find];
            }
            mp[sum]++;
            
        }
        return count;
}

int main(void){

}
