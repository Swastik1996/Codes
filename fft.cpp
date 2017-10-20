#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
typedef long double Num;
const Num PI = 3.141592653589793238462643383279L;
typedef complex<Num> Complex;
void fft_main(int n, Num theta, Complex a[]) {
	for(int m = n; m >= 2; m >>= 1) {
		int mh = m >> 1;
		Complex thetaI = Complex(0, theta);
		rep(i, mh) {
			Complex w = exp((Num)i*thetaI);
			for(int j = i; j < n; j += m) {
			int k = j + mh;
			Complex x = a[j] - a[k];
			a[j] += a[k];
			a[k] = w * x;
			}
		}
		theta *= 2;
	}
	int i = 0;
	reu(j, 1, n-1) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1) ;
		if(j < i) swap(a[i], a[j]);
	}
}
void fft(int n, Complex a[]) { fft_main(n, 2 * PI / n, a); }
void inverse_fft(int n, Complex a[]) { fft_main(n, -2 * PI / n, a); }
void convolution(vector<Complex> &v, vector<Complex> &w) {
	int n = 1, vwn = v.size() + w.size() - 1;
	while(n < vwn) n <<= 1;
	v.resize(n), w.resize(n);
	fft(n, &v[0]);
	fft(n, &w[0]);
	rep(i, n) v[i] *= w[i];
	inverse_fft(n, &v[0]);
	rep(i, n) v[i] /= n;
}
const int MOD = 100003;
vector<int> calc_dfs(const vector<int> &A, int l, int r) {
	if(r - l == 1) {
		vector<int> res(2);
		res[0] = 1;
		res[1] = A[l];
		return res;
	}
	int mid = (l + r) / 2;
	vector<int> L = calc_dfs(A, l, mid), R = calc_dfs(A, mid, r);
	vector<Complex> Lc(all(L)), Rc(all(R));
	convolution(Lc, Rc);
	int n = L.size() + R.size() - 1;
	vector<int> res(n);
	rep(i, n) res[i] = (long long)(Lc[i].real() + .5) % MOD;
	return res;
}