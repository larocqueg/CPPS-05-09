/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:03:30 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/22 18:04:18 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <iostream>
#include <list>

int main()
{
  std::list<int> mstack;

  mstack.push_back(5);
  mstack.push_back(17);
  std::cout << mstack.back() << std::endl;

  mstack.pop_back();
  std::cout << mstack.size() << std::endl;

  mstack.push_back(3);
  mstack.push_back(5);
  mstack.push_back(737);
  mstack.push_back(0);

  std::list<int>::iterator it = mstack.begin();
  std::list<int>::iterator ite = mstack.end();

  ++it;
  --it;

  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::list<int> s(mstack);
  return (0);
}

