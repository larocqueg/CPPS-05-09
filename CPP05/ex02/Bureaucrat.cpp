/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:05:43 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/03 19:05:44 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default")
{
  _grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name)
{
  std::cout << YELLOW << "Bureaucrat " << this->_name << " parameterized contructor called!"
    << RESET << std::endl;
	if (grade < 1)
		throw gradeTooHighException();
	if (grade > 150)
		throw gradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name)
{
	_grade = original._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
	if (this != &original)
		_grade = original._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw cannotIncrementException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw cannotDecrementException();
	_grade++;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}
