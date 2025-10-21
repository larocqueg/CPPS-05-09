/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:23:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/21 17:37:52 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

template <typename T>

typename T::iterator easyfind(T& arr, int n)
{
  typename T::iterator it = std::find(arr.begin(), arr.end(), n);
  if (it != arr.end())
    return (it);
  throw std::logic_error("Couldn't find any occurance of the given value");
}

template <typename T>

typename T::const_iterator easyfind(const T& arr, int n)
{
  typename T::const_iterator it = std::find(arr.begin(), arr.end(), n);
  if (it != arr.end())
    return (it);
  throw std::logic_error("Couldn't find any occurance of te given value");
}
