/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:29:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/08 11:29:52 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& original);
    ScalarConverter& operator=(const ScalarConverter& original);
    ~ScalarConverter();
    static bool               typeChar(std::string& literal);
    static bool               typeInt(std::string& literal);
    static bool               typeFloat(std::string& literal);
    static bool               typeDouble(std::string& literal);
    static const std::string  getType(const std::string& literal);
  public:
    static void convert(std::string& literal);
}
