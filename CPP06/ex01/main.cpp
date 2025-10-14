/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:57:59 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/14 14:58:23 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
  Data data;

  if (ac == 4)
  {
    std::string av1 = av[1];
    data.id = std::atoi(av1.c_str());

    std::string av2 = av[2];
    data.value = std::strtod(av2.c_str(), NULL);

    data.name = av[3];
  }
  else
  {
    data.id = 42;
    data.value = 3.14159;
    data.name = "Gabriel";
  }

  std::cout << CYAN << "\nOrigianl Data address: " << RESET
    << GREEN << &data << RESET << std::endl;
  
  std::cout << GREEN << "\nOrigianl Data content:" << RESET
    << "\nid: " << data.id
    << "\nvalue: " << data.value 
    << "\nname: " << data.name << std::endl;
  
  uintptr_t raw = Serializer::serialize(&data);
  std::cout << YELLOW << "\nSerializer (uintptr_t): " << raw << RESET << std::endl;

  Data  *deserialize = Serializer::deserialize(raw);

  if (deserialize == &data)
  {
    std::cout << CYAN << "\nDeserialized data address: "
      << RESET << GREEN << deserialize << RESET << std::endl;
    
    std::cout << GREEN << "\nDeserialized Data content:" << RESET
      << "\nid: " << deserialize->id
      << "\nvalue: " << deserialize->value
      << "\nname: " << deserialize->name  + "\n" << std::endl;
  }
  else
  {
    std::cout << "Error: deserialize pointer does not match!" << std::endl;
    return (1);
  }
  return (0);
}
