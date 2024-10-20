/// some utility functions 一些工具函數
#include "myid.h"
#include <ctype.h>

void doHelp() {
   printf("\nDocumentation: \n");
   printf(" - Enter an ID to check it\n");
   printf(" - Type 'help' for this help message\n");
   printf(" - Type 'gen' to generate a new ID\n");
   printf(" - Type 'quit'/'exit' to exit\n");
}

char * toUppers(char * str) {  // 把字串中小寫字母都轉成大寫字母
   char*p = str;  // p points to str[0]
   while(*p) {  // 還沒碰到 NULL ('\0' 或者說就是 0 啦)
     *p = toupper(*p);   // ctype.h 內的函數名稱都是小寫; 其實整個 C 程式庫都用小寫
     ++p;  // p points to next char
   } // while
   return str;
} // toUppers(

int startsWith(const char *prefix, const char *str)
{   
   int len = strlen(prefix);  // 最多比較這麼多 char
   return strncmp(prefix, str, len) == 0;
} // startsWith(  注意名稱和 Python 的不同, 這樣 With 比較好

int isHelp(const char* str) {
   return startsWith("HE", str);
}// isHelp(

int isQuit(const char* str) {
   if(startsWith("QU", str) ) return 1;
   if(startsWith("EX", str) ) return 1;
   return 0;
} // isQuit(

int isGenCMD(const char* str) {
   if(startsWith("GE", str) ) return 1;
   return 0;
}// isGenCMD( 

char* chop(char*p) {
   char*pOLD = p;
   if(p==0) return p;  // 防呆
    while(38==38) {
      if(p[0] == 0) break;
      if(p[0] == '\n') p[0] = 0;  // 咬掉尾巴的 newLine
      ++p;  // p points to next char
   }// while(
   return pOLD;
} // chop(

//////// 還有啥需要的 function ?