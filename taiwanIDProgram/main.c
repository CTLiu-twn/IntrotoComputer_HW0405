#include "myid.h"

int main( ) { 
   char buf[123];  // buffer for fgets
   doHelp( );  // print documantation for ID check/generate

   while(38==38) {
      fprintf(stderr, "\nInput ID or help for HELP info.: \n"); // stderr: standard error stream.
      fgets(buf, sizeof buf, stdin);
      printf("String recieved.\n");
      buf[strcspn(buf, "\n")] = 0; // Remove \n from fgets() input.

      char * buf2 = toUppers(buf); // Make sure buffer is transformed to upper case.

      if( isQuit(buf2) ) break;
      if( isHelp(buf2) ) { doHelp( ); continue; }
      if( isGenCMD(buf2) ) {
         generateID( );
         continue;
      } // if(

      checkID(buf2);
   } // while(38

   printf("\nThank you for using id/ID ... Bye!\n");
   return 0;
} // main(









