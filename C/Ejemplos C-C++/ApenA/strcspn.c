/* strcspn.c
 */
#include <stdio.h>
#include <string.h>

main(void)
{
   char cadena[] = "xyzabc";
   int  pos;
   pos = strcspn( cadena, "abc" );
   printf( "Primer a, b o c en %s es el car�cter %d\n", cadena, pos );
}
