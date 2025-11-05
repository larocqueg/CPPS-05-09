/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:27:23 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/31 14:29:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <deque>
#include <ctime>
#include <utility>
#include <algorithm>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define INT_MAX 2147483647

class PmergeMe
{
  private:
    std::deque<int>       _numbersDeq;
    std::vector<int>   _numbersVec;
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& original);
    PmergeMe& operator=(const PmergeMe& original);
    ~PmergeMe();
    int   isValid(char c);
    int   parser(std::string arg);
    int   sorting();
    int   fordJohnsonVec();
    int   fordJohnsonDeq();
    void  printNums();
};
