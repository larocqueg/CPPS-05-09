/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:59:59 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/11/05 13:08:43 by gde-la-r         ###   ########.fr       */
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

static void binaryInsert(std::vector<int>& vec, int value)
{
  std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), value);
  vec.insert(pos, value);
}

static bool comparePair(const std::pair<int,int>& a, const std::pair<int,int>& b)
{
    return (a.second < b.second);
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
  {
    std::cout << (_numbersVec[i]) << " ";
  }
  std::cout << std::endl;
}

int PmergeMe::fordJohnsonDeq()
{
  return (0);
}


int PmergeMe::fordJohnsonVec()
{
  if (_numbersVec.size() <= 1)
    return (0);

  int                               leftover = -1;
  std::vector<int>                  mainChain;
  std::vector<std::pair<int, int> > pairs;

  for (size_t i = 0; i < _numbersVec.size(); i += 2)
  {
    if (i + 1 < _numbersVec.size())
    {
      int a = _numbersVec[i];
      int b = _numbersVec[i + 1];
      if (a > b)
      {
        std::swap(a, b);
      }
      pairs.push_back(std::make_pair(a, b));
    }
    else
      leftover = _numbersVec[i];
  }

  std::sort(pairs.begin(), pairs.end(), comparePair);

  for (size_t i = 0; i < pairs.size(); ++i)
    mainChain.push_back(pairs[i].second);

  std::vector<size_t> insertionOrder;
  size_t j1 = 1, j2 = 3;

  insertionOrder.push_back(1);
  while (j2 <= pairs.size())
  {
    insertionOrder.push_back(j2);
    size_t tmp = j2;
    j2 = j2 + 2 * j1;
    j1 = tmp;
  }

  for (size_t i = 1; i <= pairs.size(); ++i)
  {
    bool exists = false;
    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
      if (insertionOrder[j] == i)
      {
        exists = true;
        break;
      }
    }
    if (!exists)
      insertionOrder.push_back(i);
  }

  for (size_t k = 0; k < insertionOrder.size(); ++k)
  {
    size_t idx = insertionOrder[k] - 1;
    if (idx < pairs.size())
      binaryInsert(mainChain, pairs[idx].first);
  }

  if (leftover != -1)
  {
    binaryInsert(mainChain, leftover);
  }

  _numbersVec = mainChain;

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
