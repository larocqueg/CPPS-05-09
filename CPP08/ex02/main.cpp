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


  MutantStack<int>testStack;

	for (int i = 2; i <= 10; i++)
    testStack.push(i * i);
  
  std::cout << "\n" << YELLOW << "Normal iteration (iterator):" << RESET << std::endl;
  for (MutantStack<int>::iterator it = testStack.begin(); it != testStack.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "\n" << YELLOW << "Constant iteration (const_iterator):"
    << RESET << std::endl;
  const MutantStack<int> const_testStack(testStack);
  
  for (MutantStack<int>::const_iterator it = const_testStack.begin(); it != const_testStack.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "\n" << GREEN << "Reverse iteration (reverse_iterator):"
    << RESET << std::endl;
  for (MutantStack<int>::reverse_iterator rit = testStack.rbegin(); rit != testStack.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << std::endl;

  std::cout << "\n" << GREEN << "Constant reverse iteration (const_reverse_iterator):"
    << RESET << std::endl;
  for (MutantStack<int>::const_reverse_iterator rit = const_testStack.rbegin(); rit != const_testStack.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << std::endl;

  std::cout << "\n" << YELLOW << "Testing pop and top:" << RESET << std::endl;
  std::cout << "Top before pop: " << testStack.top() << std::endl;
  testStack.pop();
  std::cout << "Top after pop:  " << testStack.top() << std::endl;

  std::cout << "\n" << CYAN << "Remaining elements:" << RESET << std::endl;
  for (MutantStack<int>::iterator it = testStack.begin(); it != testStack.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return (0);
}

