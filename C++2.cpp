#include <iostream>
#include <chrono>


int main() {
    // ��ȡ��ǰϵͳʱ���
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();


    // ��ʱ���ת��Ϊʱ���
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "��ǰʱ�䣺" << std::ctime(&now_c);


    // �����������ʱ��
    auto start = std::chrono::high_resolution_clock::now();
    // ִ��һЩ����
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "����ִ��ʱ�䣺" << elapsed.count() << " ��\n";


    return 0;
}