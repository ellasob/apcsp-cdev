//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
 Student* st = (Student*) malloc(sizeof(Student));
 st->firstName = (char*) malloc(strlen(fname)+1);  
 st->lastName = (char*) malloc(strlen(lname)+1);
 strcpy(st->firstName, fname);
 strcpy(st->lastName, lname);
 st->age = age;
 st->id = id;

 students[numStudents]= st;
 numStudents++;

}


void deleteStudent(Student* st)
{
 free (st->firstName);
 free (st->lastName);
 free (st);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0

 for(int i = 0; i < numStudents; i++)
 {
  deleteStudent(students[i]);
  students[i] = 0;
 }
 numStudents = 0;
}


void saveStudents(int key)
{
  FILE* fp = fopen(STUFILE, "w");

  if (fp)
  {

  	for(int i = 0; i < numStudents; i++)
  	{
		int keys[1];
		keys[0] = key;

		encrypt(students[i]->firstName, keys, 1);
		encrypt(students[i]->lastName, keys, 1);

		char ageString[256];
		char idString[256];

		sprintf(ageString, "%d", students[i]->age);
		sprintf(idString, "%ld",students[i]->id);
		encrypt(ageString, keys, 1);
		encrypt(idString, keys, 1);

		printf("Saving: %s %s %d %ld.\n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
		fprintf(fp, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
	}
  printf("Saved %d students.\n", numStudents);
  }

  fclose(fp);
}

void loadStudents(int key)
{
  if(numStudents > 0)
  {
	deleteStudents();
  }
 
  FILE* fp = fopen(STUFILE, "r");

  if(fp)
  {
	char b1[256];
  	char b2[256];
  	char b3[256];
  	char b4[256];

  	int age;
  	long id;
	int z = 0;
	numStudents = 0;

	do
	{
		z = fscanf(fp, "%s %s %s %s\n",b1, b2, b3, b4);
		if(z > 0)
		{
			int keys[1];
			keys[0] = key;
			decrypt(b1, keys, 1);
			decrypt(b2, keys, 1);
			decrypt(b3, keys, 1);
			decrypt(b4, keys, 1);
        		sscanf(b3,"%d", &age);
        		sscanf(b4,"%ld", &id);
			createStudent(b1, b2, age, id);
		}
  	}
  while (z > 0);
  fclose(fp);
  printf("Loaded %d students", numStudents);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




