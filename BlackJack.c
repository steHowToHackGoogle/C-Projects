#include <stdio.h>

int card, value, sum;
char cards[2][13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int play()

int menu() {
    printf("[Play] annonimously\n[Log] In\n[New] account\n[Exit]\n");
    char menu_choise[4];
    scanf("%s", menu_choise);
    if(menu_choise == "Play") {

    }else if(menu_choise == "Log") {

    }else if(menu_choise == "New") {

    }else if(menu_choise == "Exit") {
        printf("Thank you and goodbye!");
    }
    else {
        printf("Invallid input!");
    }
}

int main() {
    menu();
}