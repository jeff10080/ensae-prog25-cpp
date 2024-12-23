//
// Created by adam0 on 04/10/2024.
//

#ifndef PROJET_ENSAE_MONTECARLOPRICER_H
#define PROJET_ENSAE_MONTECARLOPRICER_H

#include <memory>
#include "BlackScholesModel.h"
#include "Option.h"

class MonteCarloPricer
{
private:
    std::shared_ptr<BlackScholesModel> m_model;
    std::shared_ptr<Option> m_option;
    size_t m_simulations;
    size_t m_steps;

public:
    MonteCarloPricer(std::shared_ptr<BlackScholesModel> modelPtr, std::shared_ptr<Option> optionPtr, size_t simulations, size_t steps) : m_model(modelPtr), m_option(optionPtr), m_simulations(simulations), m_steps(steps) {}
    ~MonteCarloPricer() = default;

    double operator() ();
};

#endif //PROJET_ENSAE_MONTECARLOPRICER_H
