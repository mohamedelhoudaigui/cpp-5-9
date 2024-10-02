/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:48:15 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/02 19:15:55 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"

Base*	generate() {
	srand(static_cast<unsigned int>(time(0)));

	int		rand_num = (rand() % 3) + 1;
	Base*	ret = NULL;

	switch (rand_num)
	{
		case 1:
			ret = new(A);
			break;
		case 2:
			ret = new(B);
			break;
		case 3:
			ret = new(C);
			break;
	}
	return ret;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "ptr is class A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "ptr is class B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "ptr is class C\n";
	else
		std::cout << "no known type\n";
}

void	identify(Base& p) {
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "ref is class A\n";
	else if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "ref is class B\n";
	else if (dynamic_cast<C*>(&p) != NULL)
		std::cout << "ref is class C\n";
	else
		std::cout << "no known type\n";
}
