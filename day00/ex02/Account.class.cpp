#include "Account.class.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl;
}

Account::Account(int initial_deposit)
: _accountIndex(Account::_nbAccounts)
, _amount(initial_deposit)
, _nbDeposits(0)
, _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";created" << std::endl;
}

Account::~Account(void)
{
    _nbAccounts--;
    _totalAmount -= _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _totalAmount += deposit;
    _totalNbDeposits++;

    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << p_amount
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits
    << std::endl;
}

bool Account::makeWithdrawal(int withdrawals)
{
    _displayTimestamp();
    if (withdrawals > _amount)
    {
        std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:refused"
        << std::endl;

        return false;
    }

    _totalAmount -= withdrawals;
    _totalNbWithdrawals++;

    int p_amount = _amount;
    _amount -= withdrawals;
    _nbWithdrawals++;

    std::cout << "index:" << _accountIndex
    << ";p_amount:" << p_amount
    << ";withdrawal:" << withdrawals
    << ";amount:" << _amount
    << ";nb_withdrawals:" << _nbWithdrawals
    << std::endl;

    return true;
}

int Account::checkAmount(void) const
{
    _nbChecks++;
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

void Account::_displayTimestamp( void )
{
    std::cout << "[20150406_153629] ";
}