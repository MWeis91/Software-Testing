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
	
   int i = 0;
   Student* dst = s;
	Student* src = NULL;

   // Scan for a deallocated block
   while ( (dst->allocated != 0) && (i<100) )
   {
      i++;    
   }

	// move each block down an index to fill the deallocated slot
	while ( i < 99 )
	{
		// deallocated destination
		dst = s + i*sizeof(Student);
		// next item = source
		src = dst + sizeof(Student);
		// copy source data over to destination 
		memcpy(dst, src, sizeof(Student));
		// move to next item pair
		i++;
	}
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
		sortArray(s);
   }
    
}
