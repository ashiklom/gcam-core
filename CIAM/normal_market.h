#ifndef _NORMAL_MARKET_H_
#define _NORMAL_MARKET_H_
#if defined(_MSC_VER_)
#pragma once
#endif

/*! 
* \file normal_market.h
* \ingroup CIAM
* \brief The NormalMarket class header file.
* \author Sonny Kim
* \date $Date$
* \version $Revision$
*/

#include "Market.h"

/*!
* \ingroup CIAM
* \brief A class which defines the normal supply-demand type market.
* \author Sonny Kim
*/

class NormalMarket: public Market {
public:
    NormalMarket( const std::string& goodNameIn, const std::string& regionNameIn, const int periodIn );
    virtual void derivedToDebugXML( std::ostream& out ) const;
    virtual std::string getType() const;
    virtual void setCompanionMarketPointer( Market* pointerIn );

    virtual void initPrice();
    virtual void setPrice( const double priceIn );
    virtual void setPriceFromLast( const double lastPrice );
    virtual double getPrice() const;

    virtual void addToDemand( const double demandIn );
    virtual double getDemand() const;

    virtual void nullSupply();
    virtual double getSupply() const;
    virtual double getSupplyForChecking() const;
    virtual void addToSupply( const double supplyIn );

    virtual bool shouldSolve() const;
    virtual bool shouldSolveNR() const;

private:
};

#endif // _NORMAL_MARKET_H_