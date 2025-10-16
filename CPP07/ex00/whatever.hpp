/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:05:20 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/15 17:22:50 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>

void  swap(T  &t1, T  &t2)
{
  T temp = t1;
  t1 = t2;
  t2 = temp;
}

template <typename T>

T const  &min(T  &t1, T  &t2)
{
  if (t1 < t2)
    return (t1);
  return (t2);
}

template <typename T>

T const &max(T  &t1, T  &t2)
{
  if (t1 > t2)
    return (t1);
  return (t2);
}
