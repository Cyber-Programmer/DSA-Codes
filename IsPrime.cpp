#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Function to find the nearest prime number
int nearestPrime(int n) {
    if (isPrime(n))
        return n;
    int smaller = n - 1;
    int larger = n + 1;
    while (true) {
        if (isPrime(smaller))
            return smaller;
        if (isPrime(larger))
            return larger;
        smaller--;
        larger++;
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the hash table: ";
    std::cin >> size;

    if (isPrime(size)) {
        std::cout << "The entered size " << size << " is already a prime number." << std::endl;
    } else {
        int nearest = nearestPrime(size);
        std::cout << "The nearest prime to " << size << " is " << nearest << std::endl;
    }

    return 0;
}
