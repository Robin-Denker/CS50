#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
     int start;
     int end;
     
     do
        {
           start = get_int("Starting Pop.: ");
        }
        while (start < 9);
      // TODO: Prompt for end size
     do 
        {
            end = get_int("End Pop.: ");
        }
        while(end < start);

    // TODO: Calculate number of years until we reach threshold
     int years = 0;
     if (start != end){
       do
     {
         start += start/3 - start/4;
         years++;
     }
     while (start < end);  
     }
     //Print out years
      printf("Years: %i ", years);
}
