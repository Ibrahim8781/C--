

#include<iostream>

using namespace std;

class Pizza
{

private:
	const char* name ;
	const char* toppings;
	const char* size;
	bool is_ready;
	double price;


public:
	Pizza();


	Pizza(const char* toppingVal, double priceVal); //– a parametrized constructor
	Pizza(const char* toppingVal, double priceVal, const char* nameVal, const char* sizeVal, bool ready_status);
	//Pizza(const char* toppingVal , double priceVal, char* nameVal, char* sizeVal, bool ready_status)
	Pizza(const Pizza& pizza); //– a copy constructor
	void setTopping(const char* toppingVal);//– setter for topping
	void setPrice(double priceVal); //– setter for price
	void setName(const char* nameVal);//– setter for name
	void setSize(const char* sizeVal);//– setter for size
	const char* getTopping();//– getter for topping
	double getPrice(); //- getter for price
	const char* getName(); //– getter for name
	const char* getSize(); //– getter for size
	void makePizza();
	//– function to make pizza(check if topping is not NULL then set value of is_ready to true)
	bool check_status();// - function to check if pizza is ready or not
	~Pizza();

};

Pizza::Pizza()
{
	this->name = "Null";
	this->toppings = "Null";
	this->size = "Null";
	price = 0.0;

}

Pizza::Pizza(const char* toppingVal, double priceVal)
{
	this->toppings = toppingVal;
	this->price = priceVal;
}

Pizza::Pizza(const char* toppingVal , double priceVal, const char* nameVal, const char* sizeVal, bool ready_status)
{
	this->toppings = toppingVal;
	this->price = priceVal;
	this->name = nameVal;
	this->size = sizeVal;
	this->is_ready = ready_status;
}

void  Pizza::setTopping(const char* toppingVal)
{
	this->toppings = toppingVal;
}

void Pizza::setPrice(double priceVal)
{
	this->price = priceVal;
}

void Pizza::setName(const char* nameVal)
{
	this->name = nameVal;
}

void Pizza::setSize(const char* sizeVal)
{
	this->size = sizeVal;
}

const char* Pizza::getTopping()
{
	return toppings ;
}

double Pizza::getPrice()
{
	return this->price;
}

const char* Pizza::getName()
{
	return this->name;
}
const char* Pizza::getSize()
{
	return this->size;;
}

void Pizza::makePizza()
{
	if (toppings != "NULL")
		is_ready = 1;
	else
		is_ready = 0;
}

bool Pizza::check_status()
{
	if (is_ready == 1)
		return 1;
	else
		return 0;
}

Pizza::~Pizza()
{
	cout << "DESTRUCTOR HAS BEEN CALLED" << endl;
}

/*
int main() {
	// Create a pizza with default values
	Pizza defaultPizza;

	Pizza pepperoniPizza("Pepperoni", 10.99);

	Pizza specialPizza("Mushrooms and Olives" , 14.99, "Special Pizza", "Large", false);

	cout << "Pepperoni pizza toppings: " << pepperoniPizza.getTopping() << endl;
	cout << "Special pizza name: " << specialPizza.getName() << endl;
	cout << "Special pizza size: " << specialPizza.getSize() << endl;

	defaultPizza.setName("Plain Pizza");
	defaultPizza.setSize("Small");
	defaultPizza.setTopping("Cheese");
	defaultPizza.setPrice(8.99);

	cout << "Default pizza name: " << defaultPizza.getName() << endl;
	cout << "Default pizza size: " << defaultPizza.getSize() << endl;
	cout << "Default pizza toppings: " << defaultPizza.getTopping() << endl;
	cout << "Default pizza price: " << defaultPizza.getPrice() << endl;

	defaultPizza.makePizza();
	specialPizza.makePizza();

	if (defaultPizza.check_status()) {
		cout << "Default pizza is ready!" << endl;
	} else {
		cout << "Default pizza is not ready." << endl;
	}

	if (specialPizza.check_status()) {
		cout << "Special pizza is ready!" << endl;
	} else {
		cout << "Special pizza is not ready." << endl;
	}

	return 0;
}
*/
