#include <stdbool.h>

bool isPowerOfTwo(int n) {
    // Base cases
    if (n == 1)
        return true;
    if (n <= 0 || n % 2 != 0)
        return false;

    // Recursive call
    return isPowerOfTwo(n / 2);
}
