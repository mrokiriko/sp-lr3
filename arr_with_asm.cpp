// gcc -m32 arr_with_asm.cpp combining.o -o arr2 -lstdc++

// nasm -felf combining.asm
// gcc -m32 arr_with_asm.cpp combining.o -o arr2

#include <stdio.h>
//#include <iostream>
#include <cstdlib>

using namespace std;

void show_arr(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++) {
        //cout << arr[i] << " ";
        printf("%d ", arr[i]);
    }     
}

extern void MatrixFill(int, int*); // int arr_len, int* arr

int main()
{
    const int arr_len = 10;
    int arr [arr_len];
    int sum = 0;
    int shift = 2;
    
    // init array
    for (int i = 0; i < arr_len; i++) {
        arr[i] = rand() % (arr_len * 2);
    }     
    
    // cout << "how many shifts to apply? (with asm method)" << endl;
    // cin >> shift;
    printf("how many shifts to apply? (with asm method)\n");
    
    // cout << "you had: ";
    printf("you had: ");
    show_arr(arr, arr_len);

    for (int i = 0; i < shift; i++) {

        MatrixFill(arr_len, arr);

    }

    // cout << endl;
    // cout << "you got: ";
    printf("\n you got: ");

    show_arr(arr, arr_len);
    // cout << endl;
    printf("\n");

    return 0;
}
