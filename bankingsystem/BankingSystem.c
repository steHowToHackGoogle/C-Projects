#include <stdio.h>
#include <string.h>

int accnum, boll;



struct acc {
    char f_name[30];
    char l_name[30];
    char u_name[30];
    char pass[30];
    float balance;
};

struct acc clients[100];

void data_clients() {
    strcpy(clients[0].f_name, "Giurgi");
    strcpy(clients[0].l_name, "Stefan");
    strcpy(clients[0].u_name, "Gstef");
    strcpy(clients[0].pass, "Frigiderele123");
    clients[0].balance = 2474.98f;

    strcpy(clients[1].f_name, "Giurgi");
    strcpy(clients[1].l_name, "Stefana");
    strcpy(clients[1].u_name, "giurgistef");
    strcpy(clients[1].pass, "GiurgiStefan");
    clients[1].balance = 2471.98f;
}

void send_money(int accnum) {
    int found = 0;
    int rn;
    char receiver[30];
    float amm;
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter ammount: \n");
    scanf("%f", &amm);
    if(amm <= clients[accnum].balance) {
        printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter receiver username: \n");
        scanf("%29s", receiver);
        for(int i = 0; i <= 100; i++) {
            if(strcmp(clients[i].u_name, receiver) == 0) {
                rn = i;
                found = 1;
            }
        }
        if(found == 1) {
            clients[accnum].balance -= amm;
            clients[rn].balance += amm;
            printf("~~~~~~~~~~~~~~~~~~~~~~\nSuccesfully sent %.2f to %s %s!\n", amm, clients[rn].f_name, clients[rn].l_name);
            printf("Balance: %.2f\n~~~~~~~~~~~~~~~~~~~~~~\n", clients[accnum].balance);
        }
    }
}

void withdraw(int accnum) {
    float amm;
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter ammount:\n");
    scanf("%f", &amm);
    if(amm <= clients[accnum].balance) {
        clients[accnum].balance -= amm;
        printf("~~~~~~~~~~~~~~~~~~~~~~\nBalance: $%.2f\n~~~~~~~~~~~~~~~~~~~~~~\n", clients[accnum].balance);
    }else {
        printf("~~~~~~~~~~~~~~~~~~~~~~\nInsufficent funds!\n~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

void deposit(int accnum) {
    float amm;
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter ammount: \n");
    scanf("%f", &amm);
    clients[accnum].balance += amm;
    printf("~~~~~~~~~~~~~~~~~~~~~~\nBalance: %.f\n~~~~~~~~~~~~~~~~~~~~~~\n", clients[accnum].balance);
}

void settings(int accnum) {
    printf("~~~~~~~~~~~~~~~~~~~~~~\nChange (U)sername\n(G)o back\n~~~~~~~~~~~~~~~~~~~~~~\n");
    char ch;
    scanf(" %c", &ch);
    if(ch == 'U' || ch == 'u') {
        int existu;
        char n_uname[30];
        printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter new username: \n");
        scanf("%29s", n_uname);
        for(int i = 0; i <= 100; i++) {
            if(strcmp(clients[i].u_name, n_uname) == 0 && !strcmp(clients[accnum].u_name, n_uname) == 0) {
                existu = 1;
            }else {
                existu = 0;
            }
        }
        if(existu == 1) {
            printf("~~~~~~~~~~~~~~~~~~~~~~\nUsername already exist!\n~~~~~~~~~~~~~~~~~~~~~~\n");
        }else if(existu == 0) {
            strcpy(clients[accnum].u_name, n_uname);
            printf("Username changed!\n~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
}

void logged_in() {
    printf("(W)ithdraw\n(D)eposit\n(S)end money\n(L)og out\n(A)ccount settings\n~~~~~~~~~~~~~~~~~~~~~~ \n");
    char ch;
    scanf(" %c", &ch);
    if(ch == 'W' || ch == 'w') {
        withdraw(accnum);
        logged_in(); 
    }else if(ch == 'D' || ch == 'd') {
        deposit(accnum);
        logged_in();
    }else if(ch == 'S' || ch == 's') {
        send_money(accnum);
        logged_in();
    }else if(ch == 'L' || ch == 'l') {
        menu();
    }else if(ch == 'A' || ch == 'a') {
        settings(accnum);
        logged_in();
    }
}

void log_in() {
    char uname_in[30];
    char pass_in[30];
    printf("Enter username: \n");
    scanf("%29s", uname_in);
    for(int i = 0; i < 101; i++) {
        if(strcmp(clients[i].u_name, uname_in) == 0) {
            boll = 1;
            accnum = i;
        }
    }
    if(boll == 1) {
        printf("Enter your password: \n");
        scanf("%29s", pass_in);
        if(strcmp(clients[accnum].pass, pass_in) == 0) {
            printf("~~~~~~~~~~~~~~~~~~~~~~\nHello %s %s!\nYour balance: $%.2f\n~~~~~~~~~~~~~~~~~~~~~~ \n", clients[accnum].f_name, clients[accnum].l_name, clients[accnum].balance);
            logged_in();
        }
    }else {
        printf("~~~~~~~~~~~~~~~~~~~~~~\nUser not found!\n~~~~~~~~~~~~~~~~~~~~~~\n");
        menu();
    }
}

void sign_up() {
    /*char fname[30];
    char lname[30];
    char uname[30];
    char passw[30];*/
    int x = 2;
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter you first name: \n");
    scanf("%29s", clients[x].f_name);
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter your last name: \n");
    scanf("%29s", clients[x].l_name);
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter your username: \n");
    scanf("%29s", clients[x].u_name);
    printf("~~~~~~~~~~~~~~~~~~~~~~\nEnter you password: \n");
    scanf("%29s", clients[x].pass);
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    clients[x].balance = 0.00f;
    x++;
}

void menu() {
    printf("~~~~~~~~~~~~~~~~~~~~~~\n(L)og in!\n(S)ign up!\n~~~~~~~~~~~~~~~~~~~~~~\n");
    char ch;
    scanf(" %c", &ch);
    if(ch == 'L' || ch == 'l') {
        log_in();
    }else if(ch == 'S' || ch == 's') {
        sign_up();
        menu();
    }
}

int main() {
    data_clients();
    menu();
    getchar();
    system("pause");
}