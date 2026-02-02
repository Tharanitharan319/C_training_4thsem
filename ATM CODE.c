#include <stdio.h>

int main() {
    int saved_pin = 1234;  // Pre-set PIN
    int entered_pin;
    int attempts = 0;
    float balance = 5000.00; // Starting balance
    float withdraw_amount;

    printf("--- Welcome to the ATM ---\n");


    while (attempts < 3) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == saved_pin) {

            printf("Access Granted!\n");
            printf("Your current balance is: $%.2f\n", balance);
            printf("Enter amount to withdraw: ");
            scanf("%f", &withdraw_amount);


            if (withdraw_amount <= balance) {
                balance -= withdraw_amount;
                printf("Please collect your cash.\n");
                printf("Remaining balance: $%.2f\n", balance);
            } else {
                printf("Error: Insufficient balance!\n");
            }
            

            return 0; 
        } else {

            attempts++;
            int remaining = 3 - attempts;
            if (remaining > 0) {
                printf("Incorrect PIN. You have %d attempts left.\n", remaining);
            }
        }
    }


    printf("\n*** CARD BLOCKED ***\n");
    printf("Too many failed attempts. Please contact your bank.\n");

    return 0;
}