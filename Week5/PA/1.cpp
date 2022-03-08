#include <iostream>
#include <numeric>

using namespace std;

void print_array(int arr[], int size, int begin){
    if ( size == begin)
        return;
    cout << arr[begin] << endl;
    print_array(arr, size, begin+1);
}

int main(void){
    int array[10];
    iota (array, array+10, 10);

    for(int i = 0; i<10; i++)
        cout << array[i] << endl;

    print_array(array, 10, 0);
    return 0;
}