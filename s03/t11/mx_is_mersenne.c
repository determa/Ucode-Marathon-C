#include <stdbool.h>

double mx_pow(double n, unsigned int pow);
bool mx_is_prime(int num);

bool mx_is_mersenne(int n) {
    if (!mx_is_prime(n)) { 
       return false;
    }
	bool res = false;
	int tmp = 0;

	for (int c = 2; tmp <= n && !res; ++c) {
		tmp = mx_pow(2, c) - 1;
		res = (tmp == n);
	}
	return res;
}

