#include <stdio.h>

int card1, card2, card1d, card2d, sum, value1, value2, totaly, totald;
char cards[14][14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int check(int i, int j) {
    if(cards[i] == "J" || cards[i] == "Q" || cards[i] == "K") {
        j = 10;
    }else {
        j = i;
    }
}

int cond(int x) {
    if(x > 21) {
        lose();
    }else if(x = 21) {
        win();
    }else {
        play_on();
    }
}

int lose() {
    printf("You lost\n1.Try again\n2.Exit");
    int ch;
    scanf("%d", &ch);
    if(ch == 1) {
        play();
    }
    else {
        printf("Goodbye");
    }
}

int win() {
    printf("You win!\n1.Play again\n2.Exit");
    int ch;
    scanf("%d", &ch);
    if(ch == 1) {
        play();
    }
    else {
        printf("Goodbye!");
    }
}

int hit() {
    card1 = rand() % 12 + 1;
    printf("Your card: %s\n", cards[card1]);
    check(card1, sum);
    totaly += card1;
    printf("Total: %d\n", totaly);
    cond(totaly);
}

int stay() {
    printf("Dealer's hand: %s, %s\nDealer's total: %d\n", cards[card1d], cards[card2d], totald);
        if(totald > totaly && totald < 21) {
            lose();
        }else {
            win();
        }
}

int play_on() {
    printf("1.Hit\n2.Stay");
    int ch;
    scanf("%d", &ch);
    if(ch == 1) {
        hit();
    }
    else {
        stay();
        }   
}

int your_hand() {
    card1 = rand() % 12 + 1;
    check(card1, value1);
    card2 = rand() % 12 + 1;
    check(card1, value2);
    printf("Your hand is: %s, %s\n", cards[card1], cards[card2]);

    totaly = card1 + card2;
    printf("Total: %d", totaly);
}

int dealer_hand() {
    card1d = rand() % 12 + 1;
    check(card1d, value1);
    card2d = rand() % 12 + 1;
    check(card2d, value2);
    printf("Dealer's hand is: %s, ?\n", cards[card1]);

    totald = card1d + card2d;
}

int menu() {
    printf("1.Play annonimously\n2.Log In\n3.New account\n4.Exit\n");
    int menu_choise;
    scanf("%d", &menu_choise);
    if(menu_choise == 1) {
        play();
        printf("%s \n %s", cards[card1], cards[card2]);
    }else if(menu_choise == 2) {

    }else if(menu_choise == 3) {

    }else if(menu_choise == 4) {
        printf("Thank you and goodbye!");
    }
    else {
        printf("Invallid input!");
    }
}

int play() {
    dealer_hand();
    your_hand();
    cond(totaly);
}

int main() {
    srand(time(NULL));
    play();
    system("pause");
}