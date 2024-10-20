///program to test read single char from Keyboard-- by tsaiwn@cs.nctu.edu.tw
/* test_getch.c */
#include <stdio.h>
// 如果用微軟的  MSVC, 可能要 #include <conio.h>              
//   https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/getch-getwch   
/////  https://www.digitalocean.com/community/tutorials/getch-function-in-c-plus-plus  
/////  https://www.geeksforgeeks.org/getch-function-in-c-with-examples/   
///// 請注意, 一般建議不要用 getch( ); 要改用 _getch( ); 這表示它不是標準函數 !
///// 就是說, 用 getch( ) 會被誤會 getch( ) 是標準函數, 但它不是, 所以有些 Compiler 已經禁止，  
int main( ) {
    int gg, yy;
    char arrowKeys[ ][33] = {"Home", "Up上", "PageUp", "", "Left左","", "Right右",
        "", "End", "Down下", "PageDown", "Insert", "Delete"};
    char FKeys[ ] [9] = {"F11", "F12", };   // F11, F12 比較特別 
    fprintf(stderr, "Q to quit 大寫 Q 結束\n"); 
 ggyy:  // 故意用 goto ; 想一想, 如果不用 goto 要怎麼改 ? 對啦就那個 38 == 38 的寫法即可 
    printf("Input: ");
    gg = _getch( );   // 不會 Echo 就是說看不到妳打的字啦        
    if(gg==0 || gg==224) yy = _getch( );  // 必須再讀一次, 這是規定 !          
    printf("Got %d ===character %c\n", gg, gg);   // 有些值用 %c 印出看不到喔 ! 
    if(gg==0 || gg==224) printf("\t Function key or Arrow Key: %d  %d ", gg, yy);
    if(gg==0) printf(" === F%d\n", yy-58);   //59 == F1; 60 == F2, ... F10
    if(gg==224)  // 別懷疑, 我沒寫錯, 只是不想要寫 && 或者 { } 夾住的  Block :-) 
       if (yy >= 133) printf("  == %s  key\n", FKeys[ yy-133 ]);  // F11, F12
       else printf("  == %s  key\n", arrowKeys[ yy-71 ]);  // 71Home ,72up, 75L, 77R, 80down. ..
    if(gg == 'Q') goto bye;  // 只有敲大寫 Q 才結束 
    goto ggyy;   // 繼續 Loop 讀取鍵盤 ; 當然還是用 while( ) 比較好啦, 這故意用 goto   
 bye:
  printf("Bye ! 再見 !\n"); 
  return 0;
} // main(
/// 測試這小範例不必建立專案(project),
