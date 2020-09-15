import 'dart:io';
import 'dart:math';

Random random = new Random();

void msg(m) {
  int i;
  stdout.write("\n");
  for (i = 0; i < m.length + 4; i++) stdout.write("_");
  stdout.write("\n\n  ${m}  \n");
  for (i = 0; i < m.length + 4; i++) stdout.write("_");
}

void end(init, now) {
  if (init == now)
    stdout.write("\n\nYou have no gain and no loss.");
  else if (init > now)
    stdout.write("\n\nYou lost ${init - now}");
  else
    stdout.write("\n\nYou gained ${now - init}");
}

void main() {
  int init_plr, amt_plr, bet_plr, num_plr;
  int amt_dlr, bet_dlr, num_dlr, num_luck;
  stdout.write("\nYour balance will be the double of what you bet. ");
  stdout.write("\n\nEnter the bet amount : \$ ");
  bet_plr = int.parse(stdin.readLineSync());
  bet_dlr = 100 * (random.nextInt(5) + 5);
  if (bet_plr > 1000) {
    stdout.write("\nMax amount is 1000");
    bet_plr = 1000;
  } else if (bet_plr < 500) {
    stdout.write("\nMin amount is 500");
    bet_plr = 500;
  }

  init_plr = amt_plr = 2 * bet_plr;
  amt_dlr = 2 * bet_dlr;
  stdout.write("\n\nPlayer Bet Amount : \$ ${bet_plr}");
  stdout.write("\nDealer Bet Amount : \$ ${bet_dlr}");
  while (true) {
    stdout.write("\n\nEnter your number (1-8) : ");
    num_plr = int.parse(stdin.readLineSync());
    if (num_plr > 8) {
      stdout.write("\nTop number is 8");
      num_plr = 8;
    } else if (num_plr < 1) {
      stdout.write("\nLowest number is 1");
      num_plr = 1;
    }

    stdout.write("\n\nPlayer's Number : ${num_plr}");

    while (true) {
      num_dlr = random.nextInt(8) + 1;
      if (num_dlr != num_plr) break;
    }

    stdout.write("\nDealer Number : ${num_dlr}");

    stdout.write("\n\nRolling . . .");
    num_luck = random.nextInt(8) + 1;
    sleep(const Duration(seconds: 2));
    stdout.write("\n\nDrawn Number : ${num_luck}");
    if (num_plr == num_luck) {
      amt_plr += bet_dlr;
      amt_dlr -= bet_dlr;
      msg("PLAYER WON !");
      if (amt_dlr <= 0) {
        stdout.write("\nDealer lost all his money");
        end(init_plr, amt_plr);
        break;
      }
    } else if (num_dlr == num_luck) {
      amt_plr -= bet_plr;
      amt_dlr += bet_dlr;
      msg("DEALER WON !");
      if (amt_plr <= 0) stdout.write("\nYour balance is 0.");
      end(init_plr, 0);
      break;
    } else
      msg("DRAW !");

    stdout.write("\n\n\nPlayer's Balance : \$ ${amt_plr}");
    stdout.write("\nDealer's Balance : \$ ${amt_dlr}");
    stdout.write("\n\n1. Continue \t 2. Quit \t : ");
    int cont = int.parse(stdin.readLineSync());
    stdout.write("___________________________________________________");
    if (cont == 2) {
      end(init_plr, amt_plr);
      break;
    }
  }
}
