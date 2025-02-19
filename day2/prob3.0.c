#include <stdio.h>

float calculateFinalAmount(float billAmount) {
    if (billAmount > 500 && billAmount <= 1000) {
        return billAmount * 0.90;
    } else if (billAmount > 1000) {
        return billAmount * 0.80; 
    } else {
        return billAmount;
    }
}

int main() {
    float billAmount;
    printf("Enter total bill amount: ₹");
    scanf("%f", &billAmount);

    float finalAmount = calculateFinalAmount(billAmount);

    printf("Final Payable Amount: ₹%.2f\n", finalAmount);

    return 0;
}
