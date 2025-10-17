/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:55:59 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/16 13:01:37 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
  std::cout << YELLOW << "\nPrinting int array before incrementing" << RESET << std::endl;
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  iter(array, 10, print_int<const int>);
  iter(array, 10, increment_int<int>);

  std::cout << YELLOW << "\n\nPrinting int array after incrementing" << RESET << std::endl;
  iter(array, 10, print_int<const int>);


  std::cout << YELLOW << "\n\nPrinting std::string array before incrementing" << RESET << std::endl;
  std::string array2[] = {"Hello", "World", "42"};
  iter(array2, 3, print_string<const std::string>);
  iter(array2, 3, increment_string<std::string>);

  std::cout << YELLOW << "\n\nPrinting std::string array after incrementing" << RESET << std::endl;
  iter(array2, 3, print_string<const std::string>);
  
  std::cout << YELLOW << "\n\nPrinting std::stirng array with repeat ascii" << RESET << std::endl;
  std::string array3[] = {"abc", "def", "ghi", "123"};
  iter(array3, 4, repeat_ascii<const std::string>);
  std::cout << std::endl;

  return (0);
}
