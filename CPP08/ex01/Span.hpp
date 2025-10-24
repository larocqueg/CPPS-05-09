/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:29:46 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/21 21:43:07 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Span
{
  private:
    Span();
    unsigned int  _N;
    std::vector<int> _values;
  public:
    Span(unsigned int n);
    Span(const Span& original);
    Span& operator=(const Span& original);
    ~Span();
    void  addNumber(int n);
    void  addNumber(int begin, int end);
    void  printVector();
    int  shortestSpan();
    int  longestSpan();
};
