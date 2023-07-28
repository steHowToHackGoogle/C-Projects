#include <stdio.h>
#include <string.h>

struct accounts {
    char f_name[30];
    char l_name[30];
    char email[30];
    char password[30];
    float balance;
};

struct accounts client[100];

int data_c() {
    strcpy(client[0].f_name, "Giurgi");
    strcpy(client[0].l_name, "Stefan");
    strcpy(client[0].email, "giurgistefan1@gmail.com");
    strcpy(client[0].password, "Frigiderele123");
    client[0].balance = 25589994.34;//$25,589,994.34

    strcpy(client[1].f_name, "Chirila");
    strcpy(client[1].l_name, "Stefana");
    strcpy(client[1].email, "chirilastefana58@gmail.com");
    strcpy(client[1].password, "Stefan2023");
    client[1].balance = 2330006.68;//$2,330,006.68

    strcpy(client[2].f_name, "Ginga");
    strcpy(client[2].l_name, "Iulian");
    strcpy(client[2].email, "mosionroata1@gmail.com");
    strcpy(client[2].password, "Carutza69");
    client[2].balance = 3221.43;//$3,221.43

    strcpy(client[3].f_name, "Danila");
    strcpy(client[3].l_name, "Gabriel");
    strcpy(client[3].email, "dg_696969@gmail.com");
    strcpy(client[3].password, "Bemeveu03");
    client[3].balance = 112.02;//$112.02

    strcpy(client[4].f_name, "Olaru");
    strcpy(client[4].l_name, "Andrei");
    strcpy(client[4].email, "olaru_aandrei@outlook.com");
    strcpy(client[4].password, "Toxic2012");
    client[4].balance = 1000.00;//$1000.00
}

int menu() {
    printf("1.Log In\n2.New account\n3.Exit\n");
    int ch;
    scanf("%d", ch);
    if(ch == 1) {
        //log in function
    }else if(ch == 2) {
        //sign up function
    }else {
        printf(" _______________________________________ \n|            INVALID INPUT              |\n|_______________________________________|\n");
    }
}

int main() {
    menu();
    system("pause");
    getchar();
}