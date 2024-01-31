#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STATIONS 10
#define NUM_PASSENGERS 20
#define NUM_SIMULATIONS 10000

void simulate(int station_counts[NUM_STATIONS]) {
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        int num_station = rand() % NUM_STATIONS; // 随机选择一个车站下车
        station_counts[num_station]++;  // 更新下车次数统计
    }
}

double calculate_expectation(int station_counts[NUM_STATIONS]) {
    double sum = 0.0;
    for (int i = 0; i < NUM_STATIONS; i++) {
        if (station_counts[i] != 0)
        {
            sum++;
        }
    }
    return sum;
}

int main() {
    int total_station_counts[NUM_STATIONS] = { 0 };  // 每个车站下车的次数统计
    srand(time(NULL));  // 种下随机数生成器的种子
    double sum1= 0.0;
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        int station_counts[NUM_STATIONS] ;  // 用于当前模拟的每个车站下车的次数统计
        simulate(station_counts);  // 进行一次模拟
        sum1+=calculate_expectation(station_counts);
    }
    printf("每个车站下车次数的期望值：%lf\n", sum1/10000);

    return 0;
}