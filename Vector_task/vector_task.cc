#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>




int main(){
    std::vector <int> vec{2,1,4,1,8,2,8};
    for(auto i = vec.begin(); i < vec.end(); i++){
        std::cout << *i << " ";
    }
    std::cout<< std::endl;
    std::vector <int> vec2{1,3,7};
    vec.swap(vec2);
    int* vec_ptr = vec.data();
    for(size_t i = 0; i < vec.size(); i++){
        std::cout << *(i+vec_ptr) << " ";
    }
    std::cout<< std::endl;
    for(auto i = vec2.begin(); i < vec2.end(); i++){
        std::cout << *i << " ";
    }
    std::cout<< std::endl;

    std::sort(vec2.begin(), vec2.end());
    for(auto i = vec2.begin(); i < vec2.end(); i++){
        std::cout << *i << " ";
    }
    std::cout<< std::endl;

    std::reverse(vec2.begin(), vec2.end());
    for(auto i = vec2.begin(); i < vec2.end(); i++){
        std::cout << *i << " ";
    }
    std::cout<< std::endl;

    std::cout << std::boolalpha << std::binary_search(vec2.begin(),vec2.end(),3, std::greater{}) << std::endl;;
    
    auto min = *(std::min_element(vec2.begin(), vec2.end()));
    auto max = *(std::max_element(vec2.begin(), vec2.end()));

    std::cout << "Min : " << min << std::endl;
    std::cout << "Max : " << max << std::endl;

    for(auto it = vec2.begin(); it < vec2.end(); it++){
        std::cout << *it << " occured " << std::count(vec2.begin(),vec2.end(),*it) << std::endl;
    }

    auto sum = std::accumulate(vec2.begin(), vec2.end(), 0);
    std::cout << "The sum of numbers is : " << sum << std::endl;
    std::ranges::sort(vec);
    std::ranges::reverse(vec);
    auto range_found = std::ranges::binary_search(vec2, 8, std::greater{});
    std::cout << "range found : " <<  std::boolalpha << range_found << std::endl;;
    auto range_count = std::ranges::count(vec2,2);
    std::cout << "number 2 in vec2 occured : " << range_count << " times" <<std::endl;

    auto duplicates = std::ranges::unique(vec2);
    vec2.erase(duplicates.begin(), duplicates.end());
    for(auto i = vec2.begin(); i < vec2.end(); i++){
        std::cout << *i << " ";
    }
}