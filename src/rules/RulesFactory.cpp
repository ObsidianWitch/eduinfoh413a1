#include "rules/Initialization/CWInitialization.hpp"
#include "rules/Initialization/RandomInitialization.hpp"
#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/BestImprovement.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "RulesFactory.hpp"

Initialization* RulesFactory::getInitialization(std::string initialization,
    Instance& instance)
{
    if (initialization == "cw") {
        return new CWInitialization(instance);
    }
    else if (initialization == "random") {
        return new RandomInitialization(instance);
    }
    
    exit(EXIT_FAILURE);
}

Improvement* RulesFactory::getPivotingRule(std::string pivotingRule,
    Instance& instance, Neighbourhood& n)
{
    if (pivotingRule == "first") {
        return new FirstImprovement(instance, n);
    }
    else if (pivotingRule == "best") {
        return new BestImprovement(instance, n);
    }
    
    exit(EXIT_FAILURE);
}

Neighbourhood* RulesFactory::getNeighbourhood(std::string neighbourhood,
    unsigned size)
{
    if (neighbourhood == "transpose") {
        return new Neighbourhood(size, Neighbourhood::TRANSPOSE);
    }
    else if (neighbourhood == "exchange") {
        return new Neighbourhood(size, Neighbourhood::EXCHANGE);
    }
    else if (neighbourhood == "insertion") {
        return new Neighbourhood(size, Neighbourhood::INSERTION);
    }
    
    exit(EXIT_FAILURE);
}
