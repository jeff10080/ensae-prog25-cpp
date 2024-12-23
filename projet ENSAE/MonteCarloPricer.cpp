//
// Created by adam0 on 04/10/2024.
//

#include "MonteCarloPricer.h"
#include <cmath>

double MonteCarloPricer::operator()() {
    double payoffSum = 0.;
    double maturity = m_option->getMaturity();

    for(size_t i = 0; i < m_simulations; ++i)
    {
        double ST = m_model->simulatePrice(maturity, m_steps);
        double payoff = m_option->payoff(ST);

        payoffSum += payoff;
    }
    double r = m_model->getRiskFree();

    double discountFactor = std::exp(-r * maturity);
    return (payoffSum / (static_cast<double> (m_simulations))) * discountFactor;
}
