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
    this->_numbersVec = original._numbersVec;
  }
  return (*this);
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::isValid(char c)
{
  if (c >= '0' && c <= '9')
  {
    return (1);
  }
  else if (c == ' ' || c == '\t')
  {
    return (1);
  }
  else
    return (0);
}

int PmergeMe::parser(std::string arg)
{
  double            num;
  std::stringstream ss(arg);
  
  while (ss >> arg)
  {
    for (int i = 0; arg[i] != '\0'; i++)
    {
      if (!isValid(arg[i]))
        throw std::runtime_error("Invalid argument");
    }
    num = std::strtod(arg.c_str(), NULL);
    if (num > INT_MAX || num < 0)
      throw std::runtime_error("Invalid number, all numbers must be positive integers");
    _numbersVec.push_back(num);
  }
  return (0);
}

void  PmergeMe::printVector()
{
  for (unsigned long i  = 0; i < _numbersVec.size(); i++)
    std::cout << static_cast<int>(_numbersVec[i]) << " ";
  std::cout << std::endl;
}

int sorting()
{
  return (0);
}
