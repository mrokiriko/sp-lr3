// gcc -m32 arr_without_asm.c -o arr && ./arr

#include <stdio.h>
#include <stdlib.h>

void shi(int arr_len, int* arr)
{
    int remember = arr[0];
    for (int j = 0; j < arr_len - 1; j++) {
        arr[j] = arr[j + 1];
    }      
    arr[arr_len - 1] = remember;
}

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
    
    printf("how many shifts to apply? (without asm method)\n");
    scanf ("%d", &shift);

    printf("you had: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }    

    for (int i = 0; i < shift; i++) {
        shi(arr_len, arr);
    }

    printf("\nyou got: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }    
    printf("\n");

    return 0;
}
