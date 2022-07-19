#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

#define NULL_CHARACTER 1

/* Hargun Bedi
   400185463
   bedih
*/

typedef enum {
    up,
    down,
    left,
    right
} direction;

char *makeString(char *s1, char *s2) {

  char *string_concatenated =
      (char *)malloc(strlen(s1) + strlen(s2) + NULL_CHARACTER);
  if (string_concatenated != NULL)
    return strcat(strcpy(string_concatenated, s1), s2);
  else {
    return NULL;
  }
}

char * fib_seq(int n){
    char * fn1;
    char * fn2;
    char * f;
    int i;
    for (i = 0; i < n; i ++){
        if (i == 0)
            fn1 = "1";
        else if (i == 1)
            fn2 = "0";
        else {
            f = makeString(fn2, fn1);
            fn1 = makeString(fn2, "");
            fn2 = makeString(f, "");
        }
    } 

    return f;
}


int fib(int n, int x, int y, int step, RGB b, RGB f, int w, int h, RGB* image){
    char * fib_word = malloc(sizeof(char) * strlen(fib_seq(n)));
    fib_word = fib_seq(n);

    
    direction dir = up;
    int counter = strlen(fib_seq(n));
        int k;
        for (k = 0; k < w * h; k++){
            image[k] = b;
        }
        int i;
        for ( i = 1; i <= counter; i ++) {
            if (dir == up){
                if (i % 2 == 0 && fib_word[i - 1] == '0')
                    dir = left;
                else if (i % 2 != 0 && fib_word[i - 1] == '0')
                    dir = right;    
                int j;            
                for (j = 0; j < step; j++)
                    image[(x + j)*w + (y)] = f;
                

                x += step;
                continue;
            }
            if (dir == left){
                if (i % 2 == 0 && fib_word[i - 1] == '0')
                    dir = down;
                else if (i % 2 != 0 && fib_word[i - 1] == '0')
                    dir = up;
                int j;
                for (j = 0; j < step; j++)
                    image[(x)*w + (y - j)] = f;


                y -= step;
                continue;
            }
            if (dir == down){
                if (i % 2 == 0 && fib_word[i - 1] == '0')
                    dir = right;
                else if (i % 2 != 0 && fib_word[i - 1] == '0')
                    dir = left;
                int j;
                for (j = 0; j < step; j++)
                    image[(x - j)*w + (y)] = f;
                    
                x -= step;
                continue;
            }

            if (dir == right){
                if (i % 2 == 0 && fib_word[i - 1] == '0')
                    dir = up;
                else if (i % 2 != 0 && fib_word[i - 1] == '0')
                    dir = down; 
                int j;
                for (j = 0; j < step; j++)
                    image[(x)*w + (y + j)] = f;

                y += step;
                continue;
            }
                
            }

    free(fib_word);
    return counter;
}
