/* Name: Mandy Meindersma
 * One Card Number: 1433871
 * UNIX ID: meinders
 * Lecture: A1
 * Lab: D01
 * TA's Name: Chenyang Huang*/


/*include my header file*/
#include "lander.h"


/*this is my main function it opens the file!
  argc is the length of argv
  argv array of the things you have typed into the command line
  argv[0]=name of the program
  argv[1]=-g
  argv[2]=gravity value
  argv[3]=-t
  argv[4]=thrust value
  argv[5]=-f
  argv[6]=landscape file*/
int main(int argc, char * argv[]){

	if (argc==8){
		improvements=1;
	}
	else{
		improvements=0;
	}

  FILE* landscape_file;
   
  const char sketchf[] = "java -jar Sketchpad.jar";

	gravity=atof(argv[2]);
	thrust=atof(argv[4]);

	landscape_file = fopen(argv[6], "r");
		if (landscape_file == NULL){
	  	printf("Can not open input file\n");
	  	return (EXIT_FAILURE);
		}/*end if*/

	sketch = popen(sketchf,"w");
	if (sketch == NULL){
		printf("Can not open sketchpad\n");
	  return (EXIT_FAILURE);
	}/*end if*/

	/*parsing file*/
	parseFile(landscape_file);

	/*closing*/
	fprintf(sketch,"end\n");
	pclose(sketch);
	fclose(landscape_file);

  return(EXIT_SUCCESS);
}/*end main*/

