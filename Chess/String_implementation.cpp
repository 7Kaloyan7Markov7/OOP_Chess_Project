#include "String_declaration.h"
#pragma warning (disable : 4996)

void String::free()
{
    delete[] data;
    data = nullptr;
    capacity = 8;
}

void String::copyFrom(const String& other)
{
    capacity = other.capacity;
    data = new char[capacity];
    strncpy(data, other.data, strlen(other.data));
    data[strlen(other.data)] = '\0';
}

void String::moveTo(String&& other)
{
    data = other.data;
    capacity = other.capacity;

    other.data = nullptr;
    other.capacity = 8;
}

void String::resize(size_t newCapacity)
{
    if (newCapacity <= capacity) return;

    char* newData = new char[newCapacity];
    strncpy(newData, data, strlen(data));
    newData[strlen(data)] = '\0';

    delete[] data;
    data = newData;
    capacity = newCapacity;
}



String::String()
{
    capacity = 8;
    data = new char[capacity];
    data[0] = '\0';
}

String::String(size_t capacity)
{
    data = new char[capacity] {};
    data[0] = '\0';
    this->capacity = capacity;

}

String::String(const char* data)
{
    if (!data) throw std::runtime_error("Nullptr");

    size_t sizeOfStr = strlen(data);
    this->capacity = 8;

    while (this->capacity < sizeOfStr + 1) this->capacity *= 2;

    this->data = new char[capacity];
    strncpy(this->data, data, strlen(data));
    this->data[strlen(data)] = '\0';
}

String::String(const String& other)
{
    copyFrom(other);
}

String::String(String&& other) noexcept
{
    moveTo(std::move(other));
}

String::~String()
{
    free();
}

String& String::operator = (const String& other)
{
    if (this != &other)
    {

        free();
        copyFrom(other);

    }

    return *this;
}

String& String::operator = (String&& other) noexcept
{
    if (this != &other)
    {

        free();
        moveTo(std::move(other));

    }

    return *this;
}



String& String::operator += (const String& other)
{
    size_t size1 = getLen();
    size_t size2 = other.getLen();
    size_t needed = size1 + size2 + 1;

    while (needed > capacity) resize(capacity * 2);
    strncat(data, other.data, strlen(other.data));

    return *this;
}

String& String::operator += (const char* str)
{

    size_t size1 = getLen();
    size_t size2 = strlen(str);
    size_t needed = size1 + size2 + 1;

    while (needed > capacity) resize(capacity * 2);
    strncat(data, str, strlen(str));

    return *this;
}



const char& String::operator [] (size_t index) const
{
    if (!data || index >= getLen())  throw std::out_of_range("String index out of range");
    return data[index];
}

char& String::operator [] (size_t index)
{
    if (!data || index >= getLen())  throw std::out_of_range("String index out of range");
    return data[index];
}



String String::substr(size_t from, size_t to) const
{

    if (!data || from > to || to > getLen()) throw std::out_of_range("String substr indices");

    size_t sizeOfStr = to - from;
    String result;

    result.capacity = 8;
    while (result.capacity < sizeOfStr + 1) result.capacity *= 2;
    result.data = new char[result.capacity];

    const char* ptr = data + from;
    strncpy(result.data, ptr, sizeOfStr);
    result.data[sizeOfStr] = '\0';

    return result;
}

bool String::empty() const
{
    return !data || data[0] == '\0';
}

size_t String::getLen() const
{
    return data ? std::strlen(data) : 0;
}

const char* String::getData() const
{
    return data;
}



std::ostream& operator << (std::ostream& os, const String& str)
{

    return os << (str.data ? str.data : "");

}

std::istream& operator >> (std::istream& is, String& str)
{

    char buffer[MAX_SIZE_BUFFER];
    is >> buffer;

    str.free();
    str.capacity = 8;
    while (str.capacity < strlen(buffer) + 1) str.capacity *= 2;

    str.data = new char[str.capacity];
    strncpy(str.data, buffer, strlen(buffer));
    str.data[strlen(buffer)] = '\0';

    return is;

}



String operator + (const String& left, const String& right)
{

    String result(left);
    result += right;

    return result;

}

String operator + (const String& str, const char* data)
{

    String result(str);
    result += data;

    return result;

}

String operator + (const char* data, const String& str)
{

    String result(str);
    result += data;

    return result;

}



static int lexCompare(const char* a, const char* b)
{

    while (*a && *a == *b) { ++a; ++b; }
    return (unsigned char)*a - (unsigned char)*b;

}

bool operator == (const String& left, const String& right)
{

    return std::strcmp(left.getData(), right.getData()) == 0;

}

bool operator != (const String& left, const String& right)
{
    return !(left == right);
}

bool operator < (const String& left, const String& right)
{
    return std::strcmp(left.getData(), right.getData()) < 0;
}

bool operator > (const String& left, const String& right)
{
    return right < left;
}

bool operator <= (const String& left, const String& right)
{
    return !(right < left);
}

bool operator >= (const String& left, const String& right)
{
    return !(left < right);
}

bool operator == (const String& left, const char* right)
{
    return std::strcmp(left.getData(), right) == 0;
}

bool operator != (const String& left, const char* right)
{
    return !(left == right);
}

bool operator < (const String& left, const char* right)
{
    return std::strcmp(left.getData(), right) < 0;
}

bool operator > (const String& left, const char* right)
{
    return std::strcmp(left.getData(), right) > 0;
}

bool operator <= (const String& left, const char* right)
{
    return !(left > right);
}

bool operator >= (const String& left, const char* right)
{
    return !(left < right);
}

bool operator == (const char* left, const String& right)
{ 
    return right == left;
}

bool operator != (const char* left, const String& right)
{
    return right != left; 
}

bool operator < (const char* left, const String& right)
{
    return std::strcmp(left, right.getData()) < 0; 
}

bool operator > (const char* left, const String& right)
{
    return std::strcmp(left, right.getData()) > 0; 
}

bool operator <= (const char* left, const String& right) 
{
    return !(left > right); 
}

bool operator >= (const char* left, const String& right) 
{ 
    return !(left < right); 
}