/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:13:15 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 13:13:31 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <stdint.h>

class ShrubberyCreationForm : public AForm
{
  private:
    const std::string _target;
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& original);
    ~ShrubberyCreationForm();

    void  execute(const Bureaucrat& b) const;
    const std::string& getTarget() const;
};
