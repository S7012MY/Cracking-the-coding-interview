#include <iostream>
#include <vector>
#include <string>
using namespace std;

//8.1
int fb[1000];
int fib(int n) {
	if(n==0) return 0;
	if(n==1) return 1;
	return fib(n-1)+fib(n-2);
	fb[1]=1;
	for(int i=2; i<=n; ++i) fb[i]=fb[i-1]+fb[i-2];
	return fb[n];
	int a,b,c;
	a=0,b=1;
	for(int i=2; i<=n; ++i) {
		c=a+b;
		a=b; b=c;
	}
	return c;
}

//8.2
//Part 1 2*n-2 choose n-1=(2*n-2)!/((n-1)!(n-1)!)
int n;
vector<int> x,y;
char grid[55][55];
void find_paths(int a,int b) {
	if(grid[a][b]=='#' || a>n || b>n) return;
	x.push_back(a); y.push_back(b);
	if(a==n && b==n) {
		for(int i=0; i<x.size(); ++i) cout<<x[i]<<' '<<y[i]<<'\n';
		return;
	}
	find_paths(a+1,b);
	find_paths(a,b+1);
	x.pop_back(); y.pop_back();
}

//8.3
void subsets(int n) {
	//does not print the void set
	for(int i=1; i<(1<<n); ++i) {
		for(int j=0; j<n; ++j) if(i&(1<<j)) cout<<j+1<<' ';
		cout<<'\n';
	}
}

//8.4
vector<int> perm;
int fol[55];

void back_perm(int n) {
	if(perm.size()==n) {
		for(int i=0; i<perm.size(); ++i) cout<<perm[i]<<' ';
		cout<<'\n';
	}
	for(int i=1; i<=n; ++i) if(!fol[i]) {
		fol[i]=1;
		perm.push_back(i);
		back_perm(n);
		perm.pop_back();
		fol[i]=0;
	}
}

void gen_perm(int n) {
	back_perm(n);
}

//8.5
vector<char> parr;

void back_para(int nro,int n){
	if(nro<0) return;
	if(parr.size()==n) {
		if(nro==0) {
			for(int i=0; i<parr.size(); ++i) cout<<parr[i];
			cout<<'\n';
		}
		return;
	}
	parr.push_back('('); back_para(nro+1,n); parr.pop_back();
	parr.push_back(')'); back_para(nro-1,n); parr.pop_back();
}
void gen_para(int n) {
	n*=2;
	back_para(0,n);
}

//8.6
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
char colors[55][55];
//we call this function like this: paint(x,y,n,colors[x][y],target)
void paint(int a,int b,int n,char init_color,char target_color) {
	if(a<0 || b<0 || a>=n || b>=n || colors[a][b]!=init_color) return;
	colors[a][b]=target_color;
	for(int d=0; d<4; ++d) {
		paint(a+dx[d],b+dy[d],n,init_color,target_color);
	}
}

//8.7
vector<int> coins,way;
void back_pos(int first_index,int target_sum) {
	if(target_sum<0) return;
	if(target_sum==0) {
		for(int i=0; i<way.size(); ++i) cout<<way[i]<<' ';
		cout<<'\n';
		return;
	}
	for(int i=first_index; i<coins.size(); ++i) {
		way.push_back(coins[i]);
		back_pos(i,target_sum-coins[i]);
		way.pop_back();
	}
}

void gen_pos(int n) {
	coins.push_back(25); coins.push_back(10); coins.push_back(5); coins.push_back(1);
	back_pos(0,n);
}

//8.8
//11 12 13 14
//21 22 23 24
//31 32 33 34
//41 42 43 44
int m[55][55],row[55];

int check(int r,int c,int n) {
	for(int i=0; i<r; ++i) if(row[i]-i==c-r || row[i]+i==c+r || row[i]==c) return 0;
	return 1;
}

void put(int i,int n) {
	if(i==n) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) cout<<m[i][j];
			cout<<'\n';
		}
		cout<<'\n';
		return;
	}
	for(int j=0; j<n; ++j) {
			row[i]=j;
			if(check(i,j,n)) {
				m[i][j]=1;
				put(i+1,n);
				m[i][j]=0;
			}
	}
	row[i]=i*i;
	put(i+1,n);
}

void gen_queen(int n) {
	put(0,n);
}

int main() {
	//cout<<fib(0);
	//cout<<fib(1);
	//cout<<fib(2);
	//cout<<fib(10);
	//subsets(4);
	//back_perm(4);
	//gen_para(3);
	//gen_pos(12);
	gen_queen(4);
}