#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> remove_duplicates(std::vector<int> vec){
    std::vector<int> ans;
    
    std::sort(vec.begin(),vec.end());
    size_t i = 0;
    while(i < vec.size()){
        size_t j = i;
        while( j < vec.size() && vec[i] == vec[j]){
            j++;
        }
        if(j-i == 1){
            ans.push_back(vec[i]);
        }
        i = j;
    }
    return ans;
}


int main(void){
    std::vector<int> vec{3,5,1,6,0,-1,-1,2,2,2,6,1,3,7};
    std::vector<int> res = remove_duplicates(vec);
    for(auto i : res){
        std::cout << i << " ";
    }
}


