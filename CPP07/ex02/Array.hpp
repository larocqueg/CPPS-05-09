/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:45:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/16 18:45:49 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

template <typename T>

class Array
{
  private:
    T*  _data;
    unsigned int  _size;

  public:
    
    Array() : _data(NULL), _size(0)
    {
      std::cout << GREEN << "Array of size " << _size << " was created!" << RESET << std::endl;
    }
    
    Array(unsigned int n)
    {
      if (n > 0)
      {
        std::cout << GREEN << "Array of size " << n << " was created!"
          << RESET << std::endl;
        _data = new T[n];
        _size = n;
      }
      else
      {
      
        _size = 0;
        _data = NULL;
        std::cout << GREEN << "Array of size " << _size << " was created!" << RESET << std::endl;
      }
    }
    
    Array(const Array& original) : _data(NULL), _size(0)
    {
      *this = original;
    }
    
    Array& operator=(const Array& original)
    {
      std::cout << CYAN << "Array copy assignment operator called!"
        << RESET << std::endl;
      if (this != &original)
      {
        delete[] _data;
        _size = original._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
          _data[i] = original._data[i];
      }
      return (*this);
    }
    
    ~Array()
    {
      if (_data)
        delete[] _data;
    }
    
    T& operator[](unsigned int index)
    {
      if (index >= _size)
        throw std::out_of_range("Index is out of bounds");
      return (_data[index]);
    }

    const T& operator[](unsigned int index) const
    {
      if (index >= _size)
        throw std::out_of_range("Index is out of bounds");
      return (_data[index]);
    }

    unsigned int  size() const
    {
      return (_size);
    }

    void  printData(unsigned int index)
    {
      if (index >= _size)
      {
        std::cout << RED << "\nError: index is out of range!" << RESET << std::endl;
        return ;
      }
      std::cout << _data[index] << " ";
    }

    void  setData(unsigned int index)
    {
      static int i;
      
      if (index >= _size)
      {
        std::cout << RED << "\nError: index is out of range!" << RESET << std::endl;
        return ;
      }
      _data[index] = i++;
    }
};
