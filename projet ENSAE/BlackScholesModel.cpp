//
// Created by adam0 on 04/10/2024.
//

#include <random>
#include <iostream>
#include "BlackScholesModel.h"

double normCDF(double x)//Returns CDF of N(0,1) at x
{
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}

double BlackScholesModel::simulatePrice(const double T, const size_t steps) const
{
    static std::random_device rd; //Setup pseudo-random number generator for the Monte-Carlo method
    static std::mt19937 gen(rd());
    static std::normal_distribution<> d(0., 1.);

    const double dt = T / static_cast<double>(steps);
    double St = m_s0;

    for (size_t i = 0; i < steps; ++i) //Euler method for the integration of the Black-Scholes PDE
    {
        double Z = d(gen);
        St = St * std::exp((m_r - 0.5 * m_sigma * m_sigma) * dt + m_sigma * sqrt(dt) * Z);
    }

    return St;
}

double BlackScholesModel::getRiskFree() const {
    return m_r;
}

double BlackScholesModel::delta(const OptionType type, double T, const double K) const {
    double d = (log(m_s0 / K) + (m_r + 0.5 * m_sigma * m_sigma) * T) / (m_sigma * sqrt(T));
    switch(type) //Based on the correct option type we return the appropriate Delta
    {
        case call:
            return normCDF(d);
        case put:
            return normCDF(d) - 1;
        default:
            return std::numeric_limits<double>::quiet_NaN();

    }
}

void BlackScholesModel::simulateReplicationStrat(const double T, const size_t steps, const double K,
                                                   const double initialCash, const OptionType type) const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::normal_distribution<> d(0., 1.);

    double dt = T / steps;
    double cash = initialCash;
    double St = m_s0;  //Underlying initial price
    double deltaOld = 0.0;
    double portfolioValue = 0.0;

    for (int i = 0; i < steps; i++)
    {
        double deltaNew = delta(type, T - i * dt, K); //Refresh the delta

        double dS = St * (deltaNew - deltaOld);  // Quanitity to buy/sell to hedge the position
        cash -= dS;  //Update the cash

        double Z = d(gen);  //Updating the price of the underlying asset to continue the simulation
        St = St * exp((m_r - 0.5 * m_sigma * m_sigma) * dt + m_sigma * sqrt(dt) * Z);

        deltaOld = deltaNew;
        portfolioValue = deltaNew * St + cash;

        std::cout << "Step: " << i << " - Delta: " << deltaNew << " - Cash: " << cash << " - Portfolio value: " << portfolioValue << "\n";
    }

    std::cout << std::flush;//We make sure to flush the buffer in case the caller's program crashes
}
