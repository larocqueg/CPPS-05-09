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
  return (NULL);
}

void  indentify(Base* p)
{
}

void  indentify(Base& p)
{
}
