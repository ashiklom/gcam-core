#ifndef _SOLVER_H_
#define _SOLVER_H_

class Marketplace;

/*! 
* \file Solver.h
* \ingroup CIAM
* \brief An abstract solver.
*
* This is the header file for the solver class.
*
* \author Josh Lurz
* \date $Date$
* \version $Revision$
*/

/*! 
* \ingroup CIAM
* \brief A class which defines an abstract solver.
* \author Josh Lurz
*/

class Solver {
public:
   Solver( Marketplace* marketplaceIn ):marketplace( marketplaceIn ){};
   virtual ~Solver(){};
   virtual bool solve( const int period ) = 0;
protected:
   Marketplace* marketplace;
};

#endif