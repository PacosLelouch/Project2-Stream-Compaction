#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>

template<typename T>
int cmpArrays(int n, T *a, T *b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            printf("    a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
            return 1;
        }
    }
    return 0;
}

void printDesc(const char* desc);

template<typename T>
void printCmpResult(int n, T *a, T *b) {
    printf("    %s \n",
            cmpArrays(n, a, b) ? "FAIL VALUE" : "passed");
}

template<typename T>
void printCmpLenResult(int n, int expN, T *a, T *b) {
    if (n != expN) {
        printf("    expected %d elements, got %d\n", expN, n);
    }
    printf("    %s \n",
            (n == -1 || n != expN) ? "FAIL COUNT" :
            cmpArrays(n, a, b) ? "FAIL VALUE" : "passed");
}

void zeroArray(int n, int* a);

void onesArray(int n, int* a);

void genArray(int n, int* a, int maxval);

void printArray(int n, int* a, bool abridged = false);

template<typename T>
void printElapsedTime(T time, std::string note = "")
{
    std::cout << "   elapsed time: " << time << "ms    " << note << std::endl;
}

void testMain();
