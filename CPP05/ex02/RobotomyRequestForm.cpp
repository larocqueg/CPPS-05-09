/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:24:24 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:27 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
  if (this != &original)
  {
    AForm::operator=(original);
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void  RobotomyRequestForm::execute(const Bureaucrat& b) const
{
  if (b.getGrade() > this->getExecGrade())
  {
    throw AForm::gradeTooLowException(
        "Bureaucrat " + b.getName() + " couldn't execute " + this->getName() + ", grade is to low!"); 
  }
  if (this->getSign())
  {
    if (rand() % 2 == 0)
    {
      std::cout << GREEN << "BZZZZZZZT VRRRRRRRRMMM GRRRRRRRRRRRRRR!" << this->_target << " has been robotomized!"
        << RESET << std::endl;
    }
    else
    {
      std::cout << RED << this->_target << " roboticization failed!" << RESET << std::endl;
    }
  }
  else
  {
    throw AForm::formNotSignedException(
        "Bureaucrat " + b.getName() + " couldn't execute " + this->getName() + ", Form not signed!");
  }
}
