#include <stdio.h>

#define MAX 1
#define STR_LIM 50
#define TAX 0.1

void calculateNetSalary(double grossSalary[], double netSalary[]);
void printSlip(const char names[][STR_LIM],const double grossSalary[],const double netSalary[]);

int main(void) {
    double gross_salaries[MAX] = {0}, net_salaries[MAX] = {0};
    char names[MAX][STR_LIM] = {""};
    for(int i = 0; i < MAX; i++) {
        printf("Enter employee name: ");
        scanf("%49s", names[i]);
        printf("Enter gross salary: ");
        scanf("%lf", &gross_salaries[i]);
    }

    calculateNetSalary(gross_salaries, net_salaries);
    printSlip(names, gross_salaries, net_salaries);
    return 0;
}

void calculateNetSalary(double grossSalary[], double netSalary[]) {
    for(int i = 0; i < MAX; i++) {
        double tax_amount = TAX * grossSalary[i];
        netSalary[i] = grossSalary[i] - tax_amount;
    }
}

void printSlip(const char names[][STR_LIM],const double grossSalary[], const double netSalary[]) {
    for(int i = 0; i < MAX; i++) {
        printf("%s\n", names[i]);
        printf("%lf\n", grossSalary[i]);
        printf("%lf\n\n", netSalary[i]);
    }
}