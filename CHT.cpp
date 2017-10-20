//Link : http://codeforces.com/contest/631/submission/16501267
struct Line {
    ll a, b, get(ll x) { return a * x + b; }
};

struct ConvexHull {
    int size;
    Line *hull;

    ConvexHull(int maxSize) {
        hull = new Line[++maxSize], size = 0;
    }

    bool is_bad(ll curr, ll prev, ll next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }

    void add_line(ll a, ll b) {
        hull[size++] = (Line){a, b};
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    ll query(ll x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hull[m].get(x) <= hull[m + 1].get(x))
                l = m;
            else
                r = m;
        }
        return hull[r].get(x);
    }
};
ConvexHull *hull;
int main(){
  fast;
  hull->size = 0;//set zero
  hull->add_line(a,b);//add line ax + b
  hull->query(x) // max value of ax+b for all lines inserted

  return 0;
}