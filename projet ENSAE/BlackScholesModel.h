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

    double simulatePrice(const double& T, const size_t & steps) const;

    double getRiskFree() const;

    double delta(OptionType type, double T, double K) const;
};

#endif //PROJET_ENSAE_BLACKSCHOLESMODEL_H
