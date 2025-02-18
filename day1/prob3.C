#include <stdio.h>

int main() {
    int salary, creditScore, experience;

    // Taking user input
    printf("Enter Salary: ");
    scanf("%d", &salary);
    
    printf("Enter Credit Score: ");
    scanf("%d", &creditScore);
    
    printf("Enter Experience (Years): ");
    scanf("%d", &experience);

    // Checking eligibility conditions
    if (salary >= 30000 && creditScore >= 750 && experience >= 2) {
        printf("Loan Approved\n");
    } else {
        printf("Loan Denied\n");
    }

    return 0;
}
