#ifndef _BATCH_RUNNER_H_
#define _BATCH_RUNNER_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*! 
* \file batch_runner.h
* \ingroup Objects
* \brief The BatchRunner class header file.
* \author Josh Lurz
* \date $Date$
* \version $Revision$
*/

#include <string>
#include <map>
#include <vector>
#include <list>
#include <memory>
#include <xercesc/dom/DOMNode.hpp>
#include "containers/include/iscenario_runner.h"
#include "util/base/include/iparsable.h"
class Timer;

/*! 
* \ingroup Objects
* \brief This class defines a batch scenario runner. The batch runner reads in set of input files
* and runs scenarios based on permutations of these files. More documentation.
* \author Josh Lurz
*/
class BatchRunner: public IScenarioRunner, IParsable {
	friend class ScenarioRunnerFactory;
public:
    virtual ~BatchRunner();
    virtual bool setupScenario( Timer& aTimer, const std::string aName = "", const std::list<std::string> aScenComponents = std::list<std::string>() );
    virtual bool runScenario( const int aSinglePeriod, Timer& aTimer );
    virtual void printOutput( Timer& aTimer, const bool aCloseDB ) const;
	virtual Scenario* getInternalScenario();
	virtual const Scenario* getInternalScenario() const;

	// IParsable Interface.
    bool XMLParse( const xercesc::DOMNode* aRoot );
protected:
    struct File {
        std::string mName;
        std::string mPath;
    };

    struct FileSet {
        std::vector<File> mFiles;
        std::string mName;
    };

    struct Component {
        std::vector<FileSet> mFileSets;
        std::vector<FileSet>::const_iterator mFileSetIterator;
        std::string mName;
    };
    
    typedef std::vector<Component> ComponentSet;
    ComponentSet mComponentSet; //!< Big data structure.
    std::vector<std::string> mUnsolvedNames; //!< List of scenarios that failed.
    std::auto_ptr<IScenarioRunner> mInternalRunner;
    
	BatchRunner();
	bool runSingleScenario( const Component aCurrComponents, Timer& aTimer );
    void XMLParseComponentSet( const xercesc::DOMNode* aNode );
    void XMLParseFileSet( const xercesc::DOMNode* aNode, Component& aCurrComponentSet );
	static const std::string& getXMLNameStatic();
    };
#endif // _BATCH_RUNNER_H_
