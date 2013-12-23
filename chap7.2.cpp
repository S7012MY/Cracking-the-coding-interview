/*
 * Imagine you have a call center with 3 types of employees: fresher, technical lead(TL),
 * product manager(PM). There can be multiple employees, but only a TL and a PM.
 * An incoming telephone call must be allocated to a fresher who is free. If a fresher can't handle the
 * call, he or she must escalate the call to the TL. If the TL is not free, then the call must be escalated
 * to PM. Design the classes and the data structures for this problem. Implement a method getCallHandler().
 */

 #include <iostream>
 #include <vector>
 using namespace std;

class employee {
public:
	static int last_id;
	int id;
	bool is_free;

};

class fresher:public employee {};
class TL:public employee {};
class PM:public employee {};

class call {};

class call_handler {
public:
	TL tl;
	PM pm;
 	vector<fresher> freshers;

 	call_handler(TL a,PM b) {
 		tl=a;
 		pm=b;
 	}

	void add_fresher(fresher e) {
		freshers.push_back(e);
	}

	employee getCallHandler() {
		for(int i=0; i<freshers.size(); ++i) if(freshers[i].is_free) return freshers[i];
		if(tl.is_free) return tl;
		if(pm.is_free) return pm;
		throw 1;
	}
};



int employee::last_id=0;

int main() {
	
}