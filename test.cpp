#include<stdio.h>
char *a =" you";
char b[ ] =" Welcome you to China!" ;
int main()
{
    int i,j=0; char * p;
    for(i=0;b[ i ] ! ='\0';i + + ) 
    { 
        if ( * a = = b[ i ] )
        { 
            p=a;
            for(j=i;*p!='\0';j+ +)
            {
                if(*p! = b[ j ]) break;
                p++ ;
            }
            if(*p= ='\0'){
                break;
            }
   }
   printf("%s",& b[ i ] );
   return 0;
｝