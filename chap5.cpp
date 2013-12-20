#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

//5.1
int set_bits(int n,int m,int a,int b) {
	int msk=(1LL<<32)-1,m2=(1<<(b+1))-1;
	m2^=((1<<a)-1);
	msk^=m2;
	n&=msk;
	n|=(m<<a);
	return n;
}

//5.2
string dec_bin(string s) {
	string r;
	int i=0,nr=0;
	double vir=0;
	for(;i<s.size() && s[i]!='.'; ++i) nr=nr*10+s[i]-'0';
	++i;
	for(;nr;nr>>=1) r+=((nr&1)+'0');
	reverse(r.begin(), r.end());
	if(!r.size()) r+='0';
	r+='.';
	double put=1;
	for(;i<s.size(); ++i) {
		vir=vir*10+s[i]-'0';
		put*=0.1;
	}
	vir*=put;
	while(vir>0.00000001) {
		//cerr<<fixed<<setprecision(12)<<vir<<'\n';
		if(r.size()>32) return "ERROR";
		vir*=2;
		if(vir>=1) {
			r+='1';
			vir-=1;
		}else r+='0';
	}
	return r;

}

//5.3
void find_next_prev(int n,int &next,int &prev) {
	next=prev=n;
	int fi=-1;
	for(int i=0; i<=32; ++i)
		if(next&(1<<i)) {
			next^=(1<<i);
			fi=i;		
		}else if(fi!=-1) {
			next^=(1<<i);
			break;
		}
	fi=-1;
	for(int i=32; i>=0; --i)
		if(prev&(1<<i)) {
			prev^=(1<<i);
			fi=i;		
		}else if(fi!=-1) {
			prev^=(1<<i);
			break;
		}
}

//5.4
//n is a power of 2

//5.5
int count_bits(int n) {
	int r=0;
	for(;n;n&=(n-1),++r);
	return r;
}

int dif_bits(int a,int b) {
	return count_bits(a^b);
}

//5.6
int swap_even_odd(int a) {
	return ((a&0x55555555)<<1)|((a&0xaaaaaa)>>1);
}

//5.7
int find_missing(vector<int> v) {
	int sum=0,n=v.size()+1;
	for(int i=0; i<v.size(); ++i) sum+=v[i];
	return n*(n+1)/2-sum;
}

int main() {
	//cout<<dec_bin("3.5");
	//cout<<dif_bits(31,14);
	vector<int> v;
	for(int i=1; i<=7; ++i) if(i!=3)v.push_back(i);
	cout<<find_missing(v);
}