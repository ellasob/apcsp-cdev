#include <stdio.h>



// student structure
//struct Student...

struct Student { 
        char firstname[300];
        char lastname[300];
        int age;
        int studentid;
};

void printStudent(struct Student* student)
{
  printf("-----------------Student----------------\n"); 
  printf("First name: %s\n", student->firstname);
  printf("Last name: %s\n", student->lastname);
  printf("Age: %d\n", student->age);
  printf("Student ID: %d\n", student->studentid);
}

void printAllStudents(struct Student students[], int num)
{
 for(int i = 0; i < num; i++)
 {
  printStudent(students + i);
 }
}


int main()
{

struct Student students[7];
char input[300];

  // an array of students
  //xxx students;

  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 300, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
printf("Enter your first name.\n");
fgets(input, 300, stdin);
sscanf(input, "%s", &students[numStudents].firstname);

printf("Enter your last name.\n");
fgets(input, 300, stdin);
sscanf(input, "%s", &students[numStudents].lastname);

printf("Enter your age.\n");
while(1)
	{
	fgets(input, 300, stdin);
	if (sscanf(input, "%d", &students[numStudents].age) == 1) break;
	printf("This is not a valid age! Please try again.\n");
	}

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
