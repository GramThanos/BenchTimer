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

#ifndef BENCHTIMER_LIB_H_
#define BENCHTIMER_LIB_H_

#ifdef __cplusplus
extern "C"{
#endif

// The Benchtimer struct
typedef struct benchtimer {
	// The timestamp the timer started (in seconds)
	double start;
	// The timestamp the timer stopped (in seconds)
	double stop;
	// The time recorded between stop and start (in seconds)
	double timer;
} benchtimer;

// Create and initialize a benchtimer struct
//
//     Returns : 
//         - a pointer to a benchtimer struct
//         - NULL on memory allocation error
//
benchtimer* benchtimer_create();

// Reset a benchtimer
//     Set all values to zero
//
//     Parameters :
//         - b : pointer to the benchtimer struct
//
void benchtimer_reset(benchtimer* b);

// Destroy a benchtimer
//     Free allocated memory
//
//     Parameters :
//         - b : pointer to the benchtimer struct
//
void benchtimer_destroy(benchtimer* b);

// Get sys time in seconds
//
//     Returns : 
//         The system's timestamp in seconds
//
double benchtimer_getSysTime();

// Start benchtimer's timer
//     Set the start value to now
//
//     Parameters :
//         - b : pointer to the benchtimer struct
//
void benchtimer_start(benchtimer* b);

// Stop benchtimer's timer
//     Set the stop value to now
//     calculate the stop - start difference
//     add the difference on the timer
//
//     Parameters :
//         - b : pointer to the benchtimer struct
//
void benchtimer_stop(benchtimer* b);

// Get benchtimer's timer value (in seconds)
//
//     Parameters :
//         - b : pointer to the benchtimer struct
//     Returns : 
//         - The calculated stop - start difference
//
double benchtimer_get(benchtimer* b);

// Sleep
//     Implements a cross platform sleep function
//
//     Parameters :
//         - ms : the time to sleep in ms (ex 1000 = 1 second)
//
void benchtimer_sleep(int ms);

#ifdef __cplusplus
}
#endif

#endif // BENCHTIMER_LIB_H_
