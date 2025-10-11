/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:57:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/10/11 18:03:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Serializer
{
  private:
    Serializer();
    Serializer(const Serializer& original);
    Serializer& operator=(const Serializer& original);
    ~Serializer();
  public:
    uintptr_t serialize(Data* ptr);
    Data*     deserialize(uintptr_t raw);
};
