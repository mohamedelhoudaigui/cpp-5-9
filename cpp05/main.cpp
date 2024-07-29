/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:28:10 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 09:47:43 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	a("simo", 1);
		Bureaucrat	b(a);
		Bureaucrat	c = a;
		
		std::cout << a << "\n";
		a.incrGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << "\n";
	}
	return (0);
}