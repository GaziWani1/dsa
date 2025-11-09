#include <iostream>
using namespace std;

void fib(int a, int b, int limit)
{
    if (limit < 1)
    {
        return;
    }
    int sum = a + b;
    cout << " , " << sum;
    limit--;
    // return fib(b, sum, limit); // NO BACKTRACKING
    fib(b, sum, limit);

    cout << "\n\nBacktracking :: " << sum;
}

int main()
{
    int a = 0, b = 1;
    cout << a << ", " << b;
    fib(a, b, 7);
    return 0;
}

// 1 , 2 , 3 , 5