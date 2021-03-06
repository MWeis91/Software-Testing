#include "main.h"
#include "search.h"
#include "stdio.h"

int getIndexByName(Student* s)
{
   Student* tmp = s;
   int i = 0;
   char input[40];
   
   printf("Please enter a name: ");
   fgets(input, 40, stdin);

   while ( strcmp(tmp->name, input) && i<100)
   {
      tmp = tmp + 1;
      i++;
   }
   return i;
   // 100 = ERROR!
}

int getIndexByID(Student* s)
{
   Student* tmp = s;
   int i = 0;
   char input[10];
   
   printf("Please enter an ID to search for: ");
   fgets(input, 10, stdin);
   
   while (strcmp(tmp->ID, input) && i<100)
   {
      tmp = tmp + 1;
      i++;
   }
   return i;
}

int getIndexByEmail(Student* s)
{
   Student* tmp = s;
   int i = 0;
   char input[40];
   
   printf("Please enter an email address to search for: ");
   fgets(input, 40, stdin);
   
   while (strcmp(tmp->email, input) && i<100)
   {
      tmp = tmp + 1;
      i++;
   }
   return i;
}

int getStudentIndex(Student* s)
{
   int choice = 0;
   
   // Search by name, id, email
   printf("Search students by\n"
      "\t1. name\n"
      "\t2. ID number\n"
      "\t3. email address\n\n");
	  
   printf("\t");
   scanf("%d", &choice);
   getchar();
	
   switch (choice){
	
      case 1:
         return getIndexByName(s);
      case 2:
         return getIndexByID(s);
      case 3:
         return getIndexByEmail(s);
      default:
         printf("Invalid choice. Try again.\n");
         break;
   }
	
      // error code
      return -1;
}

void viewStudent(Student *s)
{
   Student* tmp = s;
   
   // get student index
   int index = getStudentIndex(s);
   if (index == 100)
   {
      printf("Matching student not found.\n");
      return;
   }
   tmp = tmp + index;
   
   // display record
   printf("\n\tName: %s"
         "\n\tID: %s"
         "\n\tEmail: %s"
         "\n\tEssay 1: %d"
         "\n\tEssay 2: %d"
         "\n\tTerm Project: %d\n\n", tmp->name, tmp->ID, tmp->email, tmp->essayGrade1, tmp->essayGrade2, tmp->termProject);
}
