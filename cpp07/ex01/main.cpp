/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:01:33 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/25 23:01:33 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "iter.hpp"

// void print_char(char c)
// {
// 	std::cout << c;
// }

// void toUpper(char *str)
// {
// 	while (str && *str)
// 		print_char(std::toupper(*str++));
// 	std::cout << std::endl;
// }

// void square(int nb)
// {
// 	std::cout << "Result of the square root for " << nb << " is " << nb * nb << std::endl;
// }

// int main(void)
// {
// 	int root[] = {2, 4, 6, 9};

// 	::iter(root, 4, square);

// 	char *s = (char *)"coucou";

// 	::iter(&s, 1, toUpper);
// }

#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}