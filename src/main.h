#ifndef MAIN_H
#define MAIN_H



// Globally defined Student structure.
//
// As long as main.c includes input.h (or another header file), this *should* be defined.
//
// For other header files, you can include input.h (bad design)



typedef struct {
	int allocated;
	char name[40];
	char ID[10];
	char email[40];
	int essayGrade1;
	int essayGrade2;
	int termProject;
} Student;
#endif
