/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:03:52 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/10 08:21:51 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"

//int main() {
//	std::string	c = "e";
//	std::string d = "a";
	
//	std::string res1 = min(c, d);
//	std::cout << res1 << '\n';

//	int a = 3;
//	int b = 1;
	
//	int res2 = max(a, b);
//	std::cout << res2 << '\n';

//	char e = 'c';
//	char f = 'd';
	
//	swap(e, f);
//	std::cout << e << " " << f << '\n';

//	//Test g;
//	//Test h;
//	//Test res3 =  min(g, h);
	
//}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}