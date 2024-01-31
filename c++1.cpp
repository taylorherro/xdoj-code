#include <iostream>
#include <vector>
#include <map>
int main() {
    // 使用vector容器存储整数
    std::vector<int> intVector;


    // 向vector容器中添加数据
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);


    // 遍历vector容器并输出其中的数据
    for (int i : intVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // 使用map容器存储键值对
    std::map<std::string, int> ageMap;


    // 向map容器中添加数据
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 20;


    // 遍历map容器并输出其中的数据
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
        return 0;
    
}