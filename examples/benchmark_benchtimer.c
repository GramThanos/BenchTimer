/*
 * BenchTimer v0.2
 * A C benchmark timer library
 * 
 * Example usage and library test
 */

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchtimer.h"


int main(int argc, char *argv[]){
	// Declare 2 benchtimer pointers
	benchtimer* test_timer;
	benchtimer* actual_timer;
	// Stats
	double min = 99999, avg, max = 0, value;
	// Test Loops
	int loops = 10000;
	int i;

	// Create 2 benchtimer objects
	test_timer = benchtimer_create();
	actual_timer = benchtimer_create();

	// Initialize random
	srand(time(NULL));

	printf("Benchtimer test on Benchtimer times\n");

	// Make tests
	for (i = 0; i < loops; ++i) {
		// Start actual benchtimer
		benchtimer_start(actual_timer);
		// Start test benchtimer
		benchtimer_start(test_timer);
		// Stop test benchtimer
		benchtimer_stop(test_timer);
		// Stop actual benchtimer
		benchtimer_stop(actual_timer);

		// Get value in ms
		value = benchtimer_get(actual_timer) * 1000;
		// Print recorded time in seconds
		printf("Benchtimer took %lf ms to start and stop\n", value);

		if (value < min) {
			min = value;
		}
		else if(value > max) {
			max = value;
		}
		avg += value;

		// Reset timers
		benchtimer_reset(test_timer);
		benchtimer_reset(actual_timer);
	}

	// Calculate average
	avg = avg / loops;

	printf("\n");
	printf("Benchtimer overhead stats (time/2 to time):\n");
	printf("   min: %lf ms to %lf ms\n", min/2, min);
	printf("   avg: %lf ms to %lf ms\n", avg/2, avg);
	printf("   max: %lf ms to %lf ms\n", max/2, max);
	printf("\n");
	printf("(since we test our library with our library,\n");
	printf(" the overhead of our library should be between\n");
	printf(" the recorded time/2 and the recorded time)\n");
	printf("\n");

	return EXIT_SUCCESS;
}
