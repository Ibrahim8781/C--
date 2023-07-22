

#include<iostream>
#include<string>

using namespace std;

class Integer
{

private:
	int num;
	string str;

public:

	Integer();// a default constructor
	Integer(int n);// a parametrized constructor
	Integer(string s); // a parametrized constructor
	void set(int);//set value
	int get()const; //get value at (i,j)
	int bitCount(); //Returns the number of one-bits in the 2's complement binary
	int compareTo(Integer); //Compares two Integer objects numerically.
	double doubleValue(); //Returns the value of this Integer as a double.
	float floatValue(); //Returns the value of this Integer as a float.
	Integer plus(const Integer& a); //adds two Integers and return the result
	Integer minus(const Integer& a); // subtracts two Integers and return the result
	Integer multiple(const Integer& a); //multiplies two Integers and return the result
	Integer divide(const Integer& a); //divides two Integers and return the result
	static int numberOfLeadingZeros(int x); //Returns the number of zero bits preceding the highest-order ("leftmost") one-bit in the two's //complement binary representation of the specified int value.
	static int numberOfTrailingZeros(int i);
	static string toBinaryString(int x); //Returns string representation of i
	static string toHexString(int i); //Returns string representation of i in base16static
	string toOctString(int i); //Returns string representation of i in base 8
};

Integer::Integer()
{
}

Integer::Integer(int n)
{
	this->num = n;
}

Integer::Integer(string s)
{
	this->str = s;
}

void Integer::set(int a)
{
	this->num = a;
}

int Integer::get() const
{
	return this->num;
}

int Integer::bitCount()
{
	bool bit[32];
	for (int i = 31; i >= 0; i--) {
		int mask = 1 << i;
		bit[i] = (this->num & mask) ? 1 : 0;
	}


	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (bit[i] == 1)
			count++;
	}
	return count;
}

int Integer::compareTo(Integer a)
{
	if (this->num == a.num)
		return 1;
	else
		return 0;
}

double Integer::doubleValue()
{
	return static_cast<double>(this->num);
}

float Integer::floatValue()
{
	return static_cast<float>(this->num);
}

Integer Integer::plus(const Integer& a)
{
	Integer temp;
	temp.num = this->num + a.num;
	return temp;
}

Integer Integer::minus(const Integer& a)
{
	Integer Temp;
	Temp.num = this->num - a.num;
	return Temp;
}

Integer Integer::multiple(const Integer& a)
{
	Integer temp;
	temp.num = this->num * a.num;
	return temp;
}

Integer Integer::divide(const Integer& a)
{
	Integer temp;
	temp.num = this->num / a.num;
	return temp;
}

int Integer::numberOfLeadingZeros(int x)
{
	bool bit[32];
	for (int i = 0; i < 32; i++)
	{
		bit[i] = ((x & (1 << i)) != 0);
	}

	int count = 0;
	for (int j = 31; j >= 0; j--)
	{
		if (bit[j] == 0)
			count++;
		else
			break;
	}
	return count;
}

int Integer::numberOfTrailingZeros(int i)
{
	int count = 0;
	while ((i & 1) == 0) {
		count++;
		i >>= 1;
	}
	return count;
}

string Integer::toBinaryString(int x) {
	string binary = "";
	while (x > 0) {
		binary = to_string(x % 2) + binary;
		x = x >> 1;
	}
	return binary;
}

string Integer::toHexString(int i)
{
	string hex = "";
	const char hex_digits[] = "0123456789ABCDEF";
	if (i == 0) {
		return "0";
	}
	while (i > 0) {
		int rem = i % 16;
		hex = hex_digits[rem] + hex;
		i /= 16;
	}
	return hex;

}

string Integer::toOctString(int i)
{
	string octal = "";
	if (i == 0) {
		return "0";
	}
	while (i > 0) {
		int rem = i % 8;
		char digit = rem + '0';
		octal = digit + octal;
		i /= 8;
	}
	return octal;
}

/*

int main()
{

	Integer obj1(15);
	cout << obj1.bitCount() << endl;
	Integer obj2(15);
	cout << obj1.compareTo(obj2) <<  endl;

	cout << obj1.doubleValue() << endl;
	cout << obj1.numberOfLeadingZeros(15) << endl;
	cout << obj1.numberOfTrailingZeros(20) << endl;

	cout << obj1.toBinaryString(20) << endl;
	cout << obj1.toHexString(97) << endl;
	cout << obj1.toOctString(97) << endl;


	return 0;
}

*/