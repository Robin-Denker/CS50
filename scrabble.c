#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
// Get input words from both players
string word1 = get_string("Player 1: ");
string word2 = get_string("Player 2: ");

// Calculates Score both words
int score1 = compute_score(word1);
int score2 = compute_score(word2);


// if score1 > score2 player 1 wins
if (score1 > score2)
{
    printf("Player 1 wins\n");
}
else if (score2 > score1)
{
    printf("Player 2 wins\n");
}
else
{
    printf("Tie\n");
}
// TODO: Print the winner
}

int compute_score(string word)
{
 int score=0;
 int ascii;
 int len = strlen(word);
 for(int i=0; i<=len; i++){
   // checking if char is uppercase
   if(isupper(word[i])){
   //subtracting the ASCII value (example A = 65; 65 - 65 = 0; 0 = 1 Point)
    ascii = word[i]-65;
    ascii = POINTS[ascii];

   }
   //checking if char is lowercase
   else if(islower(word[i])){
    ascii = word[i]-97;
    ascii = POINTS[ascii];
}
else{
ascii = 0;
}

score+=ascii;
}
return score;
}
