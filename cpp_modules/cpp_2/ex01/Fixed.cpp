/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:36:29 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/19 13:36:30 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nbr = 8;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
};

Fixed::Fixed( const Fixed& obj )
{
	cout << "Copy constructor called" << endl;
	*this = obj;
};

Fixed::Fixed( const int _fx_nbr )
{
	cout << "Int constructor called" << endl;
	fx_nbr = _fx_nbr << nbr;
};

Fixed::Fixed( const float _fx_nbr )
{
	cout << "Float constructor called" << endl;
	fx_nbr = _fx_nbr >> nbr;
};

int		Fixed::getRawBits( void ) const
{
	return ( fx_nbr );
}

void	Fixed::setRawBits( int const raw )
{
	fx_nbr = raw;
}

float	Fixed::toFloat( void ) const
{
	return ( fx_nbr << nbr );
}

int		Fixed::toInt( void ) const
{
	return ( fx_nbr >> nbr);
}

Fixed&	Fixed::operator = ( const Fixed &obj )
{
	cout << "Copy assigment operator called" << endl;
	return ( *this );
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
};

ostream& Fixed::operator << ( ostream& out, const Fixed& obj )
{
	out << obj.toInt();
	return ( out );
}