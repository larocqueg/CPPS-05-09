/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:59:59 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/31 15:00:08 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& original)
{
  *this = original;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& original)
{
  if (this != &original)
  {
    this->_numbers = original._numbers;
  }
  return (*this);
}

PmergeMe::~PmergeMe()
{
}

int  PmergeMe::isDigit(char c)
{
  if (c >= '1' && c <= '9')
  {
    this->_numlen++;
    return (1);
  }
  return (0);
}

int  PmergeMe::isSpace(char c)
{
  if (_numlen >= 1)
    return (0);
  if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
    return (1);
  return (0);
}

int PmergeMe::parser(std::string arg)
{
  for (int i = 0; arg[i] != '\0'; i++)
  {
    if (!isDigit(arg[i]) && !isSpace(arg[i]))
      throw std::runtime_error("Invalid argument");
  }
  if (_numlen > 10)
    throw std::runtime_error("Invalid number, only positive integers are allowed");
  _numbers.push_back(std::atoi(arg.c_str()));
  return (0);
}

void  PmergeMe::printVector()
{
  for (unsigned long i  = 0; i < _numbers.size(); i++)
    std::cout << _numbers[i] << " ";
  std::cout << std::endl;
}
