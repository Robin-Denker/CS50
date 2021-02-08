#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


string key;




int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    int letters[26];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
          if(isdigit(argv[1][i])){
              printf("Error cant use digits\n");
              return 1;
          }
         
           // Check for repeated letters
    for (int j = 0; j < 26; j++)
        {
          if (argv[1][i] == letters[j])
                {
                    printf("Key can not contain repeated letters.\n");
                    return 1;
                }
        }
            
            
        }
        // prompting user for plaintext
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");

            int length = strlen(plaintext);

            for (int c = 0; c < length ; c++)
            {
                // printing any non-alphabet characters unchanged
                if (plaintext[c] < 'A' || (plaintext[c] > 'Z' && plaintext[c] < 'a') || plaintext[c] > 'z')
                {
                    printf("%c", plaintext[c]);
                }
                else
                {
                    for (int b = 0; b <= 25; b++)
                    {
                        if (plaintext[c] == 65 + b)
                        {
                            char upper = argv[1][b];
                            int up = isupper(upper);
                            if (up == 0)
                            {
                                upper = toupper(upper);
                                printf("%c", upper);
                            }
                            if (up != 0)
                            {
                                printf("%c", upper); 
                                
                            }

                        }
                        else if (plaintext[c] == 97 + b)
                        {
                            char lower = argv[1][b];
                            int low = islower(lower);
                            if (low == 0)
                            {
                                lower = tolower(lower);
                                printf("%c", lower);
                            }
                            if (low != 0)
                            {
                                printf("%c", lower);
                            }

                        }

                    }

                }

            }
            printf("\n");
            return 0;
}
