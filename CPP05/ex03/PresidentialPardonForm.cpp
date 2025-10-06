/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:24:24 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:27 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
  if (this != &original)
  {
    AForm::operator=(original);
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void  PresidentialPardonForm::execute(const Bureaucrat& b) const
{
  if (b.getGrade() > this->getExecGrade())
  {
    throw AForm::gradeTooLowException(
        "Bureaucrat " + b.getName() + " couldn't exceute " + this->getName() + ", grade is to low!"); 
  }
  if (this->getSign() && b.getGrade() <= this->getExecGrade())
  {
    std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox."
      << RESET << std::endl;
  }
  else
  {
    throw AForm::formNotSignedException(
        "Bureaucrat " + b.getName() + " couldn't execute " + this->getName() + ", Form is not signed!");
  }
}
