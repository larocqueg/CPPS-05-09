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

  std::cout << YELLOW << "\nLooping trought int untill it catches a invalid number\n"
    << RESET << std::endl;
  try
  {
    for  (int i = -5; i <= 6; i++)
    {
      std::vector<int>::iterator it = easyfind(vectorArr, i);
      if (i < 0)
        std::cout << GREEN << "Found: " << i << " index: "
          << std::distance(vectorArr.begin(), it) << RESET << std::endl;
      else
        std::cout << GREEN << "Found:  " << i << " index: "
          << std::distance(vectorArr.begin(), it) << RESET << std::endl;
    }

  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  const int arr1[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  std::vector<int>vectorArr1(arr1, arr1 + sizeof(arr1)/sizeof(arr[0]));

  std::cout << YELLOW << "\nLooping trought const int vector untill it catches a invalid number\n"
    << RESET << std::endl;
  try
  {
    for (int i = -5; i <= 6; i++)
    {
      std::vector<int>::iterator it = easyfind(vectorArr1, i);
      if (i < 0)
        std::cout << GREEN << "Found: " << i << " index: "
          << std::distance(vectorArr1.begin(), it) << RESET << std::endl;
      else
        std::cout << GREEN << "Found:  " << i << " index: "
          << std::distance(vectorArr1.begin(), it) << RESET << std::endl;

    }
  }
  catch (const std::exception& e)
  {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  return (0);
}
