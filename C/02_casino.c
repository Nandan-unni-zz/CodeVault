#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void msg(char m[20])
{
    int i;
    printf("\n");
    for (i = 0; i < strlen(m) + 4; i++)
        printf("_");
    printf("\n\n  %s  \n", m);
    for (i = 0; i < strlen(m) + 4; i++)
        printf("_");
}

void end(int init, int now)
{
    if (init == now)
        printf("\n\nYou have no gain and no loss.");
    else if (init > now)
        printf("\n\nYou lost %d", init - now);
    else
        printf("\n\nYou gained %d", now - init);
}

int main()
{
    int init_plr, amt_plr, bet_plr, num_plr;
    int amt_dlr, bet_dlr, num_dlr, num_luck;
    printf("\nYour balance will be the double of what you bet. ");
    printf("\n\nEnter the bet amount : $ ");
    scanf("%d", &bet_plr);
    bet_dlr = 100 * ((rand() % 6) + 5);
    if (bet_plr > 1000)
    {
        printf("\nMax amount is 1000");
        bet_plr = 1000;
    }
    else if (bet_plr < 500)
    {
        printf("\nMin amount is 500");
        bet_plr = 500;
    }

    init_plr = amt_plr = 2 * bet_plr;
    amt_dlr = 2 * bet_dlr;
    printf("\n\nPlayer Bet Amount : $ %d", bet_plr);
    printf("\nDealer Bet Amount : $ %d", bet_dlr);

    while (1)
    {
        printf("\n\nEnter your number (1-8) : ");
        scanf("%d", &num_plr);
        if (num_plr > 8)
        {
            printf("\nTop number is 8");
            num_plr = 8;
        }
        else if (num_plr < 1)
        {
            printf("\nLowest number is 1");
            num_plr = 1;
        }

        printf("\n\nPlayer's Number : %d", num_plr);

        while (1)
        {
            num_dlr = (rand() % 8) + 1;
            if (num_dlr != num_plr)
                break;
        }

        printf("\nDealer Number : %d", num_dlr);

        printf("\n\nRolling . . .");
        printf(".");
        num_luck = (rand() % 8) + 1;
        sleep(2);
        printf("\n\nDrawn Number : %d", num_luck);
        if (num_plr == num_luck)
        {
            amt_plr += bet_dlr;
            amt_dlr -= bet_dlr;
            msg("PLAYER WON !");
            if (amt_dlr <= 0)
            {
                printf("\nDealer lost all his money");
                end(init_plr, amt_plr);
                break;
            }
        }
        else if (num_dlr == num_luck)
        {
            amt_plr -= bet_plr;
            amt_dlr += bet_dlr;
            msg("DEALER WON !");
            if (amt_plr <= 0)
                printf("\nYour balance is 0.");
                end(init_plr, 0);
                break;
        }
        else
            msg("DRAW !");

        printf("\n\n\nPlayer's Balance : $ %d", amt_plr);
        printf("\nDealer's Balance : $ %d", amt_dlr);
        printf("\n\n1. Continue \t 2. Quit \t : ");
        int cont;
        scanf("%d", &cont);
        printf("___________________________________________________");
        if (cont == 2)
        {
            end(init_plr, amt_plr);
            break;
        }
    }
    return 0;
}
