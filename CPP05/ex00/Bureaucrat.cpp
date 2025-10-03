/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:54:32 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/03 10:54:33 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string& name, int grade) : _name(name), _grade(grade)
{
  std::cout << "Bureaucrat " << this->_name << " Was created!";
}

Bureaucrat::Bureaucrat(const Bureaucrat& original)
{
  *this = original;
}

Bureaucrat::Bureaucrat& operator = (const Bureaucrat& original)
{
  if (*this != original)
  {
    this-> = new original;
  }
}

Bureaucrat::~Bureaucrat()
{

}
