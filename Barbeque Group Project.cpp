#include <iostream>
#include <string>

using namespace std;

class Barbeque {
	private :
		string my_Brand;
		string my_Model;
		bool coal, lights;
	public :
		Barbeque(string brand, string model);
		void loadCoals();
		void light();
		void cook();
		void reset();
		bool hasCoals();
		bool isLit();
		bool isCooking();
};

Barbeque::Barbeque(string brand, string model){
	this->my_Brand = brand;
	this->my_Model = model;
}

bool Barbeque::hasCoals(){
	string option;
	cout << endl << "Do you have coals? "; 
	cin >> option;
	if (option == "yes")
	{
		coal = true;	
		return coal;
	}
	else
	{
		coal = false;
		return coal;
	}
}

bool Barbeque::isLit(){
	string option;
	cout << endl << "Do you have lit?";
	cin >> option;
	if (option == "yes")
	{
		lights = true;
		return lights;
	}
	else 
	{
		lights = false;
		return lights;
	}
}

void Barbeque::loadCoals(){
	cout << "Loading " << my_Brand << " " << my_Model << " with coals!";
}

void Barbeque::light(){
	if(coal)
	cout << "Lightning the grill!";
	else
	cout << "You can't light this " << my_Brand << " " << my_Model << " until you load it with coals!";
}

void Barbeque::cook(){
	if (lights)
	cout << "Cooking food!";
	else
	cout << endl << "You can't cook on this " << my_Brand << " " << my_Model << " until it has been lit!";
}

void Barbeque::reset(){
	coal = false;   // make some errors	
	lights = false;
}

int main(){
	Barbeque bbq("Coleman", "Grill 101A");
	bbq.loadCoals();
	
	if (bbq.hasCoals()) {
		bbq.light();
		if (bbq.isLit()) {
			bbq.cook();
		}
		else {
			cout << "bbq should be lit so this is an error in your logic!" << endl;
		}
	}
	else 
		cout << "bbq should have coal, so this is an error in your logic!" << endl;

	
	bbq.reset();
	cout << endl << "Let's make some errors..." << endl;
	bbq.light(); 	  // print error
	bbq.cook();		  // print error 
	cout << endl;	  
	bbq.loadCoals();  // print output
	bbq.cook();       // print error

	return 0;
}
