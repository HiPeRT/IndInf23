#include <iostream>
using namespace std;

int main()
{
    const int N_ELEM = 16;
    int arr[N_ELEM];

    // Init arr
    for(int i=0; i<N_ELEM; i++)
        arr[i]= i;        

    // Work
    for(int i=0; i<N_ELEM; i++)
        arr[i] = arr[i] * 2;

    // Check
    for(int i=0; i<N_ELEM; i++)
        cout << "arr[" << i << "] now is " << arr[i] << endl;    

    return 0;
}