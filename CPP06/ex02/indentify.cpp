/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentify.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:05:50 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/14 18:12:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "indentify.hpp"

Base  *generate(void)
{
  int i = rand() % 3;

  if (i == 0)
  {
    std::cout << GREEN << "Generating object A!" << RESET << std::endl;
    return (new A);
  }
  else if (i == 1)
  {
    std::cout << GREEN << "Generating object B!" << RESET << std::endl;
    return (new B);
  }
  else
  {
    std::cout << GREEN << "Generating object C!" << RESET << std::endl;
    return (new C);
  }
  std::cout << RED << "Couldn't generate a instance of A, B or C!" << RESET << std::endl;
  return (NULL);
}

void  indentify(Base* p)
{
  if (dynamic_cast<A*>(p))
  {
    std::cout << GREEN << "Object type is A!" << RESET << std::endl;
  }
  else if (dynamic_cast<B*>(p))
  {
    std::cout << GREEN << "Object type is B!" << RESET << std::endl;
  }
  else if (dynamic_cast<C*>(p))
  {
    std::cout << GREEN << "Object type is C!" << RESET << std::endl;
  }
  else
  {
    std::cout << RED << "Invalid object!" << RESET << std::endl;
  }
}

void  indentify(Base& p)
{
  try
  {
    (void)dynamic_cast<A&>(p);
    std::cout << GREEN << "Object type is A!" << RESET << std::endl;
    return ;
  }
  catch (...)
  {
  }
  
  try
  {
    (void)dynamic_cast<B&>(p);
    std::cout << GREEN << "Object type is B!" << RESET << std::endl;
    return ;
  }
  catch (...)
  {
  }
  
  try
  {
    (void)dynamic_cast<C&>(p);
    std::cout << GREEN << "Object type is C!" << RESET << std::endl;
    return ;
  }
  catch (...)
  {
  }
  std::cout << RED << "Invalid object!" << RESET << std::endl;
}
