#include "myid.h"

int returnFirstChar(int numInput) {
    int distictCode[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    return distictCode[numInput];
}