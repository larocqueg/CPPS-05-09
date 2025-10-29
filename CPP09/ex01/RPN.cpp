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
  return (*this);
}

RPN::~RPN()
{
}

static int  isSpace(char c)
{
  if (c == ' ')
    return (1);
  return (0);
}

static int  isDigit(std::string token)
{
  int i = 0;

  while (token[i] && token[i] >= '0' && token[i] <= '9')
    i++;
  if (i == 1 && (isSpace(token[i]) || token[i] == '\0'))
    return (1);
  return (0);
}

static int  isSignal(std::string token)
{
  int i = 0;

  while (token[i] && (token[i] == '+' || token[i] == '-' || token[i] == '*' || token[i] == '/'))
    i++;
  if (i == 1 && (isSpace(token[i]) || token[i] == '\0'))
    return (1);
  return (0);
}

void  RPN::parser(const std::string& str)
{
  if (str.empty())
    throw std::runtime_error("Invalid argument.");

  int               nums = 0;
  int               sig = 0;
  std::string       token;
  std::stringstream ss(str);

  while (ss >> token)
  {
    if (isDigit(token))
      nums++;
    else if (isSignal(token))
      sig++;
    else
      throw std::runtime_error("Invalid argument");
  }
  if (sig != nums - 1)
    throw std::runtime_error("Invalid argument");
  return ;
}

void RPN::doOp(const std::string& str)
{
  std::stack<int> st;
  std::string token;
  std::stringstream ss(str);
  int a, b, res;

  while (ss >> token)
  {
    if (isDigit(token))
    {
      st.push(std::atoi(token.c_str()));
    }
    else if (isSignal(token))
    {
      if (st.size() < 2)
        throw std::runtime_error("Not enough operands before operator");

      b = st.top(); st.pop();
      a = st.top(); st.pop();
      res = 0;

      if (token == "+")
      {
        res = a + b;
      }
      else if (token == "-")
      {
        res = a - b;
      }
      else if (token == "*")
      {
        res = a * b;
      }
      else if (token == "/")
      {
        if (b == 0)
          throw std::runtime_error("Division by zero");
        res = a / b;
      }

      st.push(res);
    }
    else
      throw std::runtime_error("Invalid token");
  }

  if (st.size() != 1)
    throw std::runtime_error("Malformed RPN expression");

  std::cout << st.top() << std::endl;
}
