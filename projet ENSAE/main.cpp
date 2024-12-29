#include <iostream>
#include <vector>
#include "MonteCarloPricer.h"
#include <memory>

int main()
{
    constexpr double maturity = 3./12.;
    constexpr size_t nSimulations = 1000;
    constexpr size_t nSteps = 1000;

    auto egCallPtr = std::make_shared<const Option>(110, maturity, call);
    auto egPutPtr = std::make_shared<const Option>(90, maturity, put);

    auto egModelPtr = std::make_shared<const BlackScholesModel>(0.05, 0.20, 100.);

    const MonteCarloPricer egCallPricer{egModelPtr, egCallPtr, nSimulations, nSteps};
    const MonteCarloPricer egPutPricer{egModelPtr, egPutPtr, nSimulations, nSteps};

    std::cout << "Call price : " << egCallPricer() << "\n";
    std::cout << "Put price : " << egPutPricer() << std::endl;

    return 0;
}
