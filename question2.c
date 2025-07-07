#include <stdio.h>

#define DAYS 7

float findMax(float temps[]);
float findMin(float temps[]);
float findAverage(float temps[]);

int main() {
    // all temps are in degree celcius
    float temperatures[DAYS] = {0.0};

    float highest_temp = 0.0;
    float lowest_temp = 0.0;
    float average = 0.0;

    // take inputs for daily temperatures
    printf("ENTER DAILY TEMPERATURES\n");
    printf("---------------------------\n");
    for (int i = 0; i < DAYS; i++) {
        printf("Enter temperature for day #%d: \n", i+1);
        scanf("%f", &temperatures[i]);
    }

    highest_temp = findMax(temperatures);
    lowest_temp = findMin(temperatures);
    average = findAverage(temperatures);

    // printing summary report
    printf("\n=====================================\n");
    printf("        Summary Temperature Report     \n");
    printf("=====================================\n");
    printf("| %-6s | %-15s |\n", "Day", "Temperature (°C)");
    printf("-------------------------------------\n");
    for (int i = 0; i < DAYS; i++) {
        printf("| %-6d | %-15.2f |\n", i + 1, temperatures[i]);
    }
    printf("Maximum Temperature : %.2f°C\n", highest_temp);
    printf("Minimum Temperature : %.2f°C\n", lowest_temp);
    printf("Average Temperature : %.2f°C\n", average);
    printf("=====================================\n");

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