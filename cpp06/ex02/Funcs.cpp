/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:48:15 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/18 08:23:43 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"

Base*	generate() {
	srand(time(0));

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

void identify(Base& p) {
    try { // A Block
        A& a = dynamic_cast<A&>(p);
        std::cout << "ref is class A\n";
    }
	catch (const std::bad_cast&)
	{
        try { // B Block
            B& b = dynamic_cast<B&>(p);
            std::cout << "ref is class B\n";
        }
		catch (const std::bad_cast&)
		{
            try { // C Block
                C& c = dynamic_cast<C&>(p);
                std::cout << "ref is class C\n";
            }
			catch (const std::bad_cast&)
			{
                std::cout << "no known type\n";
            }
        }
    }
}
