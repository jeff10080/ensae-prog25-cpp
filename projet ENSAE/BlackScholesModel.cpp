//
// Created by adam0 on 04/10/2024.
//

#include <random>
#include "BlackScholesModel.h"

double normCDF(double x)
{
    return 0.5 * std::erfc(-x * M_SQRT1_2);  //CDF of N(0,1)
}

double BlackScholesModel::simulatePrice(const double& T, const size_t& steps) const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::normal_distribution<> d(0., 1.);

    const double dt = T / static_cast<double>(steps);
    double St = m_s0;

    for (size_t i = 0; i < steps; ++i)
    {
        double Z = d(gen);
        St *= St * std::exp((m_r - 0.5 * m_sigma * m_sigma) * dt + m_sigma * sqrt(dt) * Z);
    }

    return St;
}

double BlackScholesModel::getRiskFree() const {
    return m_r;
}

double BlackScholesModel::delta(OptionType type, double T, double K) const {
    double d = (log(m_s0 / K) + (m_r + 0.5 * m_sigma * m_sigma) * T) / (m_sigma * sqrt(T));
    switch(type)
    {
        case call:
            return normCDF(d);
        case put:
            return normCDF(d) - 1;
        default:
            return std::numeric_limits<double>::quiet_NaN();

    }
}
