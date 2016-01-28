#ifndef ParameterCache_h
#define ParameterCache_h

#include <iostream>
#include <vector>
#include <algorithm>

#include "Combiner.h"
#include "MethodAbsScan.h"
#include "RooAbsArg.h"
#include "RooSlimFitResult.h"
#include "TDatime.h"
#include "TIterator.h"
#include "TString.h"
#include "Utils.h"
#include "boost/algorithm/string/predicate.hpp"
#include "boost/algorithm/string/split.hpp"
#include "boost/lexical_cast.hpp"

class ParameterCache {

	public:

		ParameterCache(OptParser* arg);
		~ParameterCache();

		void cacheParameters(MethodAbsScan *scanner, TString fileName);
		bool loadPoints(TString fileName);
		void printFitResultToOutStream(ofstream &out, RooSlimFitResult *slimFitResult);
		void printPoint();
		int getNPoints();
		void setPoint(Combiner* cmb, int i, bool isToy=false);
		void setPoint(MethodAbsScan *scanner, int i, bool isToy=false);
		std::vector<TString> getFixedNames(std::vector<Utils::FixPar> fixPar);
		std::vector<std::map<TString,double> > startingValues;
		std::vector<std::map<TString,double> > startingErrorLo;
		std::vector<std::map<TString,double> > startingErrorHi;

	private:

		bool m_parametersLoaded;
		OptParser* m_arg;
};

#endif

