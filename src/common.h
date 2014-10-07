/*
 * common.h
 *
 *  Created on: Aug 7, 2014
 *      Author: crystal
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <cassert>
#include <cstdlib>
#include <numeric>
#include <limits>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <iomanip>
#include <utility>
#include <iterator>
#include <tuple>

#include <stdio.h>

typedef std::map<int, int> XpressIntControl;
typedef std::map<int, double> XpressDblControl;
typedef std::pair<XpressIntControl, XpressDblControl> XpressControl;


typedef std::map<int, std::string> XpressName;
typedef std::map<std::string, int> XpressCtrId;
typedef std::map<std::string, std::string> XpressResult;
typedef std::map<size_t, XpressResult> XpressResults;

typedef std::map<int, std::set<int> > XpressIntControlValues;
typedef std::map<int, std::set<double> > XpressDblControlValues;
typedef std::pair<XpressIntControlValues, XpressDblControlValues> XpressControlValues;


typedef std::list<std::string> Headers;

class Instance;

template<class T> std::string Str(T const & t){
  std::stringstream buffer;
  buffer << t;
  return buffer.str();
}

#endif /* COMMON_H_ */
