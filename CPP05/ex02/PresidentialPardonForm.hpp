/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:13:15 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/05 13:13:31 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
    const std::string _target;
    PresidentialPardonForm& operator=(const PresidentialPardonForm& original);
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& original);
    ~PresidentialPardonForm();

    void  execute(const Bureaucrat& b) const;
    const std::string& getTarget() const;
};
