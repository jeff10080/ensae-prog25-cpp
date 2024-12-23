//
// Created by adam0 on 04/10/2024.
//

#ifndef PROJET_ENSAE_OPTION_H
#define PROJET_ENSAE_OPTION_H

enum OptionType{call, put}; //List of possible types for the option
//TODO : Add more possible type

class Option
{
private:
    double m_strike;
    double m_maturity;
    OptionType m_type;

public:
    Option(const double& K, const double& T, const OptionType& type) : m_strike(K), m_maturity(T), m_type(type){}
    ~Option() = default;

    double payoff(const double& ST);
    [[nodiscard]] double getMaturity() const;
};


#endif //PROJET_ENSAE_OPTION_H
