/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:26:43 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/14 18:26:54 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "identify.hpp"

int main(void)
{
  srand(time(NULL));

  std::cout << std::endl;

  Base  *random = generate();
  
  identify(random);
  delete (random);
  std::cout << std::endl;
  
  random = generate();
  identify(random);
  delete (random);
  std::cout << std::endl;
  
  random = generate();
  identify(random);
  delete(random);
  std::cout << std::endl;
  
  // A a;
  // B b;
  // C c;
  //
  // identify(a);
  //
  // std::cout << std::endl;
  //
  // identify(b);
  //
  // std::cout << std::endl;
  //
  // identify(c);
 
  return (0);
}
