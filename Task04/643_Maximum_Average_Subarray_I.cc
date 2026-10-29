#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

double findMaxAverage(std::vector<int>& nums, int k) {
    int sum = 0;
    size_t size = nums.size();
    int i = 0;
    for(int i = 0; i < k;i++){
        sum+=nums[i];
    }
    int max_sum = sum;
    while(i + k < size){
        sum -= nums[i];
        sum += nums[i+k];
        i++;
        max_sum = std::max(max_sum, sum);
    }
    return static_cast<double>(max_sum) / k;
    
}


int main(void){

}