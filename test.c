#include <stdio.h>
#include <assert.h>

void extendedGCD(int a, int b, int *k, int *u, int *v) {
    assert(a >= 0 && b > 0);
    int c = a, d = b;
    int ue = 1, ve = 0, ua = 0, va = 1;
    
    while (c != 0) {
        int q = d / c;
        int temp_c = c;
        c = d - q * c;
        d = temp_c;

        int temp_ue = ue;
        ue = ua - q * ue;
        ua = temp_ue;

        int temp_va = ve;
        ve = va - q * ve;
        va = temp_va;
    }

    *k = d;
    *u = ua;
    *v = va;
}

int ModDiv(int a, int b, int m) {
    int k, u, v;
    extendedGCD(b, m, &k, &u, &v);
    if (k != 1) {
        // b and m are not coprime, division is not defined
        return -1;
    } else {
        // (u * a) % m
        int result = (u * a) % m;
        if (result < 0) result += m;  // ensure result is non-negative
        return result;
    }
}

void test() {
    // Test 1: 5 / 2 % 13
    int result1 = ModDiv(5, 2, 13);
    printf("5 / 2 %% 13 = %d\n", result1);

    // Test 2: 8 / 3 % 11
    int result2 = ModDiv(8, 3, 11);
    printf("8 / 3 %% 11 = %d\n", result2);

    // Test 3: 7 / 4 % 9
    int result3 = ModDiv(7, 4, 9);
    printf("7 / 4 %% 9 = %d\n", result3);
}

int main() {
    test();
    return 0;
}

