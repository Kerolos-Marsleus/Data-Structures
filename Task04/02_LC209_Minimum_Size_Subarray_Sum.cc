#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

int minSubArrayLen(int target, std::vector<int>& nums) {
        int i = 0; 
        size_t n = static_cast<int>(nums.size());
        int j = 0;
        int sum = nums[0];
        int length = __INT_MAX__;
        while(i < n){
            if(sum < target){
                j++;
                if(j == n){
                    break;
                }
                sum += nums[j];
            }else{
                length = std::min(length,j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        if( length == __INT_MAX__){
            return 0;
        }
        return length;
}

int main(void){
    std::vector<int> vec{2,3,1,2,4,3};
    std::cout << minSubArrayLen(7,vec);
}