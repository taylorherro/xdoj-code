#include <iostream>
#include <chrono>


int main() {
    // 获取当前系统时间点
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();


    // 将时间点转换为时间戳
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "当前时间：" << std::ctime(&now_c);


    // 计算程序运行时间
    auto start = std::chrono::high_resolution_clock::now();
    // 执行一些操作
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "程序执行时间：" << elapsed.count() << " 秒\n";


    return 0;
}