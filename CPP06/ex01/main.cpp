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

int main(void)
{
  Data data;

  data.id = 42;
  data.value = 3.14159;
  data.name = "Gabriel";

  std::cout << "Origianl Data address: " << &data << std::endl;
  std::cout << "Origianl Data content:"
    << "\nid: " << data.id
    << "\nvalue: " << data.value 
    << "\nname: " << data.name << std::endl;
  
  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "\nSerializer (uintptr_t): " << raw << std::endl;

  Data  *deserialize = Serializer::deserialize(raw);

  if (deserialize == &data)
  {
    std::cout << "\nDeserialized data address: " << deserialize << std::endl;
    
    std::cout << "Origianl Data content: "
      << "\nid: " << deserialize->id
      << "\nvalue: " << deserialize->value
      << "\nname: " << deserialize->name << std::endl;
  }
  else
  {
    std::cout << "Error: deserialize pointer does not match!" << std::endl;
    return (1);
  }
  return (0);
}
