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
#include <deque>

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

template <typename T>

class MutantStack : public std::stack<T>
{
  public:
    //taking deque functions to use in MutantStack
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    MutantStack<T>() : std::stack<T>()
    {
    }
    
    MutantStack<T>(const MutantStack<T>& original) : std::stack<T>(original)
    {
    }
    
    MutantStack &operator=(const MutantStack<T>& original)
    {
        if (this != &original)
            std::stack<T>::operator=(original);
        return *this;
    }

    ~MutantStack<T>()
    {
    }

    iterator begin()
    {
      return (this->c.begin());
    }
    iterator end()
    {
      return (this->c.end());
    }

    const_iterator begin() const
    {
      return (this->c.begin());
    }
    const_iterator end() const
    {
      return (this->c.end());
    }

    reverse_iterator rbegin()
    {
      return (this->c.rbegin());
    }
    reverse_iterator rend()
    {
      return (this->c.rend());
    }

    const_reverse_iterator rbegin() const
    {
      return (this->c.rbegin());
    }
    const_reverse_iterator rend() const
    {
      return (this->c.rend());
    }
};
