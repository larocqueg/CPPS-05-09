/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:12:53 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 13:13:09 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
  private:
    const std::string _target;
    RobotomyRequestForm& operator=(const RobotomyRequestForm& original);
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& original);
    ~RobotomyRequestForm();

    void  execute(const Bureaucrat& b) const;
    const std::string& getTarget() const;
};
