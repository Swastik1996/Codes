const int OmegaMax = 1;
int OmegaPrim = 5;
int Omega[OmegaMax + 1];

void fft_init() {
	if (Omega[OmegaMax] != 0) return;
	int x = OmegaPrim;
	for (int i = OmegaMax; i >= 0; i --) {
		Omega[i] = x;
		x = mul(x,x);
	}
}
void fft_main(int logn, const bool inv, fft_mint a[]) {
	fft_init();
	int n = 1 << logn;
	int ww = Omega[logn];
	if (inv) ww = expo(ww,mod-2);
	for (int m = n, mi = 0; m >= 2; m >>= 1, mi ++) {
		int mh = m >> 1;
		int w = 1;
		FOR(i,0, mh-1) {
			for (int j = i; j < n; j += m) {
				int k = j + mh;
				int x = add(a[j],mod- a[k]);
				a[j] = add(a[j],a[k]);
				a[k] = mul(w , x);
			}
			w = mul(w,ww);
		}
		ww = mul(ww,ww);
	}
	int i = 0;
	FOR(j, 1, n - 1) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(a[i], a[j]);
	}
}
void fft(int logn, int a[]) { fft_main(logn, false, a); }
void inverse_fft(int logn, int a[]) {
	fft_main(logn, true, a);
	int n = 1 << logn;
	fft_mint invn = expo(n,mod-2);
	FOR(i,0,n-1) a[i] = mul(a[i],invn);
}
void convolution(int v[], int w[], int logn) {
	fft(logn, v); fft(logn, w);
	FOR(i,0, (1 << logn) -1) v[i] = mul(w[i],v[i]);
	inverse_fft(logn, v);
}