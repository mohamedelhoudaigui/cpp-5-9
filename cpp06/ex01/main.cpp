/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:06:26 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/18 12:28:06 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main() {
	Data gg;
	std::string g;

	gg.field1 = 1;
	gg.field2 = 'a';
	gg.field3 = g;

	uintptr_t	ptr_ser = Serializer::serialize(&gg);
	Data*		ptr = &gg;
	Data*		ptr_des = Serializer::deserialize(ptr_ser);
	std::cout << ptr_des << std::endl << ptr <<std::endl;
}