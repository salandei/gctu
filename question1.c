#include <stdio.h>

/**
*  Paulina Dansoa Adomako - 2425401659
 *  Solomon Alan-Dei - 2425404803
 *  Essey Adzahlie-Mensah - 2425402854
 *  Rudy Nene Amanor - 2425400316
**/

#define EMPLOYEE_MAX 10
#define STR_LIM 50
#define TAX 0.1

double calculateNetSalary(double grossSalary);

void printSlip(char name[], double grossSalary, double netSalary);

int main(void) {
    unsigned int num_of_employees;
    printf("Enter number of employees (1-10): ");
    scanf("%u", &num_of_employees);
    if (num_of_employees < 1 || num_of_employees > EMPLOYEE_MAX) {
        printf("Error: enter a number between 1 and 10\n\n");
        return -1;
    }
    double gross_salaries[num_of_employees], net_salaries[num_of_employees];
    char names[num_of_employees][STR_LIM];
    for (int i = 0; i < num_of_employees; i++) {
        printf("Enter name for employee %u: ", i + 1);
        scanf("%49s", names[i]);
        printf("Enter gross salary: ");
        scanf("%lf", &gross_salaries[i]);
    }

    // calculating net salaries and printing salary slip
    for (int i = 0; i < num_of_employees; i++) {
        double net_salary = calculateNetSalary(gross_salaries[i]);
        printSlip(names[i], gross_salaries[i], net_salary);
    }

    return 0;
}

double calculateNetSalary(double grossSalary) {
    if (grossSalary <= 0) {
        return 0.0;
    }
    double tax_amount = TAX * grossSalary;
    return grossSalary - tax_amount;
}

void printSlip(char name[], double grossSalary, double netSalary) {
    // Print salary receipt
    printf("\n=========================================\n");
    printf("              SALARY RECEIPT             \n");
    printf("=========================================\n");
    printf("| %-20s : %-15s |\n", "Employee Name", name);
    printf("-----------------------------------------\n");
    printf("| %-20s : GHS%-12.2f |\n", "Gross Salary", grossSalary);
    printf("| %-20s : GHS%-12.2f |\n", "Tax (10%%)", grossSalary - netSalary);
    printf("| %-20s : GHS%-12.2f |\n", "Net Salary", netSalary);
}
