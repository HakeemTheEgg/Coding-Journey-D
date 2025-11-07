#include <stdio.h>

void checkbalance(float balance);
float deposit();
float withdraw(float balance);

int main(){
    //banking progrm

    int choice = 0;
    float balance = 0.0f;
    printf("***Welcome to your bank!***");

    do{
        printf("\nEnter your preferred option\n");
        printf("\n1. Check balance\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            checkbalance(balance);
            break;
        case 2:
            balance += deposit();
            break;
        case 3:
            balance -= withdraw(balance);
            break;
        case 4:
            printf("\nThank you for using this service!\n");
            break;
        default:
            printf("\nenter a valid choice between 1-4\n");
        }
    }while(choice != 4);
    

    return 0;
}

void checkbalance(float balance){
    printf("\nYour current balance is: $%.2f\n", balance);
    
}
float deposit(){
    float deposit_amount = 0.0f;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &deposit_amount);
    if (deposit_amount <= 0)
    {
        printf("invalid amount!\n");
        return 0.0f;
    }
    else{
       printf("Successfully added %f to your balance!\n", deposit_amount);
       return deposit_amount; 
    }
    return 0.0f;
}
float withdraw(float balance){
    float withdraw_amount = 0.0f;
    printf("Enter an amount to withdraw");
    scanf("%f", &withdraw_amount);

    if (withdraw_amount <= 0)
    {
        printf("Invalid withdrawal amount!\n");
        return 0.0f;
    }
    else if (withdraw_amount > balance)
    {
       printf("Insufficient funds! your balance is: $%.2f\n", balance);
       return 0.0f;
    }
    else{
       printf("you succesfully withdrew $%.2f\n", withdraw_amount);
       return withdraw_amount; 
    }
    return 0.0f;
}
