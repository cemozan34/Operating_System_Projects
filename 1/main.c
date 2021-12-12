#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time header is included because of using time() function.
#include <string.h> // string header is included because I used strcmp() function.

// I wrote my code in CodeBlocks IDE(Windows) and then test my code in ORACLE VM VirtualBox's Ubuntu console. And cannot find any mistake. And my gcc version __STDC_VERSION__ : 201710L . I think this is C17.
// I find the __STDC_VERSION__ value using "gcc -dM -E - < /dev/null" command.

void roundNumbers(int counterDegree, int counter,int round){ // Printing round numbers correctly.

            if (round == (counter*10)+1){
                    if (round != 11){
                    printf("%dst round\n",round);}
                    else{
                        printf("%dth round\n",round);
                    }
            }
            else if (round == (counter*10)+2){
                    if (round != 12){
                    printf("%dnd round\n",round);}
                    else{
                        printf("%dth round\n",round);
                    }
            }
            else if (round == (counter*10)+3){
                    if (round != 13){
                    printf("%drd round\n",round);}
                    else{
                        printf("%dth round\n",round);
                    }
            }
            else{
                    printf("%dth round\n",round);
            }

}
int rollingDice(int array[]){ // This function rolls the dice 3 times for everyone and put the result of the related array for everyone.
    int dice = 0;
    for (int i = 0 ; i < 3 ; i++){
        dice = (rand() % 6) + 1; // I add 1 to rand()%6 because this expression generate random numbers between 0-5 but we want 1-6.
        array[i] = dice;
    }

}

void showTheDices(char playerName[],int array[]){ // This function shows the everyone's dices.
    printf("%s rolled: ",playerName);
    for (int i = 0 ; i < 3 ; i++){
        if (i != 2){
        printf("%d-",array[i]);
        }
        else{
            printf("%d\n",array[i]);
        }
    }
}

