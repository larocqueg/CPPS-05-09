/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:59:59 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/11/05 14:59:21 by gde-la-r         ###   ########.fr       */
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

static void binaryInsertVec(std::vector<int>& vec, int value)
{
  std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), value);
  vec.insert(pos, value);
}

static void binaryInsertDeq(std::deque<int>& deq, int value)
{
  std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), value);
  deq.insert(pos, value);
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
  for (size_t i = 0; i < _numbersVec.size(); ++i)
  {
    if (i >= 10)
      break ;
    std::cout << _numbersVec[i] << " ";
  }
  std::cout << "[...]" << std::endl;
}

static std::vector<size_t> generateJacobsthalSequenceVec(size_t n)
{
  std::vector<size_t> seq;
  if (n == 0)
    return (seq);
  seq.push_back(1);
  if (n == 1)
    return (seq);
  size_t j_prev = 1;
  size_t j_curr = 3;
  while (j_curr <= n)
  {
    seq.push_back(j_curr);
    size_t tmp = j_curr;
    j_curr = j_curr + 2 * j_prev;
    j_prev = tmp;
  }
  for (size_t i = 1; i <= n; ++i)
  {
    bool exists = false;
    for (size_t j = 0; j < seq.size(); ++j)
    {
      if (seq[j] == i)
      {
        exists = true;
        break;
      }
    }
    if (!exists)
      seq.push_back(i);
  }
  return (seq);
}

static std::deque<size_t> generateJacobsthalSequenceDeq(size_t n)
{
  std::deque<size_t> seq;
  if (n == 0)
    return (seq);
  seq.push_back(1);
  if (n == 1)
    return (seq);
  size_t j_prev = 1;
  size_t j_curr = 3;
  while (j_curr <= n)
  {
    seq.push_back(j_curr);
    size_t tmp = j_curr;
    j_curr = j_curr + 2 * j_prev;
    j_prev = tmp;
  }
  for (size_t i = 1; i <= n; ++i)
  {
    bool exists = false;
    for (size_t j = 0; j < seq.size(); ++j)
    {
      if (seq[j] == i)
      {
        exists = true;
        break;
      }
    }
    if (!exists)
      seq.push_back(i);
  }
  return (seq);
}

static std::vector<int> fordJohnsonRecursiveVec(const std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return (arr);

    std::vector<std::pair<int,int> > pairs;
    int leftover = -1;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            int a = arr[i];
            int b = arr[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
            leftover = arr[i];
    }

    std::vector<int> chain;
    for (size_t i = 0; i < pairs.size(); ++i)
        binaryInsertVec(chain, pairs[i].second);

    std::vector<size_t> order = generateJacobsthalSequenceVec(pairs.size());
    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx = order[k] - 1;
        if (idx < pairs.size())
            binaryInsertVec(chain, pairs[idx].first);
    }

    if (leftover != -1)
        binaryInsertVec(chain, leftover);

    return (chain);
}

int PmergeMe::fordJohnsonVec()
{
  if (_numbersVec.size() <= 1)
    return (0);
  _numbersVec = fordJohnsonRecursiveVec(_numbersVec);
  return (0);
}

static std::deque<int> fordJohnsonRecursiveDeq(const std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return (arr);

    std::deque<std::pair<int,int> > pairs;
    int leftover = -1;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            int a = arr[i];
            int b = arr[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
            leftover = arr[i];
    }

    std::deque<int> chain;
    for (size_t i = 0; i < pairs.size(); ++i)
        binaryInsertDeq(chain, pairs[i].second);

    std::deque<size_t> order = generateJacobsthalSequenceDeq(pairs.size());
    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx = order[k] - 1;
        if (idx < pairs.size())
            binaryInsertDeq(chain, pairs[idx].first);
    }

    if (leftover != -1)
        binaryInsertDeq(chain, leftover);
    return (chain);
}

int PmergeMe::fordJohnsonDeq()
{
  if (_numbersDeq.size() <= 1)
    return (0);
  _numbersDeq = fordJohnsonRecursiveDeq(_numbersDeq);
  return (0);
}

int PmergeMe::sorting()
{
    if (_numbersVec.size() <= 1 || _numbersDeq.size() <= 1)
        throw std::runtime_error("Invalid argument, it needs to have 2 or more positive integers");

    double vecTime, deqTime;
    struct timespec start, end;

    std::cout << std::endl;
    std::cout << YELLOW << "Before: " << RESET;
    printNums();
    std::cout << std::endl;

    clock_gettime(CLOCK_MONOTONIC, &start);
    fordJohnsonVec();
    clock_gettime(CLOCK_MONOTONIC, &end);
    vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    clock_gettime(CLOCK_MONOTONIC, &start);
    fordJohnsonDeq();
    clock_gettime(CLOCK_MONOTONIC, &end);
    deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    std::cout << YELLOW << "After: " << RESET;
    printNums();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "\nTime to process range of " << _numbersVec.size()
      << " elements with std::vector : " << GREEN << vecTime << " µs" << RESET << std::endl;

    std::cout << "Time to process range of " << _numbersDeq.size()
              << " elements with std::deque : " << GREEN << deqTime << " µs" << RESET << std::endl;

    return (0);
}
