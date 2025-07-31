#include "img_convert.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RUNS 30

int main() {
    int width, height, i;
    
    scanf("%d %d", &height, &width);
    
    unsigned char* input = malloc(width * height);
    double* output = malloc(width * height * sizeof(double));
    
    // inputted values (comment out for testing)
    for (int i = 0; i < width * height; i++) {
        scanf("%hhu,", &input[i]);
    }

    
    // auto generated values
    /* srand(time(0)); */
    /* for (i = 0; i < width * height; i++) { */
    /*     input[i] = rand() % 256; */
    /* } */


    // usage of windows.h library to access QueryPerformanceCounter (more accurate
    // reading of time). Initially not possible with time.h library
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    
    
    double total_time = 0.0;
    
    for (i = 0; i < NUM_RUNS; i++) {
        LARGE_INTEGER start, end;
        QueryPerformanceCounter(&start);

        convertToDouble(input, output, width, height);
        
        QueryPerformanceCounter(&end);
        double time_used = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
        
        printf("Time for %dx%d: %.6f seconds\n", width, height, time_used);
        total_time += time_used;
    }

    double avg_time = total_time / NUM_RUNS;

    printf("\nAverage execution time for %d runs: %.6f seconds\n", NUM_RUNS, avg_time);

    // comment out when testing with larger values
    printf("Converted image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", output[i * width + j]);
        }
        printf("\n");
    }


  
    free(input);
    free(output);
    return 0;
}
