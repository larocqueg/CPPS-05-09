/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:54:25 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/03 10:54:29 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

class Bureaucrat
{

  private:
    int               _grade;
    const std::string_name;
  public:
    Bureaucrat();
    Bureaucrat(std::string& name, int grade);
    Bureaucrat(const Bureaucrat& original);
    Bureaucrat& operator = (const Bureaucrat& original);
    ~Bureaucrat();

    //Getters
    int         getGrade() const;
    std::string getName() const;
};

