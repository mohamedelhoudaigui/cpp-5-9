/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:28:10 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 10:34:09 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	a("simo", 1);
	Bureaucrat	b(a);
	Bureaucrat	c = a;
	Bureaucrat	d("yassine", 150);
	std::cout << a << "\n";
	std::cout << "----------------------\n";
	try
	{
		a.incrGrade();	
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";		
	}
	try
	{
		d.decrGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		Bureaucrat f("test", 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}