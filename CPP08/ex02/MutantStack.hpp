/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:57:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/22 16:57:54 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

template <typename T>

class MutantStack : public std::stack<T>
{
  public:
    MutantStack<T>() : std::stack<T>
    {
    }
    
    MutantStack<T>(const MutantStack<T>& original) : std::stack<T>(original)
    {
    }
    
    MutantStack<T>& MutantStack<T>::operator(const MutantStack<T>& original)
    {
      if (this != &original)
      {
        std::stack<T>operator=(original);
      }
      retur (*this);
    }

    ~MutantStack<T>()
    {
    }

}
