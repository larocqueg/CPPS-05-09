/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequesForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:24:24 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:27 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequesForm.hpp"

RobotomyRequesForm::RobotomyRequesForm() : AForm("RobotomyRequesForm", 145, 137), _target("Default")
{
}

RobotomyRequesForm::RobotomyRequesForm(const std::string& target) : AForm("RobotomyRequesForm", 145, 137), _target(target)
{
}

RobotomyRequesForm& RobotomyRequesForm::operator=(const RobotomyRequesForm& original)
{
  if (this != &original)
  {
    AForm::operator=(original);
  }
  return (*this);
}

RobotomyRequesForm::~RobotomyRequesForm()
{
}

void  RobotomyRequesForm::execute(const Bureaucrat& b) const
{
  if (b.getGrade() > this->getExecGrade())
  {
    throw AForm::gradeTooLowException(
        "Bureaucrat " + b.getName() + " couldn't exeute " + this->getName() + " because grade is to low!"); 
  }
  if (this->getSign())
  {
  }
  else
  {
    std::cerr << RED << this->getName() << " is not signed!" << RESET << std::endl;
  }
}
