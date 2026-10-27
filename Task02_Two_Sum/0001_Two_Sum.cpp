#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // will take O(n)
        std::vector<int> ans;
        std::unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(!m.count(nums.at(i)) && !m.count(target-nums.at(i))){
                m[nums.at(i)] = i;
            }else if(m.count(target - nums.at(i))){
                ans.push_back(m[target- nums.at(i)]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
}
std::vector<int> twoSum_without_map(std::vector<int> &nums, int target){
    // will take 0(n^2)
    auto number_of_items = nums.size();
    for(auto i = 0 ; i < number_of_items; i++){
        for(auto j = i+1; j < number_of_items;j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }
    return {};
}

int main(){
    std::vector<int> num{1,2,3,4,5,6,7,8,4,3,1,6};
    std::vector<int> res;
    res = twoSum(num,4);
    for(int i : res){
        std::cout << i << '\t';
    }
}