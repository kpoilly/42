/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:45:53 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/29 18:59:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
};
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
};
Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
};

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
};

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
};

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
};

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
};

bool	Account::makeWithdrawal(int withdrawal)
{
		
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
};

int		Account::checkAmount(void) const
{
	return (_amount);
};

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
};

void	Account::_displayTimestamp(void)
{
	std::time_t timestamp = std::time(nullptr);
	struct tm *time = std::localtime(&timestamp);
	std::cout << "[" << time->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << time->tm_sec;
	std::cout << "] ";
	
	
};
