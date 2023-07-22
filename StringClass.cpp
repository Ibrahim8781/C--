
#include<iostream>
#include<string>

using namespace std;

class String
{

private:
	char* data;
	int size;


public:
	String(int l);
	String(const char* alpha);
	String(const String& str);
	int stringLength();

	void clear();
	bool isEmpty();
	int charAt(char c);
	char* getdata();
	bool isEqual(const char* str);
	bool equalsIgnoreCase(const char* str);
	char* substring(const char* substr, int startIndex);


	~String();
	void print();
};



String::String(int l)
{
	this->size = l;
	this->data = new char[size];
}

String::String(const char* alpha)
{
	this->size = strlen(alpha);
	this->data = new char[size] ;
	//strcpy(data, alpha);  copying words from alpha (parameter) to data
	for (int i = 0; i < size; i++)
	{
		   data[i] = alpha[i] ;
	}

}



String::String(const String& str)
{
	this->size = str.size;
	this->data = new char[str.size];

	for (int i = 0; i < size; i++)
	{
		this->data[i] = str.data[i];
	}
}


String::~String()
{
	delete[] data;

}

int String::stringLength()
{
	return this->size;
}

void String::clear()
{
	this->size = 0;
	delete[] data;
	data = new char[size + 1];
	data[0] = '\0';
}

bool String::isEmpty()
{
	if (this->size != 0 && this->data[0] != '\0')
		return false;
	else
		return true;
}

int String::charAt(char c)
{
	for (int i = 0; i < this->size+1; i++)
	{
		if ( data[i]  ==  c)
			return i+1;
	}
	return 0;

}


char* String::getdata()
{
	return this->data;
}

bool String::isEqual(const char* str)
{
	if (this->size != strlen(str))
		return false;

	for (int i = 0; i < size; i++)
	{
		if (this->data[i] != str[i])
			return false;
	}

	return true;
}

bool String::equalsIgnoreCase(const char* str)
{

	if (this->size != strlen(str))
		return false;

	for (int i = 0; i < size; i++) {
		char c1 = data[i];
		char c2 = str[i];

		if (c1 != c2 && c1 != c2 + 32 && c1 != c2 - 32) {
			return false;
		}
	}
	return true;
}

char* String::substring(const char* substr, int startIndex) {
	int substr_len = strlen(substr);
	int data_len = strlen(data);

	for (int i = startIndex; i <= data_len - substr_len; i++) {
		bool found = true;
		for (int j = 0; j < substr_len; j++) {
			if (data[i + j] != substr[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			char* result = new char[data_len - i + 1];
			int k = 0;
			for (int j = i; j < data_len; j++) {
				result[k++] = data[j];
			}
			result[k] = '\0';
			return result;
		}
	}
	return NULL;
}



void String::print()
{
	if (this->size == 0)
		cout << "null";


	else
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->data[i];
		}
	}


}



int main() {
	String s3("ibrahim");
	s3.print();
	cout << endl;

	String s4(s3);
	s4.print();
	cout << endl;

	cout << s4.stringLength() << endl;
	s4.clear();
	s4.print();
	cout << endl;


//	cout << s4.isEmpty() << endl ;
//	cout << s3.isEmpty() << endl;

//cout << s4.charAt('l');
//cout << s3.charAt('o');

//	cout << s3.getdata();

//	cout << s3.isEqual("hello");

//	cout << s3.equalsIgnoreCase("HELLO");

//	cout << s3.substring("h", 1);


	return 0;
}

