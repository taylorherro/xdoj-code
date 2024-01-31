#include <iostream>
#include <vector>
#include <map>
int main() {
    // ʹ��vector�����洢����
    std::vector<int> intVector;


    // ��vector�������������
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);


    // ����vector������������е�����
    for (int i : intVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // ʹ��map�����洢��ֵ��
    std::map<std::string, int> ageMap;


    // ��map�������������
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 20;


    // ����map������������е�����
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
        return 0;
    
}