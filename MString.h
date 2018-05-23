
#pragma once

#include <utility>
#include <string.h>
#include <iostream>

class String
{
    friend std::istream &operator >> (std::istream &, String &);
    friend std::ostream & operator<<(std::ostream &out,const String &obj);
public:
  String()
    : size_(0),data_(new char[size_ + 1])
  {
    *data_ = '\0';
  }
 
  String(const char* str)
    : size_(strlen(str)), data_(new char[size_ + 1])
  {
    strcpy(data_, str);
  }
 
  String(const String& rhs)
    : size_(rhs.size()), data_(new char[size_ + 1])
  {
    strcpy(data_, rhs.c_str());
  }
  /* Delegate constructor in C++11
  String(const String& rhs)
    : String(rhs.data_)
  {
  }
  */
 
  ~String()
  {
    delete[] data_;
  }
 
  /* Traditional:
  String& operator=(const String& rhs)
  {
    String tmp(rhs);
    swap(tmp);
    return *this;
  }
  */
  String& operator=(String rhs) // yes, pass-by-value
  {
    swap(rhs);
    return *this;
  }
 
  // C++ 11
  String(String&& rhs)
    : size_(rhs.size()),data_(rhs.data_)
  {
    rhs.data_ = nullptr;
  }
 
  String& operator=(String&& rhs)
  {
    swap(rhs);
    return *this;
  }
 
  // Accessors
  size_t size() const
  {
    return size_;
  }

  size_t length() const
  {
    return size_;
  }
 
  const char* c_str() const
  {
    return data_;
  }
 
  void swap(String& rhs)
  {
    std::swap(size_, rhs.size_);
    std::swap(data_, rhs.data_);
  }

  bool operator==(String& rhs)
  {
    for (size_t i = 0; i < this->size() && i < rhs.size() ; ++i)
    {
        if((*this)[i] != rhs[i])
        {
            return false;
        }
    }
    if(this->size() != rhs.size())
    {
        return false;
    }
    return true;
  }

  char& operator[](int x)
  {
    return *(data_+x);
  }

  char operator[](int x) const
  {
    return *(data_+x);
  }


  bool operator<(String& rhs)
  {
    for (size_t i = 0; i < this->size() && i < rhs.size() ; ++i)
    {
        if((*this)[i] < rhs[i])
        {
            return true;
        }
    }
    if(this->size() < rhs.size())
    {
        return true;
    }
    return false;
  }

 private:
  size_t   size_;
  char* data_;

};
