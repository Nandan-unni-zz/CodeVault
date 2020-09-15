#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void msg(string m)
{
    int i;
    cout << "\n";
    for (i = 0; i < m.length() + 4; i++)
        cout << "_";
    cout << "\n\n  " << m << "  \n";
    for (i = 0; i < m.length() + 4; i++)
        cout << "_";
}

void end(int init, int now)
{
    if (init == now)
        cout << "\n\nYou have no gain and no loss.";
    else if (init > now)
        cout << "\n\nYou lost " << init - now;
    else
        cout << "\n\nYou gained " << now - init;
}

int main()
{
    int init_plr, amt_plr, bet_plr, num_plr;
    int amt_dlr, bet_dlr, num_dlr, num_luck;
    cout << "\nYour balance will be the double of what you bet. ";
    cout << "\n\nEnter the bet amount : $ ";
    cin >> bet_plr;
    bet_dlr = 100 * ((rand() % 6) + 5);
    if (bet_plr > 1000)
    {
        cout << "\nMax amount is 1000";
        bet_plr = 1000;
    }
    else if (bet_plr < 500)
    {
        cout << "\nMin amount is 500";
        bet_plr = 500;
    }

    init_plr = amt_plr = 2 * bet_plr;
    amt_dlr = 2 * bet_dlr;
    cout << "\n\nPlayer Bet Amount : $ " << bet_plr;
    cout << "\nDealer Bet Amount : $ " << bet_dlr;

    while (1)
    {
        cout << "\n\nEnter your number (1-8) : ";
        scanf("%d", &num_plr);
        if (num_plr > 8)
        {
            cout << "\nTop number is 8";
            num_plr = 8;
        }
        else if (num_plr < 1)
        {
            cout << "\nLowest number is 1";
            num_plr = 1;
        }

        cout << "\n\nPlayer's Number : " << num_plr;

        while (1)
        {
            num_dlr = (rand() % 8) + 1;
            if (num_dlr != num_plr)
                break;
        }

        cout << "\nDealer Number : " << num_dlr;

        cout << "\n\nRolling . . ";
        cout << ".";
        num_luck = (rand() % 8) + 1;
        sleep(2);
        cout << "\n\nDrawn Number : " << num_luck;
        if (num_plr == num_luck)
        {
            amt_plr += bet_dlr;
            amt_dlr -= bet_dlr;
            msg("PLAYER WON !");
            if (amt_dlr <= 0)
            {
                cout << "\nDealer lost all his money";
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
                cout << "\nYour balance is 0.";
                end(init_plr, 0);
                break;
        }
        else
            msg("DRAW !");

        cout << "\n\n\nPlayer's Balance : $ " << amt_plr;
        cout << "\nDealer's Balance : $ " << amt_dlr;
        cout << "\n\n1. Continue \t 2. Quit \t : ";
        int cont;
        scanf("%d", &cont);
        cout << "___________________________________________________";
        if (cont == 2)
        {
            end(init_plr, amt_plr);
            break;
        }
    }
    return 0;
}
