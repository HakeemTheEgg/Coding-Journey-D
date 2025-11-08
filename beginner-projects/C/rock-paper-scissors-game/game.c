#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
int getcompchoice();
int getuserchoice();
void checkwinner(int userchoice, int compchoice);

int main(){
    srand(time(NULL));

    printf("***rock paper scissors***\n");
    int compchoice = getcompchoice();
    int userchoice = getuserchoice();

    

    switch (userchoice)
    {
    case 1:
        printf("you chose rock\n");
        break;
    case 2:
        printf("you chose paper\n");
        break;
    case 3:
        printf("you chose scissors\n");
        break;
    }

    switch (compchoice)
    {
    case 1:
        printf("computer chose rock\n");
        break;
    case 2:
        printf("computer chose paper\n");
        break;
    case 3:
        printf("computer chose scissors\n");
        break;
   
    }
     checkwinner(userchoice, compchoice);
return 0;
} 
int getcompchoice(){
   
    return (rand() % 3 + 1 );
}
int getuserchoice(){
    int choice = 0;
    do
    {
        printf("Enter a number betweeen 1 and 3: ");
        scanf("%d", &choice);
    } while (choice > 3 || choice < 1 );
    
    return choice;
}
void checkwinner(int userchoice, int compchoice){
    if (userchoice == compchoice)
    {
        printf("its a tie! :D");
    }
    else if( (userchoice == 1 && compchoice == 3) ||
             (userchoice == 2 && compchoice == 1) ||
             (userchoice == 3 && compchoice == 2) ){
         printf("you win! :)");   
    }
    else{
        printf("you lose! :(");
    }
}
