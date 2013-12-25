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
protected:
	int id;
	bool is_free_1;
public:
	static int last_id;
	bool is_free() {
		return is_free_1;
	}
	void set_free(bool v) {
		is_free_1=v;
	}
	employee() {id=last_id++;}
};

class fresher:public employee {};
class TL:public employee {};
class PM:public employee {};

class call {};

class call_handler {
private:
	TL tl;
	PM pm;
 	vector<fresher> freshers;
public:
 	call_handler(TL a,PM b) {
 		tl=a;
 		pm=b;
 	}

	void add_fresher(fresher e) {
		freshers.push_back(e);
	}

	employee getCallHandler() {
		for(int i=0; i<freshers.size(); ++i) if(freshers[i].is_free()) return freshers[i];
		if(tl.is_free()) return tl;
		if(pm.is_free()) return pm;
		throw 1;
	}
};



int employee::last_id=0;

int main() {
	
}