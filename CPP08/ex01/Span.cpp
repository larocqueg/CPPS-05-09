/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:51:40 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/22 14:54:52 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n) : _N(n)
{
}

Span::Span(const Span& original) : _N(original._N), _values(original._values)
{
}

Span& Span::operator=(const Span& original)
{
  if (this != &original)
  {
    this->_N = original._N;
    _values = original._values;
  }
  return (*this);
}

Span::~Span()
{
}

void  Span::addNumber(unsigned int n)
{
  if (_values.size() == _N)
  {
    throw (std::out_of_range("Couldn't add more numbers, values is already full"));
  }
  _values.push_back(n);
}

void  Span::addNumber(unsigned int begin, unsigned end)
{
  if (end - begin >= _N)
  {
    std::cout << end - begin << std::endl;
    std::cout << _N << std::endl;
    throw(std::out_of_range("Invalid range"));
  }
  for (unsigned i = 0; i <= end; i++)
  {
    _values.push_back(begin++);
  }
}

unsigned int  Span::shortestSpan()
{
  unsigned int min;
  unsigned int temp_min;

  if (_values.size() == 1)
  {
    throw (std::out_of_range("Error: there is only 1 number inside values"));
  }
  
  std::vector<unsigned int>sortVec = _values;
  std::sort(sortVec.begin(), sortVec.end());

  min = sortVec[1] - sortVec[0]; 

  for (size_t i = 1; i < sortVec.size(); i++)
  {
    if (i + 1 < sortVec.size())
      temp_min = static_cast<unsigned int>(sortVec[i + 1] - sortVec[i]);
    if (temp_min < min)
      min = temp_min;
  }
  return(min);
}

unsigned int  Span::longestSpan()
{
  if (_values.size() == 1)
  {
    throw (std::out_of_range("Error: there is only 1 number inside values"));
  }
  
  int min = *std::min_element(_values.begin(), _values.end());
  int max = *std::max_element(_values.begin(), _values.end());
  return (abs(max - min));
}

void  Span::printVector()
{
  for (size_t i = 0; i < _values.size(); i++)
  {
    std::cout << _values[i] << " ";
  }
  std::cout << std::endl;
}
