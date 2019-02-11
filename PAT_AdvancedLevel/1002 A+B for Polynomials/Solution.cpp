#include <bits/stdc++.h>
using namespace std;

struct Poly {
	double coe;
	int exp;
	Poly(int e, double c) : exp(e), coe(c) {}
};

int getInput(vector<Poly>& poly) {
	int k, a;
	double b;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		poly.push_back(Poly(a, b));
	}

	return k;
}

int main() {
	int k1, k2, k = 0;
	vector<Poly>poly1, poly2, poly;

	k1 = getInput(poly1);
	k2 = getInput(poly2);

	int i, j;
	for (i = 0, j = 0; i < k1 && j < k2; ++k) {
		if (poly1[i].exp > poly2[j].exp) {
			poly.push_back(poly1[i]);
			++i;
		}
		else if (poly1[i].exp < poly2[j].exp) {
			poly.push_back(poly2[j]);
			++j;
		}
		else {
			double tmp = poly1[i].coe + poly2[j].coe;
			if (fabs(tmp) > 0.00001) {
				poly.push_back(Poly(poly1[i].exp, tmp));
				++i, ++j;
			}
		}
	}

	while (i < k1) {
		poly.push_back(poly1[i]);
		++i; ++k;
	}

	while (j < k2) {
		poly.push_back(poly2[j]);
		++j; ++k;
	}

	cout << k;
	for (i = 0; i < k; ++i) {
		printf(" %d %.1f", poly[i].exp, poly[i].coe);
	}

	return 0;
}