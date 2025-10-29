/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:52:33 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/29 17:32:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& original)
{
  *this = original;
}

RPN& RPN::operator=(const RPN& original)
{
  (void)original;
}

RPN::~RPN()
{
}

static int  isDigit(std::string token)
{
  int i = 0;

  while (token[i] && token[i] >= '0' && token[i] <= '9')
    i++;
  if (i == 1 && !token[i])
    return (1);
  return (0);
}

void  RPN::parser(const std::string& str)
{
  if (str.empty())
    throw std::runtime_error("Invalid argument.");

  int         num = 0;
  int         sig = 0;
  std::string token;
  std::stringstream ss(str);

  while (ss >> token)
  {
    if (isDigit(token))
      numbers++;
    else
      throw std::runtime_error("Invalid argument");
    if (isSignal(token))
      sig++;
    else
      throw std::runtime_error("Invalid argument");
  }
  if (sig != num - 1)
    throw std::runtime_error("Invalid argument");
  return ;
}

void  doOp(const std::string& str)
{
  int                 res = 0;
  std::string         token;
  std::stack<int>     _nums;
  std::stack<std::string>    _sigs;
  std::stringstream   ss(str);

  while  (ss >> token)
  {
    if (isDigit(token))
      _nums.push_back(atoi(token));
    if (isSignal(token))
      _sigs.push_back(token);

  }
}