void calculatingPoints(int array[], int *totalPoints){ // This function calculates total points with respect to your mentions in homework pdf file for everyone and print the points that are earned in that round to the console for everyone.
    while(1){
        if (array[0] == 1){
            if ((array[0] == array[1]) && (array[0] == array[2])){
                printf("lost 10 points\n");
                *totalPoints -= 10;
                break;
            }
        }
        if (array[0] == 6){
            if ((array[0] == array[1]) && (array[0] == array[2])){
                printf("gain 10 points\n");
                *totalPoints += 10;
                break;
            }
        }
        if ((array[0] != 6) && (array[0] != 1)){
            if ((array[0] == array[1]) && (array[0] == array[2])){
                printf("gain 5 points\n");
                *totalPoints += 5;
                break;
            }
        }
        if(array[0] == array[1] && (array[0] != array[2])){
            if (array[0] < 4){
                printf("lost %d points\n",array[2]);
                *totalPoints -= array[2];
                break;
            }
            else{
                printf("gain %d points\n",array[2]);
                *totalPoints += array[2];
                break;
            }
        }
        if(array[1] == array[2] && (array[0] != array[1])){
            if (array[1] < 4){
                printf("lost %d points\n",array[0]);
                *totalPoints -= array[0];
                break;
            }
            else{
                printf("gain %d points\n",array[0]);
                *totalPoints += array[0];
                break;
            }
        }
        if(array[0] == array[2] && (array[0] != array[1])){
            if (array[0] < 4){
                    printf("lost %d points\n",array[1]);
                *totalPoints -= array[1];
                break;
            }
            else{
                printf("gain %d points\n",array[1]);
                *totalPoints += array[1];
                break;
            }
        }
        if (array[0] == 1){
            if(array[1] == 2){
                if(array[2] == 3){
                    printf("lost 3 points\n");
                    *totalPoints -= 3;
                    break;
                }
            }
        }
        if (array[0] == 2){
            if(array[1] == 1){
                if(array[2] == 3){
                        printf("lost 3 points\n");
                    *totalPoints -= 3;
                    break;
                }
            }
        }
        if (array[0] == 3){
            if(array[1] == 2){
                if(array[2] == 1){
                        printf("lost 3 points\n");
                    *totalPoints -= 3;
                    break;
                }
            }
        }
        if (array[0] == 3){
            if(array[1] == 1){
                if(array[2] == 2){
                        printf("lost 3 points\n");
                    *totalPoints -= 3;
                    break;
                }
            }
        }
        if (array[0] == 1){
            if(array[1] == 3){
                if(array[2] == 2){
                        printf("lost 3 points\n");
                    *totalPoints -= 3;
                    break;
                }
            }
        }
        if (array[0] == 2){
            if(array[1] == 3){
                if(array[2] == 1){
                        printf("lost 3 points\n");
                    *totalPoints -= 3;
                    break;
                }
            }
        }

        if (array[0] == 4){
            if(array[1] == 5){
                if(array[2] == 6){
                        printf("gain 3 points\n");
                    *totalPoints += 3;
                    break;
                }
            }
        }
        if (array[0] == 5){
            if(array[1] == 4){
                if(array[2] == 6){
                         printf("gain 3 points\n");
                    *totalPoints += 3;
                    break;
                }
            }
        }
        if (array[0] == 6){
            if(array[1] == 4){
                if(array[2] == 5){
                         printf("gain 3 points\n");
                    *totalPoints += 3;
                    break;
                }
            }
        }
        if (array[0] == 6){
            if(array[1] == 5){
                if(array[2] == 4){
                         printf("gain 3 points\n");
                    *totalPoints += 3;
                    break;
                }
            }
        }
        if (array[0] == 5){
            if(array[1] == 6){
                if(array[2] == 4){
                         printf("gain 3 points\n");
                    *totalPoints += 3;
                    break;
                }
            }
        }
        if (array[0] == 4){
            if(array[1] == 6){
                if(array[2] == 5){
                         printf("gain 3 points\n");
                    *totalPoints += 3;
                    break;
                }
            }
        }
        if (1){
            printf("gain 0 points\n");
            *totalPoints += 0;
            break;
        }
    }
}
int main()
{
    srand(time(NULL)); // I need a different seed at every execution for rand function that's why this line is necessary.
    char gameBegin[30];
    char startStr[6] = {"Start"}; //I choose length of the array 6 because of \0 symbol to prevent any misunderstanding.
    char username[30]; // I gave 30 to prevent extraordinary situation from user sourced just in case.
    printf("Please enter username: ");
    scanf("%s",username); // Taking user input to determine username. I do not use use ampersand because same thing is valid for the username that I mentioned for gameBegin.
    printf("User registered as \"%s\"\n", username);
    printf("Type \"start\" to begin the game: ");
    scanf("%s",gameBegin); // As a second input from user I put the input value to gameBegin variable without using ampersand because "%s" means that scanf is expecting a pointer to the first element of a char array.
                           // gameBegin is an object array and could evaluated as pointer. So that's why I can use gameBegin directly without adding &. Adding & to me will be evaluated to ‘char (*)[20]’ and your scanf is waiting char *.
    if (strcmp(gameBegin,startStr)){ // strcmp prevents case sensitivity. START, Start, start, sTaRt, ... is valid for starting the game.
        int userTotalPoint = 0; // user's total point.
        int player1TotalPoint = 0; // player1's total point.
        int player2TotalPoint = 0; // player2's total point.
        int player3TotalPoint = 0; // player3's total point.
        int userNumbers[3];
        int player1Numbers[3];
        int player2Numbers[3];
        int player3Numbers[3];
        int round = 1;
        char rollTheDice;
        int counter = 0; // counter and counterDegree is created for determining "st, nd, rd, th" postfixes for each round number.
        int counterDegree = 0;
        while(1){

            if ((counterDegree % 10 == 0) && (counterDegree != 0)){
                counter++;
            }

            roundNumbers(counterDegree,counter,round);

            rollingDice(player1Numbers); // Rolling dice for player1.
            showTheDices("Player1",player1Numbers); // Showing player1's dices.
            printf("Player1 ");
            calculatingPoints(player1Numbers,&player1TotalPoint); // Calculating total points of player1.

            rollingDice(player2Numbers); // Rolling dice for player2.
            showTheDices("Player2",player2Numbers); // Showing player2's dices.
            printf("Player2 ");
            calculatingPoints(player2Numbers,&player2TotalPoint); // Calculating total points of player2.

            rollingDice(player3Numbers); // Rolling dice for player3.
            showTheDices("Player3",player3Numbers); // Showing player3's dices.
            printf("Player3 ");
            calculatingPoints(player3Numbers,&player3TotalPoint); // Calculating total points of player3.

            printf("Roll the dice(y/n)?");
            scanf(" %c",&rollTheDice); // Taking user input to check if user wants to roll the dice or not.
            if (rollTheDice == 'y'){
                rollingDice(userNumbers); // Rolling dice for user.
                showTheDices(username,userNumbers); // Showing user's dices.
                printf("%s ",username);
                calculatingPoints(userNumbers,&userTotalPoint); // Calculating total points of user.
            }
            else{
                break;
            }

            printf("Points table after round %d\n",round);
            printf("1-Player 1 %d points\n",player1TotalPoint);
            printf("2-Player 2 %d points\n",player2TotalPoint);
            printf("1-%s %d points\n",username,userTotalPoint);
            printf("4-Player 3 %d points\n",player3TotalPoint);

            //Checking that who pass 20 points first. And deciding the order of the rest.
            if(userTotalPoint >= 20){
                printf("%s reached 20 points.\n",username);
                printf("Congratulations! %s won the game.\n",username);
                printf("Final Results Table:\n");
                printf("1-%s %d points. Winner\n",username,userTotalPoint);
                if ((player3TotalPoint > player1TotalPoint) && (player3TotalPoint > player2TotalPoint)){
                    printf("2-Player3 %d points\n",player3TotalPoint);
                    if (player1TotalPoint > player2TotalPoint){
                        printf("3-Player1 %d points\n",player1TotalPoint);
                        printf("4-Player2 %d points",player2TotalPoint);
                    }
                    else{
                        printf("3-Player2 %d points\n",player2TotalPoint);
                        printf("4-Player1 %d points",player1TotalPoint);
                    }
                }
                if ((player2TotalPoint > player1TotalPoint) && (player2TotalPoint > player3TotalPoint)){
                    printf("2-Player2 %d points\n",player2TotalPoint);
                    if (player1TotalPoint > player3TotalPoint){
                        printf("3-Player1 %d points\n",player1TotalPoint);
                        printf("4-Player3 %d points",player3TotalPoint);
                    }
                    else{
                        printf("3-Player3 %d points\n",player3TotalPoint);
                        printf("4-Player1 %d points",player1TotalPoint);
                    }
                }
                if ((player1TotalPoint > player2TotalPoint) && (player1TotalPoint > player3TotalPoint)){
                    printf("2-Player1 %d points\n",player1TotalPoint);
                    if (player2TotalPoint > player3TotalPoint){
                        printf("3-Player2 %d points\n",player2TotalPoint);
                        printf("4-Player3 %d points",player3TotalPoint);
                    }
                    else{
                        printf("3-Player3 %d points\n",player3TotalPoint);
                        printf("4-Player2 %d points",player2TotalPoint);
                    }
                }
                break;
            }
            if(player1TotalPoint >= 20){
                printf("Player1 reached 20 points.\n");
                printf("Congratulations! Player1 won the game.\n");
                printf("Final Results Table:\n");
                printf("1-Player1 %d points. Winner\n",player1TotalPoint);
                if ((player3TotalPoint > userTotalPoint) && (player3TotalPoint > player2TotalPoint)){
                    printf("2-Player3 %d points\n",player3TotalPoint);
                    if (player2TotalPoint > userTotalPoint){
                        printf("3-Player2 %d points\n",player2TotalPoint);
                        printf("4-%s %d points",username,player2TotalPoint);
                    }
                    else{
                        printf("3-%s %d points\n",username,player2TotalPoint);
                        printf("4-Player2 %d points",player2TotalPoint);
                    }
                }
                if ((player2TotalPoint > userTotalPoint) && (player2TotalPoint > player3TotalPoint)){
                    printf("2-Player2 %d points\n",player2TotalPoint);
                    if (userTotalPoint > player3TotalPoint){
                        printf("3-%s %d points\n",username,player1TotalPoint);
                        printf("4-Player3 %d points",player3TotalPoint);
                    }
                    else{
                        printf("3-Player3 %d points\n",player3TotalPoint);
                        printf("4-%s %d points",username,player1TotalPoint);
                    }
                }
                if ((userTotalPoint > player2TotalPoint) && (userTotalPoint > player3TotalPoint)){
                    printf("2-%s %d points\n",username,player2TotalPoint);
                    if (player2TotalPoint > player3TotalPoint){
                        printf("3-Player2 %d points\n",player2TotalPoint);
                        printf("4-Player3 %d points",player3TotalPoint);
                    }
                    else{
                        printf("3-Player3 %d points\n",player3TotalPoint);
                        printf("4-Player2 %d points",player2TotalPoint);
                    }
                }
            break;
            }
            if(player2TotalPoint >= 20){
                printf("Player2 reached 20 points.\n");
                printf("Congratulations! Player2 won the game.\n");
                printf("Final Results Table:\n");
                printf("1-Player2 %d points. Winner\n",player2TotalPoint);
                if ((player3TotalPoint > userTotalPoint) && (player3TotalPoint > player1TotalPoint)){
                    printf("2-Player3 %d points\n",player3TotalPoint);
                    if (player1TotalPoint > userTotalPoint){
                        printf("3-Player1 %d points\n",player1TotalPoint);
                        printf("4-%s %d points",username,player2TotalPoint);
                    }
                    else{
                        printf("3-%s %d points\n",username,player2TotalPoint);
                        printf("4-Player1 %d points",player1TotalPoint);
                    }
                }
                if ((player1TotalPoint > userTotalPoint) && (player1TotalPoint > player3TotalPoint)){
                    printf("2-Player1 %d points\n",player1TotalPoint);
                    if (userTotalPoint > player3TotalPoint){
                        printf("3-%s %d points\n",username,player1TotalPoint);
                        printf("4-Player3 %d points",player3TotalPoint);
                    }
                    else{
                        printf("3-Player3 %d points\n",player3TotalPoint);
                        printf("4-%s %d points",username,player1TotalPoint);
                    }
                }
                if ((userTotalPoint > player1TotalPoint) && (userTotalPoint > player3TotalPoint)){
                    printf("2-%s %d points\n",username,player2TotalPoint);
                    if (player1TotalPoint > player3TotalPoint){
                        printf("3-Player1 %d points\n",player1TotalPoint);
                        printf("4-Player3 %d points",player3TotalPoint);
                    }
                    else{
                        printf("3-Player3 %d points\n",player3TotalPoint);
                        printf("4-Player1 %d points",player1TotalPoint);
                    }
                }
                break;
            }
            if(player3TotalPoint >= 20){
                printf("Player3 reached 20 points.\n");
                printf("Congratulations! Player3 won the game.\n");
                printf("Final Results Table:\n");
                printf("1-Player3 %d points. Winner\n",player3TotalPoint);
                if ((player1TotalPoint > userTotalPoint) && (player1TotalPoint > player2TotalPoint)){
                    printf("2-Player1 %d points\n",player1TotalPoint);
                    if (player2TotalPoint > userTotalPoint){
                        printf("3-Player2 %d points\n",player2TotalPoint);
                        printf("4-%s %d points",username,player2TotalPoint);
                    }
                    else{
                        printf("3-%s %d points\n",username,player2TotalPoint);
                        printf("4-Player2 %d points",player2TotalPoint);
                    }
                }
                if ((player2TotalPoint > userTotalPoint) && (player2TotalPoint > player1TotalPoint)){
                    printf("2-Player2 %d points\n",player2TotalPoint);
                    if (userTotalPoint > player1TotalPoint){
                        printf("3-%s %d points\n",username,player1TotalPoint);
                        printf("4-Player1 %d points",player1TotalPoint);
                    }
                    else{
                        printf("3-Player1 %d points\n",player1TotalPoint);
                        printf("4-%s %d points",username,player1TotalPoint);
                    }
                }
                if ((userTotalPoint > player1TotalPoint) && (userTotalPoint > player2TotalPoint)){
                    printf("2-%s %d points\n",username,userTotalPoint);
                    if (player1TotalPoint > player2TotalPoint){
                        printf("3-Player1 %d points\n",player1TotalPoint);
                        printf("4-Player2 %d points",player2TotalPoint);
                    }
                    else{
                        printf("3-Player2 %d points\n",player2TotalPoint);
                        printf("4-Player1 %d points",player1TotalPoint);
                    }
                }
                break;
            }
            round++;
            counterDegree++;
        }
    }
}
