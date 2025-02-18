#include <stdio.h>

// Function to calculate the final payable amount
float calculateFinalAmount(float billAmount) {
    if (billAmount > 500 && billAmount <= 1000) {
        return billAmount * 0.90; // 10% discount
    } else if (billAmount > 1000) {
        return billAmount * 0.80; // 20% discount
    } else {
        return billAmount; // No discount
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
