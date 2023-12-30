#include<iostream>
#include<vector>
#include<math.h>
#include<complex>
#include<string>
#include<algorithm>

using namespace std;
typedef complex<double> cpx;
const double PI = acos(-1);

/*FFT, 합성곱 소스코드 출처
https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=221633584963&proxyReferer=https%3A%2F%2Fwww.google.com%2F
*/


//FFT
void FFT(vector<cpx>& f, cpx w) {
	int n = f.size();
	if (n == 1) return;

	vector<cpx> even(n / 2), odd(n / 2);
	for (int i = 0; i < n; ++i) (i % 2 ? odd : even)[i / 2] = f[i];

	FFT(even, w * w);
	FFT(odd, w * w);

	cpx wp(1, 0);
	for (int i = 0; i < n / 2; ++i) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

//합성곱:벡터 a,b를 받아서 크기가 (a,b의 크기보다 큰 2의 제곱수중 가장 작은 것*2)인 합성곱을 반환함
vector<int> poly_multiply(vector<int> A, vector<int> B) {

	vector<cpx> a(A.begin(), A.end());		//convert int vector to complex vector 
	vector<cpx> b(B.begin(), B.end());

	int n = 1;
	int aSize = a.size();
	int bSize = b.size();
	while (n < aSize || n < bSize) n *= 2;
	n *= 2;

	vector<cpx> c(n); a.resize(n); b.resize(n);

	cpx w = cpx(cos((2 * PI) / n), sin((2 * PI / n)));
	FFT(a, w); FFT(b, w);

	for (int i = 0; i < n; ++i) {
		c[i] = a[i] * b[i];
	}

	FFT(c, cpx(1, 0) / w);   //IFFT
	for (int i = 0; i < n; ++i) {
		c[i] /= n;
	}

	vector<int> ret(n);
	for (int i = 0; i < n; i++) {
		ret[i] = (int)round(c[i].real());
	}
	return ret;										//cpx로 연산하고 int로 바꿔서 int로 뱉음 
}

int main() {

	int a, b = 0;
	cin >> a >> b;                                    //a,b 의 크기 입력

	vector<int> f(a + 1), g(b + 1);                   //f(x),g(x) 선언
	for (int i = 0; i < a + 1; ++i) cin >> f[i];
	for (int i = 0; i < b + 1; ++i) cin >> g[i];           //f(x),g(x) 입력

	vector<int> h = poly_multiply(f, g);           //h(x) = f(x)*g(x) 

	int ret = 0;                                  //출력값, XOR의 항등원 0으로 초기화
	for (auto elem : h) ret ^= elem;               //원소들을 XOR해줌

	cout << ret;                                    //출력값 출력


	return 0;
}
