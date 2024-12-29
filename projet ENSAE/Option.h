//
// Created by adam0 on 04/10/2024.
//

#ifndef PROJET_ENSAE_OPTION_H
#define PROJET_ENSAE_OPTION_H

enum OptionType{call, put}; //Small enum of possible types for the option
//TODO : Add more possible type

class Option
{
private:
    double m_strike; //Strike price usually noted K
    double m_maturity; //Maturity of the option
    OptionType m_type; //Type of the option (European put or call for now)

public:
    Option(const double K, const double T, const OptionType type) : m_strike(K), m_maturity(T), m_type(type){}
    ~Option() = default;

    [[nodiscard]] double payoff(const double ST) const; //Compute the payoff of the option with the underlying price S at time T
    [[nodiscard]] double getMaturity() const; //Getter function for the maturity, used by another class
    [[nodiscard]] double getStrike() const; //Getter function for the strike price , used by another class
    [[nodiscard]] OptionType getType() const; //Getter function for the option type, used by another class
};


#endif //PROJET_ENSAE_OPTION_H
