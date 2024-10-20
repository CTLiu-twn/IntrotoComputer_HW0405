#include "myid.h"

// idSum( ) 比 idSum9( ) 多加入檢查碼
int idSum9(const char*); // 宣告; 即使重負宣各只要一樣都不會有問題 !!!
int idSum(const char* id) {  // 利用 idSum9( ) 加上檢查碼; 可用於檢查 id 
   return idSum9(id) + id[9] - '0';  // 把檢查碼也加進去; 檢查碼的 weight 是 1 
}// idSum(  字母變 10..35; weight 1 9 8 7 6 5 4 3 2 1 1  加權  
//  ID 編碼規則 see  https://iottalk.vip/idcheck/  
int idSum9(const char* id) {  // 計算 id 的加權和, 但不包括檢查碼
   int ans = c2n( toupper( id[0] ) );  // c2n( ) 參看 Q&A 區關於身分證練習補充
   ans = (ans/10) + 9 * (ans%10);  // weight 1, 9; 因為 ans/10 取得左邊那位
   int i;  // C23 版本之前不可以像 C++ 那樣寫 for(int i= ...
   for(i=1; i <= 8; ++i)   // id[1], id[2], .. id[8]
       ans += (id[i] - '0') * (9-i);  // 比重 8, 7, 6, 5, 4, 3, 2, 1
   return ans;  // 這 idSum9( ) 只計算 id[0], id[1], .. id[8]  
}// idSum9(  比重 1 9, 8 7 6 5 4 3 2 1
