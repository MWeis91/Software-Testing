
// This is the main program file.
//
// It directs the user to several subroutines which perform operations on the database of students.
//
// The database of students is denoted by Student s[100], with students 0-99.
//




#include "stdlib.h"
#include "stdio.h"
#include "input.h" // Links to main.h, provides typedef student(bad design)



int menu(void){
	int choice=0;
	
	printf("\nWelcome to the student database for Software Testing.\n\nYou may enter student information here, "
			"which includes their full name, UID#,\nemail address, and their grades for Essay 1, Essay 2,"
			" and for the term project.\n");
	printf("\nWhat would you like to do?\n\n"
			"\t1. Add student information (name, UID#, and email)\n"
			"\t2. Enter grades for student\n"
			"\t3. Search for student\n"
			"\t4. View student information\n"
			"\t5. Delete a student\n\n"
			"Enter an option number here: ");
			
	scanf("%d", &choice);
	return choice;
}

int main(int argc, char ** argv) {
	
	// array of type Student
	Student s[100];
	int menuOpt;
	
	menuOpt = menu();
	switch (menuOpt){
		case 1:	// Module that handles entering the student's basic information (name, email, UID#)
		  newStudent(s);
		  break;

		case 2:	// Module that searches for a student in the database

		  // search(s);




		case 3:	// Module that sorts the students in the database according to name, email, or UID#
		case 4:	// Module that prints all students currently in database to screen
		case 5: // Module that allows the user to delete a student from the database
		default: printf("Please enter a valid option number\n\n");
	}
	
	return 0;
}
