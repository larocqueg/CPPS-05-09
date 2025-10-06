/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:58:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/06 10:02:51 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
  private:
    Intern(const Intern& original);
    Intern& operator=(const Intern& original);
  public:
    Intern();
    ~Intern();
    AForm *makeForm(const std::string from, const std::string target);

  class internException : public std::exception
  {
    private:
      std::string _msg;
    public:
      internException() : _msg("AForm: grade is too high!") {}
      internException(const std::string& msg) : _msg(msg) {}
      virtual const char* what() const throw() { return _msg.c_str(); }
      virtual ~internException() throw() {}
  };
};
