/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:23:14 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/22 18:48:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void	incr(int& value)
{
	value ++;
}

int main() {
	int arr[] = {1, 2, 3, 4};
	int size = 4;
	for (int i = 0 ; i < 4; i++)
	{
		std::cout << arr[i] << '\n';
	}

	iter(arr, size, incr);
	std::cout << "------------------\n";
	for (int i = 0 ; i < 4; i++)
	{
		std::cout << arr[i] << '\n';
	}
	
}