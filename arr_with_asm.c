// nasm -felf combining.asm && gcc -m32 arr_with_asm.c combining.o -o arr2 && ./arr2

#include <stdio.h>
#include <stdlib.h>

extern void MatrixFill(int, int*); // int arr_len, int* arr

int main()
{
    const int arr_len = 10;
    int arr [arr_len];
    int sum = 0;
    int shift = 0;
    
    // init array
    for (int i = 0; i < arr_len; i++) {
        arr[i] = rand() % (arr_len * 2);
    }     
    
    printf("how many shifts to apply? (with asm method)\n");
    scanf ("%d", &shift);

    printf("you had: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }    

    for (int i = 0; i < shift; i++) {
        MatrixFill(arr_len, arr);
    }

    printf("\nyou got: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }    
    printf("\n");

    return 0;
}
