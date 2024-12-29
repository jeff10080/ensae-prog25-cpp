//
// Created by adam0 on 04/10/2024.
//

#include <algorithm>
#include <limits>
#include "Option.h"

double Option::payoff(const double ST) const //Return the correct payoff based on option type
{
    switch(m_type) //We use the type to choose the correct way to compute the payoff, in case of an error, returns NaN
    {
        case call:
            return std::max(ST - m_strike, 0.);
        case put:
            return std::max(m_strike - ST, 0.);
        default:
            return std::numeric_limits<double>::quiet_NaN();
    }

}

double Option::getMaturity() const
{
    return m_maturity;
}
