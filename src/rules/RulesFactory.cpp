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

Neighbourhood** RulesFactory::getVNDNeighbourhood(std::string neighbourhood,
    unsigned size)
{
    Neighbourhood** n = new Neighbourhood*[3];
    Neighbourhood* nt = new Neighbourhood(size, Neighbourhood::TRANSPOSE);
    Neighbourhood* ne = new Neighbourhood(size, Neighbourhood::EXCHANGE);
    Neighbourhood* ni = new Neighbourhood(size, Neighbourhood::INSERTION);
    
    if (neighbourhood == "tei") {
        n[0] = nt; n[1] = ne; n[2] = ni;
        return n;
    }
    else if (neighbourhood == "tie") {
        n[0] = nt; n[1] = ni; n[2] = ne;
        return n;
    }
    
    exit(EXIT_FAILURE);
}
