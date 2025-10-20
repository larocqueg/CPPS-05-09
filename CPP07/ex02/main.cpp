/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:26:56 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/17 16:28:13 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
  std::cout << std::endl;
  
  Array<int> array1(25);
  Array<int> array2;
  unsigned int size;

  array2 = array1;
  size = array1.size();

  std::cout << YELLOW << "\nCreating empty array" << RESET << std::endl;
  Array<int> array3(0);

  std::cout << YELLOW << "\nPrinting array1 before changing _data values" << RESET << std::endl;
  for (unsigned int i = 0; i < size; i++)
  {
    array1.printData(i);
    array1.setData(i);
  }
  
  std::cout << YELLOW << "\n\nPrinting array2 before changing _data values" << RESET << std::endl;
  for (unsigned int i = 0; i < size; i++)
  {
    array2.printData(i);
    array2.setData(i);
  }
  
  std::cout << YELLOW << "\n\nPrinting array1 && array2 after changing _data values" << RESET << std::endl;
  std::cout << CYAN << "array1" << RESET << std::endl;
  for (unsigned int i = 0; i < size; i++)
  {
    array1.printData(i);
  }

  std::cout << std::endl;
  
  std::cout << CYAN << "array2" << RESET << std::endl;
  for (unsigned int i = 0; i < size; i++)
  {
    array2.printData(i);
  }

  std::cout << YELLOW << "\n\nPrinting array1 until index is out of bounds" << RESET << std::endl;
  std::cout << CYAN << "array1" << RESET << std::endl;
  for (unsigned int i = 0; i <= size; i++)
  {
    array1.printData(i);
  }
  return (0);
}
