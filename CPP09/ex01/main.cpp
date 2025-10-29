/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:27:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/29 19:31:58 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cerr << RED << "" << RESET << std::endl;
    return (1);
  }
  
  try 
  {
    RPN rpn;
    rpn.parser(av[1]);
    rpn.doOp(av[1]);
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  return (0);
}
