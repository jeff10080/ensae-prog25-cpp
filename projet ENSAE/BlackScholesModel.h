//
// Created by adam0 on 04/10/2024.
//

#ifndef PROJET_ENSAE_BLACKSCHOLESMODEL_H
#define PROJET_ENSAE_BLACKSCHOLESMODEL_H


#include "Option.h"


class BlackScholesModel
{
private:
    double m_r; //Risk Free Rate
    double m_sigma; //Volatility
    double m_s0; //Initial price

public:
    BlackScholesModel(double r, double sigma, double s0) : m_r(r), m_sigma(sigma), m_s0(s0){}
    ~BlackScholesModel() = default;

    [[nodiscard]] double simulatePrice(const double T, const size_t steps) const; //Simulate the price using the Monte Carlo method for time T

    void simulateReplicationStrat(const double T, const size_t steps, const Option option, const double initialCash) const; //Simulate the price with a replication strategy using delta hedging

    [[nodiscard]] double getRiskFree() const;//Getter function for the risk free rate r, used by another class

    [[nodiscard]] double delta(const OptionType type, const double T, const double K) const; //Computes the delta of the option at strike price T and maturity T
};

#endif //PROJET_ENSAE_BLACKSCHOLESMODEL_H
