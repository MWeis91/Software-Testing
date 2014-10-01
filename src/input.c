
// This program handles input of new students, and input of grades(separately)(TODO).


#include "stdlib.h"
#include "stdio.h"
#include "input.h"
#include "string.h"
#include "search.h"

void loadDB(Student* s)
{
   FILE* studentsdb = fopen("students.db", "r");

   printf("Loading student database from students.db...\n");

   fread(s, sizeof(Student), 100, studentsdb);
}

void saveDB(Student* s)
{
   FILE* studentsdb = fopen("students.db", "w");

   printf("Saving student databse to students.db....\n");

   fwrite(s, sizeof(Student), 100, studentsdb);
}


void newStudent(Student* S) {


  int i = 0;
  Student* tmp = S;

  while (tmp->allocated == 123456)
  {
    tmp = tmp + 1;
    i++;
  }

  printf("\nCreating new student in slot %d/100\n\n",i+1); 



  char nameInput[40];
  char IDInput[40];
  char emailInput[40];

  printf("Please enter the name. (Max 40. Characters)\n\t");

  fgets(nameInput, 40, stdin);

  printf("Please enter the U#.\n\t");

  fgets(IDInput, 10, stdin);

  printf("Please enter the email.\n\t");

  fgets(emailInput, 40, stdin);
  
  strcpy(tmp->name,nameInput);
  strcpy(tmp->ID,IDInput);
  strcpy(tmp->email, emailInput);
  tmp->allocated = 123456;



  printf("\nStudent number %s with name %s successfully entered.\n", tmp->ID, tmp->name);
  
}

int getGrade() {

   int grade = 0;
   
   printf("\tEnter a grade from 0 to 4.\n\t");
   scanf("%d", &grade);
   
   return grade;
   
}
void enterGrades(Student* S) {

   Student* tmp = S;
   int choice = 0;
   // search for a student
   int index = 0;
   
   index = getStudentIndex(S);
   tmp = tmp + index;
   
   // Choose grade to change.
   printf("\nChoose a grade to change: "
         "\n\t1. Essay 1"
		 "\n\t2. Essay 2"
		 "\n\t3. Term Project\n\t");
		 
   scanf("%d", &choice);
   getchar();
   
   switch (choice) {
   
      case 1:
	     tmp->essayGrade1 = getGrade();
	     break;
      case 2:
	     tmp->essayGrade2 = getGrade();
	     break;
      case 3:
	     tmp->termProject = getGrade();
         break;	  
   }

   
   // TODO: Automatically save database?

}

  
  
