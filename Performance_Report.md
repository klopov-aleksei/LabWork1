# Parallel Processing Performance Report: BMP Image Processor

## Executive Summary

This report analyzes the performance improvements achieved by adding parallel processing to a BMP image processing application. The Gaussian filter showed the most significant gains (3.52× speedup), while rotation operations demonstrated near-linear scaling for larger images after optimization.

## 1. Introduction

The original image processing application performed three operations sequentially:

1. 90° clockwise rotation
    
2. 90° counter-clockwise rotation
    
3. Gaussian blur filter

## 2. Parallelization Approach
### 2.1 Hardware Environment

| Component | Specification            |
| --------- | ------------------------ |
| CPU       | M1 (8 cores)             |
| RAM       | 8GB 28-bit LPDDR4X SDRAM |
| OS        | Ubuntu 22.04 LTS         |
| Compiler  | GCC 11.4.0               |

### 2.2 Test Images

| Image Name    | Dimensions | File Size |
| ------------- | ---------- | --------- |
| sample2-2.bmp | 1280×853   | 3.3 MB    |
| sample2-3.bmp | 1920×1280  | 7.4 MB    |

## 3. Performance Results

### 3.1 Small Image Performance (sample2-2.bmp - 1280×853)

| Operation          | 1 Thread  | 2 Threads | 4 Threads | Speedup (4T) |
| ------------------ | --------- | --------- | --------- | ------------ |
| Clockwise Rotation | 2.674 ms  | 1.901 ms  | 2.141 ms  | 1.25×        |
| Counter Rotation   | 1.316 ms  | 0.874 ms  | 0.814 ms  | 1.62×        |
| Gaussian Filter    | 25.592 ms | 15.167 ms | 11.122 ms | 2.30×        |

### 3.2 Large Image Performance (sample2-3.bmp - 1920×1080)

| Operation          | 1 Thread  | 2 Threads | 4 Threads | Speedup (4T) |
| ------------------ | --------- | --------- | --------- | ------------ |
| Clockwise Rotation | 5.328 ms  | 4.051 ms  | 3.192 ms  | 1.67×        |
| Counter Rotation   | 4.462 ms  | 2.015 ms  | 1.832 ms  | 2.44×        |
| Gaussian Filter    | 51.590 ms | 27.305 ms | 15.997 ms | 3.22×        |

## 4.  Conclusion

Overall, multithreaded processing is most effective for the Gauss Filter, which is expected due to its computational complexity. For rotation operations, the benefits of multithreading are less significant, but still present. The efficiency depends on the initial size of an image.