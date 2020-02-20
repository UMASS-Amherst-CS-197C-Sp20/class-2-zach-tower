//INSTRUCTIONS
//Your parser will read from input.txt
//input.txt consists of a series inputs that you need to read.
//each input is proceeded by a flag.
//Each flag will be either I, C, or F.
//I means int, C means char, F means float.

//So for example

//I 7963467 
//means int 7963467

//C H
//means char H

//F 0.7896
//means float 0.7896

//Your parser must read in each input, and then print it to the correct file.
//ints go in ints.txt
//chars go in chars.txt
//floats go in floats.txt

//CODE BEGINS HERE

//include fprintf and fscanf

//begin your main function

//open ints.txt, chars.txt, and floats.txt for writing
//open input.txt for reading
//don't forget that the file access mode is different for each!

//create a char variable to hold the flags you read	

//create an int, char, and float variable to hold the int, char, and float values you read

//while fscanf does not return an EOF error
//read in a flag from input.txt

//if it stands for an int
//read an int from input.txt
//write the int to ints.txt

//if it stands for a char
//read a char from input.txt
//write the char to chars.txt

//if it stands for a float
//read a float from input.txt
//write the float to floats.txt

//once fscanf returns and EOF error return a successful exit status
#include <stdbool.h>
#include <stdio.h>

#define IMODE 0
#define CMODE 1
#define FMODE 2
#define DEFAULT -1

#define ITOKEN 'I'
#define CTOKEN 'C'
#define FTOKEN 'F'

int main(int argc, char *argv[]) {
	FILE *input;
	FILE *ifile;
	FILE *cfile;
	FILE *ffile;
	char token[1024];
	int mode = DEFAULT;

	input = fopen("/nfs/elsrv4/users4/grad/ztower/class-2-zach-tower/homework2/input.txt", "r");
	ifile = fopen("/nfs/elsrv4/users4/grad/ztower/class-2-zach-tower/homework2/ints.txt", "w");
	cfile = fopen("/nfs/elsrv4/users4/grad/ztower/class-2-zach-tower/homework2/chars.txt", "w");
	ffile = fopen("/nfs/elsrv4/users4/grad/ztower/class-2-zach-tower/homework2/floats.txt", "w");

	while(fscanf(input, "%s", token) != EOF) {
		/* debug tool
		printf("Mode is %d\n", mode);
		printf("Token is %s\n", token);
		*/
		switch(mode) {
			case IMODE:
				// we got an integer
				fprintf(ifile, "%s\n", token);
				mode = DEFAULT;
				break;
			case CMODE:
				fprintf(cfile, "%s\n", token);
				mode = DEFAULT;
				break;
			case FMODE:
				fprintf(ffile, "%s\n", token);
				mode = DEFAULT;
				break;
			default:
				switch(token[0]) {
					case ITOKEN:
						mode = IMODE;
						break;
					case CTOKEN:
						mode = CMODE;
						break;
					case FTOKEN:
						mode = FMODE;
						break;
					default:
						printf("%s\n", token);
						return -1;
				} // switch token
		} // switch(mode)
	} // while fscanf
	fclose(input);
	fclose(ifile);
	fclose(cfile);
	fclose(ffile);
} // main
