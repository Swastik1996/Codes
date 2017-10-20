const int ROOT = 350;
struct node{
  int l,r,i;
}Q[N];

bool cmp(node x,node y){
  if(x.l/ROOT!=y.l/ROOT){
    return x.l/ROOT < y.l/ROOT;
  }
  return x.r<y.r;
}

void add(int pos){
  
}

void remove(int pos){
  
}

int main() {
    while(L > x)add(--L);
    while(R < y)add(++R);
    while(L < x)remove(L++);
    while(R > y)remove(R--);
  return 0;
} 
