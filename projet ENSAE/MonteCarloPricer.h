//
// Created by adam0 on 04/10/2024.
//

#ifndef PROJET_ENSAE_MONTECARLOPRICER_H
#define PROJET_ENSAE_MONTECARLOPRICER_H

#include <memory>
#include <utility>
#include "BlackScholesModel.h"
#include "Option.h"

class MonteCarloPricer
{
private:
    //A MonteCarloPricer object does not take ownership of a model or an option thus it store shared_ptr,
    // the use of smart pointers allows for simple and efficient management of the object without the need for a non-default destructor
    std::shared_ptr<const BlackScholesModel> m_model;
    std::shared_ptr<const Option> m_option;
    size_t m_simulations; //Number of simulations to compute for the Monte-Carlo method
    size_t m_steps; //Number of steps in each simulation

public:
    MonteCarloPricer(std::shared_ptr<const BlackScholesModel> modelPtr, std::shared_ptr<const Option> optionPtr, size_t simulations, size_t steps) : m_model(std::move(modelPtr)), m_option(std::move(optionPtr)), m_simulations(simulations), m_steps(steps) {}
    ~MonteCarloPricer() = default;

    double operator() () const;//The operator() is the one to call in order to use a MonteCarloPricer object,
                         // it returns the average price of m_simulations simulation with m_steps steps for each
};

#endif //PROJET_ENSAE_MONTECARLOPRICER_H
