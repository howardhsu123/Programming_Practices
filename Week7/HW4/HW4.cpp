#include <iostream>

using namespace std;

uint64_t insertion_sort(int arr[400], int len){
    uint64_t count = 0;
    for(int i = 1; i < len; i++){
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            count++;
        }
        arr[j+1] = key;
    }
    return count;
}

int main(void){
    int n;
    int arr[400];
    /*
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    */
    n = 399;
    for(int i = 0; i < n; i++)
        arr[i] = n - i;
    
    cout << insertion_sort(arr,n) << endl;

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}