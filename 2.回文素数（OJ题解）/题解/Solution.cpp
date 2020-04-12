#include <stdio.h>
#include <math.h>
typedef long long ll;
const int INF = 0x7f7f7f7f;
int xx;

const long N = 1000003;
int prime[N] = { 0 }, num_prime = 0, isNotPrime[N] = { 1, 1 };
int syspri[N], num_syspri = 0;

void isPri() {
	for (ll i = 2; i < N; i++)
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;
		for (ll j = 0; j < num_prime && i * prime[j] < N; j++)
		{
			isNotPrime[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}

int isSys(int val) {
	int reverseVal = 0;
	int valrecord = val;
	do {
		reverseVal = reverseVal * 10 + valrecord % 10;
		valrecord = valrecord / 10;
	} while (valrecord >= 1);
	return reverseVal == val ? 1 : 0;
}

int lower_bound(int *array, int size, int key)
{
	int first = 0, middle;
	int half, len;
	len = size;

	while (len > 0) {
		half = len >> 1;
		middle = first + half;
		if (array[middle] < key) {
			first = middle + 1;
			len = len - half - 1;
		}
		else
			len = half;
	}
	return first;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d", &xx);
	isPri();
	for (int i = 0; i < num_prime; i++) {
		if (isSys(prime[i])) {
			syspri[num_syspri++] = prime[i];
		}
	}
	syspri[num_syspri] = INF;
	int pos = lower_bound(syspri, num_syspri, xx);
	printf("%d\n", min(xx, ceil(syspri[pos] / 2)));
	getchar();
	getchar(); 
	return 0;
}
