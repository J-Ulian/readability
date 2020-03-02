#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_words (string word);
int count_letters (string letr);
int count_sent (string sent);

int main (void)
{
    string text = get_string("Text:");
  
   int l = count_letters(text);
   int w = count_words(text);
   int s = count_sent (text);
   
  
   double score;
   score = round ((0.0588 * (l / w * 100)) - (0.296 * (s / w * 100)) - 15.8 );
   
   if (score >= 16)
   {
       printf("Grade 16+");
   }
   else if (score < 1)
   {
       printf ("Before Grade 1");
   }
   else
   {
       printf("Grade: %.0f\n", score);
   }

}

int count_letters (string letr)
{
     int l = 0;
    for (int i = 0; i <= strlen(letr); i++)
    {
        if (isalpha(letr[i]) != 0)
        {
            l++;
        }
    }
    return l;
}

int count_words (string word)
{
     int l = 1;
    for (int i = 0; i <= strlen(word); i++)
    {
        if (isblank(word[i]) != 0)
        {
            l++;
        }
    }
    return l;
}

int count_sent (string sent)
{
    int l = 0;
    for (int i = 0; i < strlen(sent); i++)
    {
        if (sent[i]  == '.' || sent[i]  == '!' || sent[i]  == '?')
        {
            l++;
        }
    }
    return l;
}