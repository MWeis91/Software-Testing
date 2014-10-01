
// This is the main program file.
//
// It directs the user to several subroutines which perform operations on the database of students.
//
// The database of students is denoted by Student s[100], with students 0-99.
//




#include "stdlib.h"
#include "stdio.h"
#include "input.h" // Links to main.h, provides typedef student(bad design)
#include "search.h"
#include "delete.h"

int menu(void){
   int choice=0;
	
   printf("\nWelcome to the student database for Software Testing.\n\nYou may enter student information here, "
			"which includes their full name, UID#,\nemail address, and their grades for Essay 1, Essay 2,"
			" and for the term project.\n");
   printf("\nWhat would you like to do?\n\n"
			"\t1. Add a student to the database.(name, UID#, and email)\n"
			"\t2. Load a stored database.\n"
			"\t3. Save the database to a file.\n"
			"\t4. Search for student.\n"
			"\t5. Enter grades for student.\n"
			"\t6. Delete a student.\n\n"
			"\t7. Exit.\n\n"
			"Enter an option number here: ");
			
   scanf("%d", &choice);
   getchar();
   printf("\n");
   return choice;
}

int main(int argc, char ** argv) {
	
   // array of type Student
   Student *s = malloc(sizeof(Student) * 100);
   // zero the newly allocated memory
   memset(s, 0, sizeof(Student)*100);

   int menuOpt;
   int terminateflag = 0;
	
   while (!terminateflag)
   {
      menuOpt = menu();
      switch (menuOpt){
         case 1:	// Module that handles entering the student's basic information (name, email, UID#)
            newStudent(s);
            break;
        
         case 2:	// (TODO) Module that loads a database file into memory.
         
            break;
        	case 3:	// (TODO) Module that saves the database to a file
			
            break;
         case 4:	// Module that searches for a student in the database
            viewStudent(s);
            break;
         case 5: // Module that allows the user to enter a grade
            enterGrades(s);
            break;
         case 6: // (TODO) Delete a student
            deleteStudent(s);
            break;
				
         case 7: // Exit
            terminateflag = 1;
            break;
				
        	default: 
         printf("Please enter a valid option number.\n\n");
         break;
      }
   }
	
   return 0;
}
