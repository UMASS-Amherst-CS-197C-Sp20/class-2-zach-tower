#include <stdio.h>

// Fizz-Buzz is a famous interview problem.
// We will do it to learn how to write a text file in C.
//
//
// Print the numbers from 0 to 100 (inclusive) to the file "fizzbuzz.txt" EXCEPT:
//  - If the number is divisible by 3, print "Fizz".
//  - If the number is divisible by 5, print "Buzz".
//  - If the number is divisible by both, print "FizzBuzz".
// Do not output blank lines.
//
void fizzbuzz(int n, FILE *out) {
	if(n == 0)
		fprintf(out, "0 ");
	else
		fprintf(out, " %d ", n);
	if(n % 3 == 0)
		fprintf(out, "Fizz");
	if(n % 5 == 0)
		fprintf(out, "Buzz");
	fprintf(out,"\n");
}
int main(void) {
  const int N = 100;
  // Open a file for writing.
  FILE* out = fopen("fizzbuzz.txt", "w");
  // Demonstrate file I/O.
  fprintf(out, "This doesn't work yet!\n");
	for(int i = 0; i <= 100; i++) {
		fizzbuzz(i, out);
	}
  // We need to close the file we're writing to, otherwise we may lose data.
  fclose(out);
  // Tell the shell/terminal that we were successful.
  return 0;
}
