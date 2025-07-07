#include <stdio.h>

#define DAYS 7

float findMax(float temps[]);
float findMin(float temps[]);
float findAverage(float temps[]);

int main() {
    // all temps are in degree celcius
    float temperatures[DAYS] = {0.0};

    float max_temp = 0.0;
    float min_temp = 0.0;
    float average = 0.0;

    // take inputs for daily temperatures
    printf("ENTER DAILY TEMPERATURES\n");
    printf("---------------------------\n");
    for (int i = 0; i < DAYS; i++) {
        printf("Enter temperature for day #%d: \n", i+1);
        scanf("%f", &temperatures[i]);
    }

    max_temp = findMax(temperatures);
    min_temp = findMin(temperatures);
    average = findAverage(temperatures);

    // printing summary report
    printf("==SUMMARY REPORT==\n\n");
    printf("DAYS\t\tTEMPERATURES\n");
    for (int i = 0; i < DAYS; i++) {
        printf("%d\t\t%.2f\n", i+1, temperatures[i]);
    }
    printf("-----------------------\n");
    printf("Maximum temperature = %.2f\n", max_temp);
    printf("Minimum temperature = %.2f\n", min_temp);
    printf("Average temperature = %.2f\n", average);

    return 0;

}

// finds the highest temperature
float findMax(float temps[]) {
    float highest_temp = temps[0];
    for (int i = 1; i < DAYS; i++) {
        if (temps[i] > highest_temp) {
            highest_temp = temps[i];
        }
    }
    return highest_temp;
}

// finds the lowest temperature
float findMin(float temps[]) {
    float lowest_temp = temps[0];
    for (int i = 1; i < DAYS; i++) {
        if (temps[i] < lowest_temp) {
            lowest_temp = temps[i];
        }
    }
    return lowest_temp;
}

// calculates the average temperature
float findAverage(float temps[]) {
    float total = 0.0;
    for (int i = 0; i < DAYS; i++) {
        total += temps[i];
    }
    float average = total / DAYS;
    return average;
}