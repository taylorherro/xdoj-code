#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STATIONS 10
#define NUM_PASSENGERS 20
#define NUM_SIMULATIONS 10000

void simulate(int station_counts[NUM_STATIONS]) {
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        int num_station = rand() % NUM_STATIONS; // ���ѡ��һ����վ�³�
        station_counts[num_station]++;  // �����³�����ͳ��
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
    int total_station_counts[NUM_STATIONS] = { 0 };  // ÿ����վ�³��Ĵ���ͳ��
    srand(time(NULL));  // ���������������������
    double sum1= 0.0;
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        int station_counts[NUM_STATIONS] ;  // ���ڵ�ǰģ���ÿ����վ�³��Ĵ���ͳ��
        simulate(station_counts);  // ����һ��ģ��
        sum1+=calculate_expectation(station_counts);
    }
    printf("ÿ����վ�³�����������ֵ��%lf\n", sum1/10000);

    return 0;
}