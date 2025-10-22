/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:37:55 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/21 17:59:33 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
  int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  std::vector<int>vectorArr(arr, arr + sizeof(arr)/sizeof(arr[0]));

  std::cout << YELLOW << "\nLooping trought the vector untill it catches a invalid number\n"
    << RESET << std::endl;
  try
  {
    for  (int i = -5; i <= 6; i++)
    {
      std::vector<int>::iterator it = easyfind(vectorArr, i);
      std::cout << GREEN << "Found the passed value at position: "
        << std::distance(vectorArr.begin(), it) << RESET << std::endl;
    }

  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  
  std::cout << YELLOW << "\n\nGiving a invalid argument to the easyfind"
    << RESET << std::endl;
  try
  {
    std::vector<int>::iterator it = easyfind(vectorArr, -10);
    std::cout << GREEN << "Found the passed value at position: "
      << std::distance(vectorArr.begin(), it) << RESET << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
  return (0);
}
