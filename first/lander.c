/* Name: Mandy Meindersma
 * One Card Number: 1433871
 * UNIX ID: meinders
 * Lecture: A1
 * Lab: D01
 * TA's Name: Chenyang Huang*/


/*include my header file*/
#include "lander.h"

/*this is my main function
  it opens the file!
  argc is the length of argv
  argv array of the things you have typed into the command line
  argv[0]=name of the program
  argv[1]=-g
  argv[2]=gravity value
  argv[3]=-t
  argv[4]=thrust value
  argv[5]=-f
  argv[6]=input file*/
int main(int argc, char * argv[]){

  FILE* fp;
 	FILE* sketch;
   
  const char sketchf[] = "java -jar Sketchpad.jar";

	printf("argv[1]: '%s'\n",argv[1]);
	printf("argv[2]: '%s'\n",argv[2]);
	printf("argv[3]: '%s'\n",argv[3]);
	printf("argv[4]: '%s'\n",argv[4]);
	printf("argv[5]: '%s'\n",argv[5]);
	printf("argv[6]: '%s'\n",argv[6]);
	fp = fopen(argv[6], "r");
		if (fp == NULL){
	  	printf("Can not open input file\n");
	  	return (EXIT_FAILURE);
		}/*end if*/


	sketch = popen(sketchf,"w");
	if (sketch == NULL){
		printf("Can not open sketchpad\n");
	  return (EXIT_FAILURE);
	}/*end if*/

	/*parsing file*/
	//parseFile(fp, sketch);

	/*closing*/
	fprintf(sketch,"end\n");
	pclose(sketch);
	fclose(fp);

  return(EXIT_SUCCESS);
}/*end main*/
