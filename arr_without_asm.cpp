// gcc -m32 arr_without_asm.cpp -o arr -lstdc++ && ./arr

#include <stdio.h>
#include <iostream>

using namespace std;

void show_arr(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++) {
        cout << arr[i] << " ";
    }     
}

void shi(int* arr, int arr_len)
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
    
    cout << "how many shifts to apply? (without asm method)" << endl;
    cin >> shift;
    
    cout << "you had: ";
    show_arr(arr, arr_len);

    for (int i = 0; i < shift; i++) {


        shi(arr, arr_len);

    }

    cout << endl;
    cout << "you got: ";

    show_arr(arr, arr_len);
    cout << endl;

    return 0;
}
