/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:48:57 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/16 12:49:27 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

template <typename I, typename F>
void iter(I *array, const int size, F f)
{
  for (int i = 0; i < size; i++)
    f(array[i]);
}

template <typename I>
void print_string(const I& arg)
{
  std::cout << arg << " ";
}

template <typename I>
void print_int(const I& arg)
{
  std::cout << arg << " ";
}

template <typename I>
void increment_int(I& arg)
{
  arg++;
}

template <typename I>
void increment_string(I& arg)
{
  std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
}

template <typename I>
void  repeat_ascii(I& arg)
{
  int repeat;

  repeat = 0;
  for (std::string::size_type i = 0; i < arg.length(); i++)
  {
    if (arg[i] >= 'A' && arg[i] <= 'Z')
    {
      repeat = arg[i] - 'A' + 1;
    }
    else if (arg[i] >= 'a' && arg[i] <= 'z')
    {
      repeat = arg[i] - 'a' + 1;
    }
    else
    {
      repeat = 0;
    }
    if (repeat != 0)
    {
      for (int j = 0; j < repeat; j++)
      {
        std::cout << arg[i];
      }
    }
    else
      std::cout << arg[i];
  }
  std::cout << " ";
}
