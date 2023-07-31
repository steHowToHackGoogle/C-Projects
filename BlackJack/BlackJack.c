#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct contact {
  char number[11];
  char name[30];
}

struct contact contacts[100];

void menu() {
  char ch;
  printf("~~~~~~~~~~\n(G)o to contacts\n(A)dd new contact\n(E)dit existing contact\n~~~~~~~~~~~~\n");
  
  
}

int main() {
  menu();
}