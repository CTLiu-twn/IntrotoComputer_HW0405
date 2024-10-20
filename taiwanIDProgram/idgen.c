#include "myid.h"

void generateID( ) {
   static char i, id[123];  // 故意, 其實不必 123 這麼多;; 順便弄個 i 給 Loop 用 
   fprintf(stderr, "End id generator with words start with \"QU\", for example \"quit\".\n");
   while(38==38) {  
      for(i=0; i <= 10; ++i) id[i] = 0;  // clear ID[ ] 開始的 11 個元素 
      fprintf(stderr, "Insert part of id or enter directly:");
      fgets(id, sizeof id, stdin);  // 不論你輸入啥, 都會給你一個 ID

      id[0] = toupper( id[0] );
      id[1] = toupper( id[1] );  // 若是小寫字母才會轉大寫
      if(id[0] == 'Q' && id[1] == 'U') break; // QUit, quit
      if( ! isupper(id[0]) ) id[0] = 'A' + rand( ) %26;  // 'A' .. 'Z'
      if( id[1] != '1' && id[1] != '2') id[1] = '1' + rand( ) % 2; // '1' or '2'
      for(i=2; i <= 8; ++i) {  // 若原先已經是 '0' .. '9' 就不動它
         if(! isdigit(id[i]) ) id[i] = '0' + rand( ) % 10;  // '0'..'9'
      }// for(i
      // 剩下最後的檢查碼, 依據 ID 編碼規則, 用算的
      int yy = idSum9(id); // 算九個char的  weighted check sum
      int id9 = 10 - (yy % 10);  // 檢查碼的值 10 - (0..9); 注意 10 - 0 等於 10 
      if(id9 == 10) id9 = 0; // 照規定的, 10 要換成 0 確保檢查碼 0 .. 9 
      id[9] = id9 + '0';  // 轉為文字的 '0' .. '9' 
      id[10] = 0;   // NULL terminated string 字串必須用 '\0' (就是 0)結束 
      printf("generated ID is %s\n", id);  // 把 id 印出 
   }// while(
   fprintf(stderr, "ID generator DONE.\n");
}// generateID(  // 如有看不懂, copy/paste 給 chatGPT 問它該段做啥 ?      
/// 你可以輸入 A3388  或者 a12??5566 或 A2 或 ?2 或 ?2555 或者 ??123?5  等等看會怎樣 ? ? 
/// 不過, 這產生器無法指定最後一位檢查碼; WHY ?
/// 思考一下, 若想要也可以指定最後一位, 會遇到啥問題 ?!!  