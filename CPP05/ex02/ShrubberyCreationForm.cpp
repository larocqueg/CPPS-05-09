/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:24:24 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:27 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
  if (this != &original)
  {
    AForm::operator=(original);
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void  ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
  if (b.getGrade() > this->getExecGrade())
  {
    throw AForm::gradeTooLowException(
        "Bureaucrat " + b.getName() + " couldn't exeute " + this->getName() + " because grade is to low!"); 
  }
  if (this->getSign())
  {
    std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox."
      << RESET << std::endl;
  }
  else
  {
    std::cerr << RED << this->getName() << " is not signed!" << RESET << std::endl;
  }
}
