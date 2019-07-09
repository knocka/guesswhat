#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

template <typename T> 
T hello_add(const T & a, const T & b) {
	cout << "T: " << typeid(a).name() << '\n';
	return a + b;
};

template <> 
string hello_add<string>(const string & a, const string & b) {
	return a + '*' + b;
};

template <class T> 
class Hello {
private:
	T x_;
public:
	Hello(T a) {
		cout << "T: " << typeid(a).name() << '\n';
		x_ = a; 
	};
	Hello& operator+(const Hello & other) {
		cout << "T: " << typeid(other).name() << '\n';
		x_ += other.x_;
		return *this;
	};
	T x() { return x_; }
};

template <>
class Hello <string> {
private:
	string x_;
public:
	Hello(string a) { 
		cout << "T: " << typeid(a).name() << '\n';
		x_ = a; 
	};
	Hello& operator+(const Hello & other) {
		cout << "T: " << typeid(other).name() << '\n';
		x_ = x_ + '$' + other.x_;
		return *this;
	};
	string x() { return x_; }
};

