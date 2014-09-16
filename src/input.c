
// This program handles input of new students, and input of grades(separately)(TODO).


#include "stdlib.h"
#include "stdio.h"
#include "input.h"
#include "string.h"

void newStudent(Student S[]) {


  int i = 0;

  for(int i; i < 100; i++) { // Get the index of the nearest empty space
    if(S[i].name == NULL)
      break;
  }

  printf("\nCreating new student in slot %d/100\n\n",i+1); 



  char nameInput[40];
  char IDInput[40];
  char emailInput[40];

  printf("Please enter the name. (Max 40. Characters)\n");

  scanf("%s",nameInput);

  printf("Please enter the U#.\n");

  scanf("%s",IDInput);

  printf("Please enter the email.\n");

  scanf("%s",emailInput);

  strcpy(S[i].name,nameInput);
  strcpy(S[i].ID,IDInput);
  strcpy(S[i].email, emailInput);



  printf("Student number %d with name %s successfully entered.\n",S[i].ID,S[i].name);
  
}


void enterGrades(Student S[]) {

  // How do we refer to the student? By name?

}

  
  
