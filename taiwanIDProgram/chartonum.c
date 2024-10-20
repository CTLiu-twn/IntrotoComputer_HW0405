#include "myid.h"

///這是表準查表法 table Lookup
int c2n(char c);  // 宣告
int charToNum(char c) {
   return c2n(c);
}// charToNum(  用起來和 c2n(c) 完全一樣
int c2n(char c) {   // 注意呼叫這之前要先確認 c 是大寫字母
   static int table[ ] = {  // 寫 static 讓這 table 在編譯階段 compile time 就定義好
      10, 11, 12, 13, 14, 15, 16, 17,  34,  // ABCDEFGH I
      18, 19, 20, 21, 22, 35,  // JKLMN O
      23, 24, 25, 26, 27, 28, 29,  // PQRSTUV
      32, 30, 31, 33, };   // W XY Z   允許多一個逗號 ,  注意最後要有分號 };
   if( (c >= 'a') && (c <='z') ) c = c-'a'+ 'A';  // 防呆, 把小寫轉大寫
   if( c < 'A') return -3388; // 防呆, 故意回傳一個負值表示有問題
   if( c > 'Z') return -3388; // 防呆, 故意回傳一個負值表示有問題
   // 剩下 'A' .. 'Z'
   return table[ c - 'A' ]; // 'A' .. 'Z'
} // c2n(
/// OK