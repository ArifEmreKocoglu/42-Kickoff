/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:51:28 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:29 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	setName( "" );
	setHealth( 100 );
	setEngPoint( 50 );
	setAtckDmg( 20 );
	cout << "ScavTrap default constructor called" << endl;
};

ScavTrap::ScavTrap( string _name )
{
	setName( _name );
	setHealth( 100 );
	setEngPoint( 50 );
	setAtckDmg( 20 );
	cout << "ScavTrap string constructor called" << endl;
};

ScavTrap::ScavTrap( const ScavTrap &cpy )
{
	cout << "ScavTrap copy constructor called" << endl;
	*this = cpy;
};

ScavTrap::~ScavTrap() { cout << "ScavTrap destructor called" << endl; };

void	ScavTrap::attack( const string &target )
{
	cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAtckDmg() << " points of damage!" << endl;
	cout << "Losed 1 energy point! " << endl;
	this->takeDamage( getAtckDmg() );
	engPoint -= 1;
}

ScavTrap&	ScavTrap::operator = ( const ScavTrap &obj )
{
	this->name = obj.name;
	this->atckDmg = obj.atckDmg;
	this->engPoint = obj.engPoint;
	this->health = obj.health;
	return ( *this );
}

void	ScavTrap::guardGate( void ) { cout << "ScavTrap in Gate keeper mode" << endl; }