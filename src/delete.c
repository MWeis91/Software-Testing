// This program will delete a student from the database, freeing up the slot for other entries.
#include "search.h"
#include "main.h"
#include "stdio.h"
#include "delete.h"


void sortArray(Student* s)
{
   // scan for deallocated block followed by allocated data blocks
   // move everything after that down a block
   // repeat
}

void deleteStudent(Student* s)
{
   int index = 0;
   char confirmation = 'n';
   Student* tmp = s;
   
   // get index of student to delete
   printf("Please search for the student to delete.\n");
   index = getStudentIndex(s);
   tmp = tmp + index * sizeof(Student);
   
   printf("Are you sure you want to delete this student? [y/n]: ");
   scanf("%s", &confirmation);
   getchar();
   
   if (confirmation == 'y')
   {
      // deallocate that entry
	  tmp->allocated=0;
   
      // eliminate the deallocated entry from our array
   }
    
}
