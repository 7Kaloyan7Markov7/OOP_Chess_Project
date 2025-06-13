#include <cstring>
#include <iostream>
#pragma once

constexpr int MAX_SIZE_BUFFER = 1024;

class String
{
private:

	char* data = nullptr;
	size_t capacity = 8;

	void free();
	void copyFrom(const String& other);
	void moveTo(String&& other);
	void resize(size_t newCapacity);

public:

	String();
	String(size_t capacity);
	String(const char* data);
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	String& operator = (const String& other);
	String& operator = (String&& other) noexcept;

	String& operator += (const String& other);
	String& operator += (const char* data);

	const char& operator [] (size_t index) const;
	char& operator [] (size_t index);

	String substr(size_t from, size_t to) const;
	bool empty() const;
	const char* getData() const;
	size_t getLen() const;

	friend std::ostream& operator << (std::ostream& os, const String& str);
	friend std::istream& operator >> (std::istream& is, String& str);

};

String operator + (const String& left, const String& right);
String operator + (const String& str, const char* data);
String operator + (const char* data, const String& str);

bool operator == (const String& left, const String& right);
bool operator != (const String& left, const String& right);
bool operator < (const String& left, const String& right);
bool operator > (const String& left, const String& right);
bool operator <= (const String& left, const String& right);
bool operator >= (const String& left, const String& right);
bool operator == (const String& left, const char* right);
bool operator != (const String& left, const char* right);
bool operator < (const String& left, const char* right);
bool operator > (const String& left, const char* right);
bool operator <= (const String& left, const char* right);
bool operator >= (const String& left, const char* right);
bool operator == (const char* left, const String& right);
bool operator != (const char* left, const String& right);
bool operator < (const char* left, const String& right);
bool operator > (const char* left, const String& right);
bool operator <= (const char* left, const String& right);
bool operator >= (const char* left, const String& right);