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
  std::cout << YELLOW << "PresidentialPardonForm default constructor called!"
    << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
  std::cout << YELLOW << "PresidentialPardonForm parameterized constructor called!"
    << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm& operator=(const PresidentialPardonForm& original)
{
  std::cout << YELLOW << "PresidentialPardonForm copy assingment operator called!"
    << RESET << std::endl;

  if (this != &original)
  {
    AForm::operator=(original);
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << RED << "PresidentialPardonForm destructor called!"
    << RESET << std::endl;
}

void  PresidentialPardonForm::execute(const Bureaucrat& b) const
{
  if (b.getGrade() > this->_getExecGrade())
  {
    throw AForm::gradeTooLowException(
        "Bureaucrat " + b.getName() + " couldn't exeute " + this->getName() + " because grade is to low!"
        << RESET << std::endl; 
  }
}
