/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:04:18 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 11:04:18 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Bureaucrat;

class AForm
{
  private:
    const std::string   _name;
    const unsigned int  _signGrade;
    const unsigned int  _execGrade;
    bool                _signed;
    AForm();
  public:
    AForm(const std::string& name, unsigned int toSign, unsigned int toExec);
    AForm(const AForm& original);
    AForm& operator=(const AForm& original);
    virtual ~AForm();

    void                signAForm(const Bureaucrat& b);
    virtual void        execute(const Bureaucrat& b) const = 0;
    unsigned int        getSignGrade() const;
    unsigned int        getExecGrade() const;
    const std::string&  getName() const;
    bool                getSign() const;
  
  class gradeTooHighException : public std::exception
  {
    private:
      std::string _msg;
    public:
      gradeTooHighException() : _msg("AForm: grade is too high!") {}
      gradeTooHighException(const std::string& msg) : _msg(msg) {}
      virtual const char* what() const throw() { return _msg.c_str(); }
      virtual ~gradeTooHighException() throw() {}
  };

  class gradeTooLowException : public std::exception
  {
    private:
      std::string _msg;
    public:
      gradeTooLowException() : _msg("AForm: grade is too low!") {}
      gradeTooLowException(const std::string& msg) : _msg(msg) {}
      virtual const char* what() const throw() { return _msg.c_str(); }
      virtual ~gradeTooLowException() throw() {}
  };
  
  class formNotSignedException : public std::exception
  {
    private:
      std::string _msg;
    public:
      formNotSignedException() : _msg("AForm: grade is too low!") {}
      formNotSignedException(const std::string& msg) : _msg(msg) {}
      virtual const char* what() const throw() { return _msg.c_str(); }
      virtual ~formNotSignedException() throw() {}
  };

};

std::ostream& operator<<(std::ostream& os, const AForm& form);
