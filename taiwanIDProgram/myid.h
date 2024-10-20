//myid.h  -- 這個 .h 檔要讓每個 .c 檔案 #include 所以裡面只可以有宣告, 不可以有定義。
#ifndef __MYID_H
#define __MYID_H
// 先把一些必要的 .h 檔 #include 進來; 故意不要 <ctype.h>
#include <stdio.h>    // I/O 有關都在這裡面, 例如 printf( ), gets( ), fgets( ), ...
#include <stdlib.h>   // rand( ) 和 srand( ) 在這裡面; 一些看不出在哪的函數通常也在這裡面
#include <string.h>   // 字串相關函數例如 strcmp( ), strncmp( ), strlen( ), ...
#include <ctype.h>


// Function Declration
void doHelp(); // in util.c
char * toUppers(char * str); // in util.c
int startsWith(const char *prefix, const char *str); // in util.c
int isHelp(const char* str); // in util.c
int isQuit(const char* str); // in util.c
int isGenCMD(const char* str); // in util.c
char* chop(char*p); // in util.c

int returnFirstChar(int numInput); // in returnFirstChar.c

void checkID(const char* id); // in idcheck.c
void generateID(); // in idgen.c

int c2n(char c); // in chartonum.c
int charToNum(char c); // in chartonum.c

int idSum(const char* id); // in idsum9.c
int idSum9(const char* id); // in idsum9.c

#endif