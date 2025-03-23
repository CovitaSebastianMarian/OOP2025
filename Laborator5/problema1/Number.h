#pragma once
class Number
{
	// add data members
	char* value;
	unsigned long long len;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(int);
	Number(const Number&);
	Number(Number&&);
	Number& operator=(const Number&);
	Number& operator=(Number&&);
	Number& operator=(int);
	Number& operator=(const char*);
	char operator[](unsigned long long index) const;
	Number& operator +=(const Number&);
	friend Number operator+(const Number&, const Number&);
	friend Number operator-(const Number&, const Number&);
	bool operator>(const Number& other) const;
	bool operator<(const Number& other) const;
	bool operator>=(const Number& other) const;
	bool operator<=(const Number& other) const;
	bool operator==(const Number& other) const;
	bool operator!=(const Number& other) const;
	Number& operator--();
	Number operator--(int);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
private:
	int ConvertToDecimal() const;
	void ConvertFromDecimal(int nr, int base);
};

