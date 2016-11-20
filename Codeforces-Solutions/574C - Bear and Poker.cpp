#include <iostream>
#include <vector>
using namespace std;

int prime_factored[int(1e5 + 5)];
void prime_factorize(int idx)
{
    while (!(prime_factored[idx] % 2))
        prime_factored[idx] /= 2;
    while (!(prime_factored[idx] % 3))
        prime_factored[idx] /= 3;
}
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> prime_factored[i];
        prime_factorize(i);
    }
    int num = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (prime_factored[i] != prime_factored[i + 1])
        {
            cout << "No"; exit(0);
        }
    }
    cout << "Yes" << endl;
}
