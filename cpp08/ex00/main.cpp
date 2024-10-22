/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:25:29 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/22 19:02:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int main() {
	std::vector<int> gg;
	gg.push_back(4);
	gg.push_back(3);
	gg.push_back(2);
	gg.push_back(1);
	std::vector<int>::iterator it;
	it = easyfind(gg, 3);
	std::cout << *it << '\n';
	it = easyfind(gg, 9);
	std::cout << *it << '\n';
}