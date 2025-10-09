/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:26:34 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/09 16:36:38 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
  (void)original;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
  (void)original;
  return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static const std::string ScalarConverter::getType(const std::string& literal)
{
  std::string array[4] = {
    "Char",
    "Int",
    "Float",
    "Double",
  };

  for (int i = 0; i < 4; i++)
  {
    if (array[i] == literal)
      return (array[i]);
  }
  if (i >= 4)
  {
    std::cerr << RED << "No match for " << literal << RESET << std::endl;
    return ("Invalid");
  }
}

static bool ScalarConverter::typeChar(std::string literal)
{
}

static bool ScalarConverter::typeInt(std::string literal)
{
}

static bool ScalarConverter::typeFloat(std::string literal)
{
}

static bool ScalarConverter::typeDouble(std::string literal)
{
}

static void convert(std::string& literal)
{
}
