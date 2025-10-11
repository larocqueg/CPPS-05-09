/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:20:53 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/09 17:23:25 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cout << "Usage: ./Scalar \"argument\"" << std::endl;
    return (1);
  }
  try
  {
    std::string literal = av[1];
    ScalarConverter::convert(literal);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}
