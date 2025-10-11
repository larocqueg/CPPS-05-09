/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:26:34 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/11 11:45:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
	(void)original;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& original)
{
	(void)original;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static int	getNumType(const std::string& literal)
{
	size_t	checker;

	checker = literal.find('f');
	if (checker != std::string::npos)
		return (ScalarConverter::FLOAT);
	checker = literal.find('.');
	if (checker != std::string::npos)
		return (ScalarConverter::DOUBLE);
	return (ScalarConverter::INT);
}

static int	getType(const std::string& literal)
{
	size_t	checker;
	int		i;

	if (literal.empty())
		return (ScalarConverter::CHAR);
	if (literal.length() == 1 && isprint(literal[0]))
		return (ScalarConverter::CHAR);
	if (literal == "nan" || literal == "nanf" || literal == "+inf"
      || literal == "+inff" || literal == "-inf" || literal == "-inff")
		return (ScalarConverter::SPECIAL);

	checker = literal.find('.');
	if (checker != std::string::npos)
	{
		if (literal.find_first_of('.') != literal.find_last_of('.')
			|| literal.length() == literal.find_first_of('.') + 1
			|| literal[0] == '.')
			return (ScalarConverter::INVALID);
	}

	checker = literal.find('f');
	if (checker != std::string::npos)
	{
		if (literal.find_first_of('f') != literal.find_last_of('f')
			|| literal[literal.length() - 1] != 'f')
			return (ScalarConverter::INVALID);
	}

	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (literal[i])
	{
		if ((literal[i] < '0' || literal[i] > '9') && literal[i] != '.' && literal[i] != 'f')
			return (ScalarConverter::INVALID);
		i++;
	}
	return (getNumType(literal));
}

void	typeChar(std::string& literal)
{
	char	c;

	c = literal[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void typeSpecial(std::string &parameter)
{
  if (parameter == "nan" || parameter == "nanf")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  }
  else if (parameter == "+inf" || parameter == "+inff")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  }
  else if (parameter == "-inf" || parameter == "-inff")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  }
}

void	typeNum(std::string& literal)
{
	double	num;

	num = std::atof(literal.c_str());
	if (num >= 0 && num <= 127)
	{
		char	c = static_cast<char>(num);

		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Not displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;

	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;

	if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
		std::cout << "double: Impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void	ScalarConverter::convert(std::string& literal)
{
	int	type = getType(literal);

	if (type == ScalarConverter::CHAR)
		typeChar(literal);
	else if (type == ScalarConverter::SPECIAL)
		typeSpecial(literal);
	else if (type == ScalarConverter::INT || type == ScalarConverter::FLOAT
      || type == ScalarConverter::DOUBLE)
		typeNum(literal);
	else
		std::cerr << "Invalid literal" << std::endl;
}
