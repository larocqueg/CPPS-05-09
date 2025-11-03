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
  return ((c >= '0' && c <= '9') || c == ' ' || c == '\t');
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
        throw std::runtime_error("Invalid argument, all arguments must be positive integers");
    }
    num = std::strtod(arg.c_str(), NULL);
    if (num > INT_MAX || num < 0)
      throw std::runtime_error("Invalid argument, all arguments must be positive integers");
    
    _numbersVec.push_back(static_cast<int>(num));
    _numbersDeq.push_back(static_cast<int>(num));
  }
  return (0);
}

void  PmergeMe::printNums()
{
  for (unsigned long i  = 0; i < _numbersVec.size(); i++)
    std::cout << (_numbersDeq[i]) << " ";
  std::cout << std::endl;
}

int PmergeMe::fordJohnsonDeq()
{
  return (0);
}


int PmergeMe::fordJohnsonVec()
{
  return (0);
}


int PmergeMe::sorting()
{
  if (_numbersDeq.size() <= 1 || _numbersVec.size() <= 1)
    throw std::runtime_error("Invlid argument, it needs to have 2 or more numbers");
  
  std::cout << std::endl; 
  std::cout << YELLOW << "Before: " << RESET;
  printNums();
  std::cout << std::endl;

  clock_t vecStart = clock();
  fordJohnsonVec();
  clock_t vecEnd = clock();


  clock_t deqStart = clock();
  fordJohnsonDeq();
  clock_t deqEnd = clock();
  
  std::cout << YELLOW << "After: " << RESET;
  printNums();
  std::cout << std::endl;
  
  double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1e6;
  double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1e6;

  std::cout << "\nTime to process range of " << _numbersVec.size()
    << " elements with std::vector : " GREEN << vecTime << "us" << RESET << std::endl;
  
  std::cout << "\nTime to process range of " << _numbersDeq.size()
    << " elements with std::deque : " << GREEN << deqTime << "us" << RESET << std::endl;
  
  return (0);
}
