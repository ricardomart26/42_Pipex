// #include <stdio.h>
// #include <stdlib.h>

// int *function(int *pointer)
// {
//     int size;
//     int *pointer2 = malloc (sizeof(int) * 3 + 1);
//     int c;

//     c = 0;   
//     size = 3;
//     while (size--)
//     {
//         pointer2[c] = pointer[size];
//         c++;
//     }  
//     for (int i = 0; i < 3; i++)
//         printf("\npointer 2 = %d\n", pointer2[i]);
//     return (pointer2);
// }

// int main(void)
// {
//     int *pointer = malloc (sizeof(int) * 3 + 1);
//     int *pointer2;
//     int c = 0;

//     while(c < 3)
//     {
//         pointer[c] = c;
//         c++;    
//     }
//     for (int i = 0; i < 3; i++)
//         printf("\npointer = %d\n", pointer[i]);
//     pointer2 = function(pointer);
//     for (int i = 0; i < 3; i++)
//         printf("\npointer = %d\n", pointer[i]);
//     for (int i = 0; i < 3; i++)
//         printf("\npointer 2 2 = %d\n", pointer2[i]);
    
//     return (0);
// }