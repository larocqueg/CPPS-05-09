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

template <typename T>

class Array
{
  private:
    T*  _data;
    unsigned int  _size;

  public:
    Array() : _data(nullptr), _size(0)
    {
    }
    Array(unsigned int n) : _data(newT[n]()), _size(n)
    {
    }
    Array(const Array& original) : _data(nullptr), size(0)
    {
    }
    Array(const Array& original) : _data(nullptr), size(0)
    {
      *this = other;
    }
    ~Array()
    {
      delete[] _data;
    }
}
