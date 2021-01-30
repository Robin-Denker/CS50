#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int sentences = 0;
int words = 1;
int letters = 0;
string text;

int main(void)
{
    do 
   {
        text = get_string("Text \n");
       
   }
   while(text<0);
   
       
   for(int j = 0; j < strlen(text); j++){
       if(text[j] == 32){
           words++;
       }
       if(text[j] == 33){
           sentences++;
       }
       if(text[j] == 63){
           sentences++;
       }
       if(text[j] == 46){
           sentences++;
       }
       if(isalpha(text[j])){
           letters++;
       }
           
    }
    //printf("letters: %i; words: %i; sentences: %i\n", letters, words, sentences);
    
    float grade = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}
