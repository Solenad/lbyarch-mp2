## [LBYARCH] Machine Project 2: Image Format Conversion (uint8 to double)
This project uses x86-to-C interface as a platform for achieving the required problem specs.

## **Project specifications**   
A grayscale image is internally represented as a 2 dimensional array. Size is defined by the number of pixels in a row (width), and number of pixels in a column (height). Each cell represents the pixel value. Pixel values in grayscale are represented as white, black, and shades of gray using different numerical data type representation depending on the library used. 

Some Libraries represent using 8 bit unsigned integer. 0 for black, 255 for white, 64 light gray, 191 dark gray, and all other gray values in between.

Image = 

64,  89,  114, 84

140, 166, 191, 84

216, 242, 38,  84

Some Image Processing Libraries represent grayscale images as having double float based pixel values between 0 to 1. 0 for black, 1 for white, 0.25 light gray, 0.75 darker gray, and all other gray values in between.

Image = 

0.25, 0.35, 0.45, 0.33

0.55, 0.65, 0.75, 0.33

0.85, 0.95, 0.15, 0.33

To enable using different image processing libraries simultaneously, conversion from one format to the other has to be done. Perform Mapping from uint8 based integer grayscale to double precision float representation. Each pixel is calculated using ratio and proportion equation (f/i = 1/255)

## How to run

1. Clone the repository:
```bash
git clone https://github.com/Solenad/lbyarch-mp2.git
```
2. Setup the NASM object:
```bash
nasm -f win64 img_convert.asm -o img_convert.obj
```
3. Compile the `main.c` file: 
```bash
gcc main.c img_convert.obj -o img_converter.exe
```
4. Run the `img_converter.exe`:
```bash
img_converter.exe
```

## Varying Input and Output Instructions
There are sections of the code that are commented out and can be uncommented by the user to test various inputs. It can be categorized by: (1) inputs for testing average execution time, and (2) inputs for correctness checking

For testing average execution time, comment out these code snippets:
```C
for (int i = 0; i < width * height; i++) {
  scanf("%hhu,", &input[i]);
}

 printf("Converted image:\n");
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        printf("%.2f ", output[i * width + j]);
    }
  printf("\n");
}
```

For testing correctness of output,, comment out this code snippet:
```C
srand(time(0));
for (i = 0; i < width * height; i++) {
    input[i] = rand() % 256;
}
```


// and



## Performance Analysis

| Image Size | Average Time (30 runs) | Observations |
|------------|-----------------------|-------------|
| 10×10      | 0.000001s             | Extremely fast - completes in microseconds |
| 100×100    | 0.000074s      | About 100x slower than 10×10 (as expected for 100x more pixels) |
| 1000×1000  | 0.003731s     | About 50x slower than 100×100 (matches expected 100x pixel increase, showing good scaling) |

### Key Findings:
1. **Excellent Performance**: The conversion is very fast even for large (1000×1000) images
2. **Linear Scaling**: Time increases roughly proportionally with pixel count
3. **Consistent Execution**: Times are stable across runs (small variance between min/max)

### Why This Matters:
- The assembly implementation efficiently handles:
  - Small images (instantaneous)
  - Large images (still under 4ms for 1 million pixels)
- Perfect for real-time image processing applications

## Sample Outputs
Correctness check result given example:  
<img width="708" height="848" alt="correctness_check" src="https://github.com/user-attachments/assets/51918ed6-6afb-4f29-b629-1806a2f4943b" />

Result for testing average execution time of 1000 * 1000:  
<img width="795" height="797" alt="Screenshot_48" src="https://github.com/user-attachments/assets/dbd806c6-9546-4875-8da3-90774227404d" />

https://drive.google.com/file/d/1qXZM_gc2BvOPFLtKC8wO3PKeQdULqxLD/view?usp=sharing

