#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int x = 0;

struct contact {
  char number[11];
  char name[30];
}

struct contact contacts[100];

void goto_contact() {
  for(int i = 0; i <= 100; i++) {
    printf("~~~~~~~~~~\n%s\n%s\n~~~~~~~~~~~\n", contacts[i].name, contacts[i].number);
  }
}

void new_contact() {
  char nname[30];
  char nnum[30];
  printf("~~~~~~~~~~\nEnter name: ");
  gets(nname);
  printf("~~~~~~~~~~\nEnter number: ");
  scanf("%s", nnum);
  strcpy(nname, contacts[x].name);
  strcpy(nnum, ccontacts[x].nnum);
  x++;
  printf("Contact added!");
}

void menu() {
  char ch;
  printf("~~~~~~~~~~\n(G)o to contacts\n(A)dd new contact\n(E)dit existing contact\n~~~~~~~~~~~~\n");
  scanf(" %c", ch);
  if(ch == 'G' || ch == 'g') {
    goto_contact();
    menu();
  }else if(ch == 'A' || ch == 'a') {
    new_contact();
    menu();
  }else if(ch == 'E' || ch == 'e') {
    
  }
  
}

int main() {
  menu();
}