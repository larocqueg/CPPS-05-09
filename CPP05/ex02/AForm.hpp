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
    ~AForm();

    void                signAForm(const Bureaucrat& b);
    unsigned int        getGrade() const;
    const std::string&   getName() const;
  
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

};
