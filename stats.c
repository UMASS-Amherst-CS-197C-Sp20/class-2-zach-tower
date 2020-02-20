#include <stdio.h>
#include <math.h>

// This is a constant defined using the "preprocessor".
#define MAX_ENTRIES 5

double max(double *e, int l);
double min(double *e, int l);
double sum(double *e, int l);
double mean(double *e, int l);
double stddev(double *e, int l);

// Given an array of doubles `entries` of size `length`, let's calculate some basic statistics (Check wikipedia if you don't remember how to do stddev).
double max(double *entries, int length) {
	double max = entries[0];
	double current;
	for(int i = 0; i < length; i++) {
		current = entries[i];
		if(current > max) max = current;
	}

	return max;
}

double min(double *entries, int length) {
	double min = entries[0];
	double current;
	for(int i = 0; i < length; i++) {
		current = entries[i];
		if(current < min) min = current;
	}

	return min;
}

double sum(double *entries, int length) {
	double s;
	for(int i = 0; i < length; i++) {
		s += entries[i];
	}
	return s;
}

double mean(double *entries, int length) {
	if(length == 0) return 0;
	return sum(entries, length) / length;
}

double stddev(double *entries, int length) {
	if(length < 2) return 0;
	double me = mean(entries, length);
	double sum_squared;

	for(int i = 0; i < length; i++) {
		sum_squared += pow(entries[i] - me, 2);
	}

	return sqrt(1 / (length - 1) * sum_squared);
}

void print_stats(double *entries, int length) {
  double s = sum(entries, length);
  double me = mean(entries, length);
  double ma = max(entries, length);
  double mi = min(entries, length);
  double sdev = stddev(entries, length);
  printf("\tN=%d\n", length);
  printf("\tsum=%lf\n", s);
  printf("\tmean=%lf\n", me);
  printf("\tmax=%lf\n", ma);
  printf("\tmin=%lf\n", mi);
  printf("\tstddev=%lf\n", sdev);
}

// When scanf gets the wrong thing, it halts immediately. This function "clears" input by reading until the next newline or the end of the stream (EOF).
void ignore_input() {
  int c;
  while (1) {
    c = getchar();
    if (c == EOF || c == '\n')
      break;
  }
}

int main(void) {
  // Keep track of an array of items.
  double entries[MAX_ENTRIES];
  // Keep track of how many items are in it.
  int filled = 0;

  while(1) {
    // "clear" the array by ignoring the old items.
    filled = 0;

    // Stop when we run out of space.
    while(filled < MAX_ENTRIES) {
      // Tell the user what they're writing to.
      printf("entry[%d]=", filled);
      fflush(stdout);

      // Take input if possible.
      double input;
      int status = scanf("%lf", &input);

      if (status == 1) {
        // They entered a number!
        entries[filled++] = input;
        // When we get an item, print the statistics so far.
        print_stats(entries, filled);
      } else if(status == EOF) {
        // They tried to quit.
        printf("Ctrl-D received. Exiting.\n");
        return 0;
      } else {
        // They entered something that's not a number.
        printf("Error. Enter only a single floating point number (e.g., 3.14).\n");
        ignore_input();
      }
    }

    // TODO: print all the items entered here:
    for(int i = 0; i < filled; i++) {
      printf("entry[%d]=%f\n", i, entries[i]);
    }
  }
}

