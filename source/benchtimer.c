/*
 * BenchTimer v0.2
 * A C benchmark timer library
 * 
 * 
 * MIT License
 * 
 * Copyright (c) 2017 Grammatopoulos Athanasios-Vasileios
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#ifdef __cplusplus
extern "C"{
#endif

// For Malloc
#include <stdlib.h>

// Time Libraries for each system
#ifdef WIN32
	// for Windows
	#include <windows.h>
	// and wrap sleep function
	#define BENCHTIMER_SLEEP_MS(ms) Sleep(ms)
#else
	// for Unix
	#include <sys/time.h>
	#include <sys/resource.h>
	#include <unistd.h>
	// and wrap sleep function
	#define BENCHTIMER_SLEEP_MS(ms) usleep(ms * 1000)
#endif

// Header file
#include "benchtimer.h"


// Create and initialize a benchtimer struct
benchtimer* benchtimer_create(){
	// Allocate memory
	benchtimer* b = (benchtimer*) malloc(sizeof(benchtimer));
	// If there was no allocation error
	if (b != NULL) {
		// Reset timers
		benchtimer_reset(b);
	}
	// Return
	return b;
}

// Reset a benchtimer
void benchtimer_reset(benchtimer* b){
	// Clear values
	b->start = 0;
	b->stop = 0;
	b->timer = 0;
}

// Destroy a benchtimer
void benchtimer_destroy(benchtimer* b){
	// Release memory
	free(b);
}

// Get sys time in seconds for each system
#ifdef WIN32
	// for Windows
	double benchtimer_getSysTime(){
		LARGE_INTEGER t, f;
		QueryPerformanceCounter(&t);
		QueryPerformanceFrequency(&f);
		return (double)t.QuadPart/(double)f.QuadPart;
	}
#else
	// for Unix
	double benchtimer_getSysTime(){
		struct timeval t;
		gettimeofday(&t, NULL);
		return t.tv_sec + t.tv_usec*1e-6;
	}
#endif

// Start benchtimer's timer
void benchtimer_start(benchtimer* b){
	// Set the start time
	b->start = benchtimer_getSysTime();
}

// Stop benchtimer's timer
void benchtimer_stop(benchtimer* b){
	// Set the stop time
	b->stop = benchtimer_getSysTime();
	// Add time to the timer
	b->timer += b->stop - b->start;
}


// Get benchtimer's timer value
double benchtimer_get(benchtimer* b){
	// Set the stop time
	return b->timer;
}


// Sleep
void benchtimer_sleep(int ms){
	BENCHTIMER_SLEEP_MS(ms);
}

#ifdef __cplusplus
}
#endif
