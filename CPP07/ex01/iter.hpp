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

#include <string>
#include <iostream>

template <typename I, typename F>

void  iter(I *array, const int size, F f)
{
  for (int i = 0; i < size; i++)
    f(array[i]);
}

template <typename I>

void  print_string(I& arg)
{
  std::cout << arg << std::endl;
}

