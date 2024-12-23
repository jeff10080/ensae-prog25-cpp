//
// Created by adam0 on 04/10/2024.
//

#include <algorithm>
#include <limits>
#include "Option.h"

double Option::payoff(const double& ST) //Return the correct payoff based on option type
{
    switch(m_type)
    {
        case call:
            return std::max(ST - m_strike, 0.);
        case put:
            return std::max(m_strike - ST, 0.);
        default:
            return std::numeric_limits<double>::quiet_NaN();
    }

}

double Option::getMaturity() const {
    return m_maturity;
}
