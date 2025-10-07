/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:02:56 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/06 10:05:58 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& original)
{
  (void)original;
}

Intern& Intern::operator=(const Intern& original)
{
  (void)original;
  return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
  std::cout << YELLOW << "Intern is trying to create AForm " << form
    << RESET << std::endl;
  int index = -1;
  std::string array[3] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm",
  };

  for (int i = 0; i < 3; i++)
  {
    if (array[i] == form)
    {
      index = i;
      break ;
    }
  }
  switch(index)
  {
    case 0:
      std::cout << GREEN << "Intern created AForm " << form << RESET << std::endl;
      return (new ShrubberyCreationForm(target));
    case 1:
      std::cout << GREEN << "Intern created AForm " << form << RESET << std::endl;
      return (new RobotomyRequestForm(target));
    case 2:
      std::cout << GREEN << "Intern created AForm " << form << RESET << std::endl;
      return (new PresidentialPardonForm(target));
    default: throw Intern::internException("No match to AForm " + form + "!");
  }
}
