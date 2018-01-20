#include <cstring>
#include <iostream>

using namespace std;

void funcB(int *a, int min, int max);

void funcA (int *a, int size) {
    funcB(a, 0, size-1);
}

void funcB(int *a, int min, int max) {
    if (min == max)
        cout << a[min] << endl;
    else {
        int mid = (min+max)/2;
        funcB(a, min, mid);
        funcB(a, mid+1, max);
    }
}

int main()
{
	int array[] = {1,2,3,4,5};
	int size = 5;

	funcA(array, size);

	return 0;
}