// TODO: Implement this header file

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using std::cout, std::endl;

class MyString{
    private:
        size_t stringCapacity;
        size_t stringLength;
        //int length;
        const char* dataString; //have to delete 
        
    public:
        MyString(); //default
        MyString(const MyString& string); //copy constructor
        MyString(const char* s); //copy from c-string
        ~MyString() ; //delete function

        void resize (size_t n);
        size_t capacity() const noexcept;
        size_t length() const noexcept;
        size_t size() const noexcept;
        const char* data() const noexcept;
        bool empty() const noexcept;
        const char& front() const;
        const char& at (size_t pos) const;
        void clear() noexcept;
        size_t find (const MyString& str, size_t pos = 0) const noexcept;


        MyString& operator= (const MyString& str);
        MyString& operator+= (const MyString& str);
        friend MyString operator+ (const MyString& lhs, const MyString& rhs);
        friend bool operator== (const MyString& lhs, const MyString& rhs);

};

    //MyString operator+ (const MyString& lhs, const MyString& rhs);
    std::ostream& operator<< (std::ostream& os, const MyString& str);

//delete [] MyString;


















#endif