/**
 *  Chapter 10 Mathematical
 *
 */
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

//10.1
//Probability p to make a shot
//p to win first game
//C(3,2)*(1-p)*(p^2)+p^3=3*(1-p)*p^2+p^3>p

//10.2
//a) 1-2*(1/2)^3=1-1/2^2=3/4
//b) 1-1/2^(n-1)=(2^(n-1)-1)/2^(n-1)

//10.3
//the slopes must not be equal or the lines must be the same

//10.4
class add_int {
public:
	int n;
	int sign;
	int neg() {
		int d=-1,cn=n,r=0;
		if(n<0) d=1;
		while(cn) {
			cn+=d;
			r+=d;
		}
		return r;
	}
	void operator +=(add_int b) {
		n+=b.neg();
		if(n<0) sign=-1;
		else sign=1;
	}
	void operator *=(add_int b) {
		int cn=n;
		for(int i=1; i<=abs(b.n); ++i) n+=cn;
		if(b.sign==-1) {
			n=neg();
			sign*=-1;
		}
	}
	void operator /=(add_int d) {
		int cn=abs(n);
		n=0;
		while(cn>=abs(d.n)) {
			++n;
			cn-=abs(d.n);
		}
		if(sign*d.sign==-1) {
			n=neg();
			sign=-1;
		}else sign=1;
	}
};

//10.5
class point {
	double x,y;
public:
	double get_x(){return x;}
	double get_y(){return y;}
	void set_x(int nx){x=nx;}
	void set_y(int ny){y=ny;}
	point find_mid(point b) {
		point r;
		r.set_x((x+b.get_x())/2);
		r.set_y((y+b.get_y())/2);
		return r;
	}
};

class line {
	int a,b,c;
	double slope,y_intercept;
	bool infinite_slope;
public:
	line(point x,point y) {
		a=x.get_y()-y.get_y();
		b=y.get_x()-x.get_x();
		c=x.get_x()*y.get_y()-x.get_y()*y.get_x();
		//y=mx+b
		if(y.get_x()!=x.get_x()) {
			infinite_slope=false;
			slope=(y.get_y()-x.get_y())/(y.get_x()-x.get_x());
			y_intercept=x.get_y()-slope*x.get_x();
		}else {
			infinite_slope=true;
			y_intercept=x.get_x();
		}
	}
};

class square {
	point low_left,up_right;
public:
	point find_center(){
		return low_left.find_mid(up_right);
	}
};

line find_line_half(square a,square b) {
	return line(a.find_center(),b.find_center());
}

//10.6
// We compute for all pairs of points the slopes and find the one that occurs the most
// See the implementation of the constructor of the line class

//10.7
int find_kth_magic(int k) {
	queue<int> q3,q5,q7;
	q3.push(3); q5.push(5); q7.push(7);
	int r=1;
	for(int i=1; i<=k; ++i) {
		if(q3.front()<q5.front() && q3.front()<q5.front()) {
			r=q3.front();
			q3.pop();
			q3.push(r*3);
			q5.push(r*5);
			q7.push(r*7);
		}else if(q5.front()<q3.front() && q5.front()<q7.front()) {
			r=q5.front();
			q5.pop();
			q5.push(r*5);
			q7.push(r*7);
		}
		else {
			r=q7.front();
			q7.pop();
			q7.push(r*7);
		}
	}
	return r;
}

int main() {
	cout<<find_kth_magic(1);
}