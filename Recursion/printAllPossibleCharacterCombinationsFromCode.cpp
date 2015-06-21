#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
If a=1, b=2, c=3,....z=26. Given a string, find all possible codes that string can generate. 
Give a count as well as print the strings.

For example:
Input: "1123". You need to general all valid alphabet codes from this string.

Output List
aabc //a = 1, a = 1, b = 2, c = 3
kbc // since k is 11, b = 2, c= 3
alc // a = 1, l = 12, c = 3
aaw // a= 1, a =1, w= 23
kw // k = 11, w = 23
*/

// Referred
#include<stdio.h>
#include<conio.h>
#include<string.h>
// start = index in the input number
// depth = index in the output string
void generate_alphabets(char *num,char *str,int start,int depth)
{
   if(start>=strlen(num))
   {
       printf("\n %s",str);
       return;
   }

       str[depth]=(num[start]-'0'-1+97);
       generate_alphabets(num,str,start+1,depth+1);
       if(num[start+1])
       {
         int result=(num[start]-'0')*10+(num[start+1]-'0')-1;
         if(result<=25)
         str[depth]=result+97;
         str[depth+1]='\0';

         generate_alphabets(num,str,start+2,depth+1);
       }
}
/*
int main()
{
    char str[50]={'\0'};
    char num[10]="1123";
    generate_alphabets(num,str,0,0);
}*/