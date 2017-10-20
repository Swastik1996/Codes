//Suffix Array and LCP. O(nlogn)
//https://apps.topcoder.com/forums/?module=RevisionHistory&messageID=1171511

 
//Usage:
// Fill str with the characters of the string.
// Call SA(n), where n is the length of the string stored in str.

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// ran = The inverse of the suffix array. ran[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> ran[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if ran[i] < ran[j]
//lcp[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// lcp[0] = 0


string str; //input
int ran[N], pos[N], lcp[N]; //output
int cnt[N], nex[N]; //internal
bool bh[N], b2h[N];
int rmq[20][N];  //rmq

int n;

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
 
void SA(){
  //sort suffixes according to their first characters
  n = sz(str);
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);

  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      nex[i] = j;
      buckets++;
    }
    if (buckets == n) break; 

    for (int i = 0; i < n; i = nex[i]){
      cnt[i] = 0;
      for (int j = i; j < nex[i]; ++j){
        ran[pos[j]] = i;
      }
    }
 
    cnt[ran[n - h]]++;
    b2h[ran[n - h]] = true;
    for (int i = 0; i < n; i = nex[i]){
      for (int j = i; j < nex[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = ran[s];
          ran[s] = head + cnt[head]++;
          b2h[ran[s]] = true;
        }
      }
      for (int j = i; j < nex[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[ran[s]]){
          for (int k = ran[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[ran[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    ran[pos[i]] = i;
  }
  
  //lcp part 
  lcp[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (ran[i] > 0){
      int j = pos[ran[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      lcp[ran[i]] = h;
      if (h > 0) h--;
    }
  }
  FOR(i,0,n-1)rmq[0][i] = lcp[i];
  FOR(i,1,19){
    FOR(j,0,n-1){
      if(j + (1<<i)-1 >= n)break;
      rmq[i][j] = min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
    }
  }
}
//tell LCP of ith and jth suffix in original string
int LCP(int i, int j){
    if(i==j)return n-i;
    i=ran[i],j=ran[j];
    if(i>j)swap(i,j);
    i++;
    int l=31 - __builtin_clz(j-i+1);
    return min(rmq[l][i],rmq[l][j-(1<<l)+1]);
}
int occ(int opos,int len){
  int l = 0, r = n-1;
  while(l < r){
    int mid = (l+r)/2;
    int lol = pos[mid];
    int lcps = LCP(lol,opos);
    if(lcps < len){
      if(str[lol+lcps] < str[opos+lcps])l = mid + 1;
      else r = mid - 1;
    }
    else r = mid;
  }
  int L = l;
  l = 0, r = n-1;
  while(l < r){
    int mid = (l+r+1)/2;
    int lol = pos[mid];
    int lcps = LCP(lol,opos);
    if(lcps < len){
      if(str[lol+lcps] < str[opos+lcps])l = mid + 1;
      else r = mid - 1;
    }
    else l = mid;
  }
  int R = l;
  return (R-L+1);
}