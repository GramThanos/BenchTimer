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
	// Declare a benchtimer pointer
	benchtimer* test_timer;
	// Variable to hold milliseconds
	int ms;
	// Stats
	double min = 99999, avg, max = 0, diff;
	// Test Loops
	int loops = 10;

	// Create a benchtimer object
	test_timer = benchtimer_create();

	// Initialize random
	srand(time(NULL));

	printf("Benchtimer test on random sleep times\n");
	printf("We call Sleep(ms) on Windows and usleep(ms * 1000) on Linux\n\n");

	// Make tests
	for (int i = 0; i < loops; ++i) {
		// Generate random milliseconds
		ms = rand() % 1000;

		// Start benchtimer
		benchtimer_start(test_timer);
		// Sleep for ms milliseconds
		benchtimer_sleep(ms);
		// Stop benchtimer
		benchtimer_stop(test_timer);

		// Calculate difference (always positive number right?)
		diff = (benchtimer_get(test_timer) * 1000) - ms;
		// Print recorded time in ms
		printf("Function sleep(%d) took %lf ms\n", ms, benchtimer_get(test_timer) * 1000);

		if (diff < min) {
			min = diff;
		}
		else if(diff > max) {
			max = diff;
		}
		avg += diff;

		// Reset timer
		benchtimer_reset(test_timer);
	}

	// Calculate average
	avg = avg / loops;

	printf("\n");
	printf("Function sleep difference stats:\n");
	printf("   min: +%lf ms\n", min);
	printf("   avg: +%lf ms\n", avg);
	printf("   max: +%lf ms\n", max);
	printf("\n");

	return EXIT_SUCCESS;
}
