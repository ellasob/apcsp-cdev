#include <stdio.h> 
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float start)
{

	float pi = M_PI;
	float area  = M_PI*start*start;
	return area; 
}


int main(int argc, char* argv[]) 
{

//checking that there is 2 args 

if(argc != 3)
{
	printf("%s : expected 2 args, please enter two ints\n", argv[0]);
	return 1;
}

//checking is arg 1 is an integer
int arg1;
int found = sscanf(argv[1], "%d", &arg1);
if(found != 1)
{
	printf("The first arg is not an integer -- please enter two ints\n");
	return 1;
}

//checking if arg 1 is a positive int
int integer = sscanf(argv[1], "%d", &arg1);
if(integer <= 0)
{
	printf("The first arg is a negative integer -- please enter a positive integer\n");
	return 1;
}

//checking if arg2 is an integer
int arg2;
found = sscanf(argv[2], "%d", &arg2);
if(found != 1)
{
	printf("The second arg is not an integer, enter two ints\n");
	return 1;
}

//checking if arg 2 is a positive int
integer = sscanf(argv[2], "%d", &arg2);
if(integer <= 0)
{
        printf("The second arg is a negative integer -- please enter a positive integer\n");
        return 1;
}

//checking if arg2 > arg1
if(arg1 >= arg2)
{
	printf("Please ensure that arg2 is greater than arg 1\n");
	return 1;
}

//finishing  up
float start = arg1;
int reps = 3;
getTestInput(argc, argv, &start, &reps);

printf("Input lower: %d\n", arg1);
printf("Input upper: %d\n", arg2);

for(float i = arg1; i < arg2+1; i++)
{
	printf("The circle's area is %f\n", areaOfCircle(i));
}
}
