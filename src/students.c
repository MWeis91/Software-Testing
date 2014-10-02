// By: Team Washington
//
// This is a simple student database.
//
// It directs the user to several subroutines which perform operations on the database of students.
//
// The database of students is denoted by Student s[100], with students 0-99.
//


#include "stdlib.h"
#include "stdio.h"
#include "string.h"

// Student data structure
typedef struct {
	int allocated;
	char name[40];
	char ID[11];
	char email[40];
	int essayGrade1;
	int essayGrade2;
	int termProject;
} Student;

// Function prototypes
int getIndexByName(Student* s);
int getIndexByID(Student* s);
int getIndexByEmail(Student* s);
int getStudentIndex(Student* s);
void viewStudent(Student *s);
void loadDB(Student* s);
void saveDB(Student* s);
void newStudent(Student* S);
void enterGrades(Student* S);
void sortArray(Student* s);
void deleteStudent(Student* s);

// Scan for a deallocated block, then move all entries after that down a block to eliminate the removed Student.
void sortArray(Student* s)
{
   int i = 0;
   Student* dst = s;
   Student* src = NULL;

   // Scan for a deallocated block
   while ( (dst->allocated != 0) && (i<100) )
   {
      dst = dst + 1;
      i++;    
   }

   // move each block down an index to fill the deallocated slot
   while ( i < 99 )
   {
      // deallocated destination
      dst = s + i;
      // next item = source
      src = dst + 1;
      // copy source data over to destination 
      memcpy(dst, src, sizeof(Student));
      // move to next item pair
      i++;
   }
}

// Search for a student to delete from the database.
void deleteStudent(Student* s)
{
   int index = 0;
   char confirmation = 'n';
   Student* tmp = s;
   
   // get index of student to delete
   printf("Please search for the student to delete.\n");
   index = getStudentIndex(s);
   tmp = tmp + index;
   
   printf("Are you sure you want to delete this student? [y/n]: ");
   scanf("%s", &confirmation);
   getchar();
   
   if (confirmation == 'y')
   {
      // deallocate that entry
      tmp->allocated=0;
   
      // eliminate the deallocated entry from our array
      sortArray(s);
   }
    
}

// Load Student database from students.db
void loadDB(Student* s)
{
   FILE* studentsdb = fopen("students.db", "r");

   printf("Loading student database from students.db...\n");

   fread(s, sizeof(Student), 100, studentsdb);
}

// Save Student database to students.db
void saveDB(Student* s)
{
   FILE* studentsdb = fopen("students.db", "w");

   printf("Saving student database to students.db...\n");

   fwrite(s, sizeof(Student), 100, studentsdb);
}

// Add a new student to the database in memory.
void newStudent(Student* S)
{
  int i = 0;
  Student* tmp = S;

  while (tmp->allocated == 123456)
  {
    tmp = tmp + 1;
    i++;
  }

  printf("\nCreating new student in slot %d/100\n\n",i+1); 


  char nameInput[40];
  char IDInput[11];
  char emailInput[40];

  printf("Please enter the name. (Max 40. Characters)\n\t");

  fgets(nameInput, 40, stdin);
  
  printf("Please enter the U#.\n\t");

  fgets(IDInput, 11, stdin); //Changed to 11, to allow for UXXXXXXXX-style input

  printf("Please enter the email.\n\t");

  fgets(emailInput, 40, stdin);
  
  
  strcpy(tmp->name,nameInput);
  strcpy(tmp->ID,IDInput);
  strcpy(tmp->email, emailInput);
  tmp->allocated = 123456;


  printf("\nStudent number %s with name %s successfully entered.\n", tmp->ID, tmp->name);
  
}

// Input a grade for an assignment, and return that grade.
int getGrade()
{

   int grade = 0;
   
   printf("\tEnter a grade from 0 to 4.\n\t");
   scanf("%d", &grade);
   
   return grade;
   
}
// Choose a grade to modify.
void enterGrades(Student* S)
{

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
   
   switch (choice)
   {
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
   
   // Automatically save database?
}

// Search for students by name
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

// Search for students by ID
int getIndexByID(Student* s)
{
   Student* tmp = s;
   int i = 0;
   char input[11];
   
   printf("Please enter an ID to search for: ");
   fgets(input, 10, stdin);
   
   while (strcmp(tmp->ID, input) && i<100)
   {
      tmp = tmp + 1;
      i++;
   }
   return i;
}

// Search for students by email address
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

// Search for a student by name, ID, or email
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

// Find and display a student's information and grades
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
   printf("\n\tName: ");
   puts(tmp->name);
   printf("\tID: ");
   puts(tmp->ID);
   printf("\tEmail: ");
   puts(tmp->email);
   printf("\n\tEssay 1: %d"
         "\n\tEssay 2: %d"
         "\n\tTerm Project: %d\n\n", tmp->essayGrade1, tmp->essayGrade2, tmp->termProject);
}

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
        
         case 2:   // Module that loads a database file into memory.
            loadDB(s);
            break;

         case 3:   // Module that saves the database to a file
            saveDB(s);
            break;
            
         case 4:   // Module that searches for a student in the database
            viewStudent(s);
            break;
            
         case 5:   // Module that allows the user to enter a grade
            enterGrades(s);
            break;
            
         case 6:   // Delete a student
            deleteStudent(s);
            break;
				
         case 7:   // Exit
            terminateflag = 1;
            break;
				
        	default: 
         printf("Please enter a valid option number.\n\n");
         break;
      }
   }
	
   return 0;
}
