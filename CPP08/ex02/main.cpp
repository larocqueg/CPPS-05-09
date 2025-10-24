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
  std::cout << YELLOW << "\nMutantStack tests" << RESET << std::endl;
  
  MutantStack<int> mstack;
  
  mstack.push(5);
  mstack.push(17);
  
  std::cout << mstack.top() << std::endl;
  
  mstack.pop();
  
  std::cout << mstack.size() << std::endl;
  
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  
  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << YELLOW << "\n\nList tests" << RESET << std::endl;
  
  std::list<int> mlist;
  
  mlist.push_back(5);
  mlist.push_back(17);
  
  std::cout << mlist.back() << std::endl;
  
  mlist.pop_back();
  
  std::cout << mlist.size() << std::endl;
  
  mlist.push_back(3);
  mlist.push_back(5);
  mlist.push_back(737);
  //[...]
  mlist.push_back(0);
  
  std::list<int>::iterator it1 = mlist.begin();
  std::list<int>::iterator ite1 = mlist.end();
  
  ++it1;
  --it1;
  while (it1 != ite1)
  {
    std::cout << *it1 << std::endl;
    ++it1;
  }
  std::list<int> s1(mlist);
  return (0);
}
