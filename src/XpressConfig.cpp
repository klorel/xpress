/*
* XpressConfig.cpp
*
*  Created on: Aug 7, 2014
*      Author: crystal
*/

#include "XpressConfig.h"
#include "Instance.h"
#include "XpressRun.h"
#include <cmath>
#include <exception>
#include <stdexcept>

XpressControlValues XpressConfig::DefaultValues = XpressControlValues();
XpressCtrId XpressConfig::ControlTypes = XpressCtrId();
XpressCtrId XpressConfig::ControlIds = XpressCtrId();
XpressName XpressConfig::ControlNames = XpressName();
XpressName XpressConfig::MipStatusNames = XpressName();
XpressName XpressConfig::StopStatusNames = XpressName();


int XpressConfig::GetXprsType(int id) {
  int const base(static_cast<int>(std::floor(id/1000.0)));
  switch (base) {
  case 1:
    return XPRS_TYPE_INT;
    break;
  case 2:
    return XPRS_TYPE_DOUBLE;
    break;
  case 4:
    return XPRS_TYPE_DOUBLE;
    break;
  case 7:
    return XPRS_TYPE_DOUBLE;
    break;
  case 8:
    return XPRS_TYPE_INT;
    break;
  default:
    assert(false && "unknown control id");
    break;
  }
  return -1;
}
void XpressConfig::Init() {
  double xpressVersion = XpressRun::Init();
  Instance::Init();
  std::cout << "XPRESS version is " << xpressVersion << std::endl;
#define __NEW_CONTROL__(x) ControlNames[XPRS_ ## x] = #x;
#include "_control.hxx"
#undef __NEW_CONTROL__
#define __NEW_CONTROL__(x) MipStatusNames[XPRS_ ## x] = #x;
#include "_mip.hxx"
#undef __NEW_CONTROL__
#define __NEW_CONTROL__(x) StopStatusNames[XPRS_ ## x] = #x;
#include "_stop.hxx"
#undef __NEW_CONTROL__
  ControlIds.clear();
  ControlTypes.clear();
  for (auto const & ctr : ControlNames){
    ControlIds[ctr.second] = ctr.first;
    //    std::cout << ctr.second<<" - "<<ctr.first<<std::endl;
  }
  //  for (std::map<int, std::string>::const_iterator it(ControlNames.begin());
  //      it != ControlNames.end(); ++it) {
  //    std::cout << std::setw(10) << it->first;
  //    std::cout << std::setw(25) << it->second;
  //    std::cout << std::endl;
  //  }
  //  for (std::map<int, std::string>::const_iterator it(MipStatusNames.begin());
  //      it != MipStatusNames.end(); ++it) {
  //    std::cout << std::setw(10) << it->first;
  //    std::cout << std::setw(25) << it->second;
  //    std::cout << std::endl;
  //  }
  //  for (std::map<int, std::string>::const_iterator it(StopStatusNames.begin());
  //      it != StopStatusNames.end(); ++it) {
  //    std::cout << std::setw(10) << it->first;
  //    std::cout << std::setw(25) << it->second;
  //    std::cout << std::endl;
  //  }
}

void XpressConfig::Print(XpressResult const & result) {
  for (XpressResult::const_iterator it(result.begin()); it != result.end();
    ++it) {
      std::cout << it->first << " - " << it->second << std::endl;
  }
}
void XpressConfig::Print(XpressControl const & control) {
  Print_T(control.first);
  Print_T(control.second);
}
void XpressConfig::Print(XpressControlValues const & control) {
  for (auto const & ctr : control.first) {
    std::cout << std::setw(20) << GetControl(ctr.first) << " : ";
    for (auto const & v : ctr.second)
      std::cout << v << " ";
    std::cout << std::endl;
  }
  for (auto const & ctr : control.second) {
    std::cout << std::setw(20) << GetControl(ctr.first) << " : ";
    for (auto const & v : ctr.second)
      std::cout << v << " ";
    std::cout << std::endl;
  }
}
void XpressConfig::Print(XpressControl const & control, XpressResult & result) {
  Print_T(control.first, result);
  Print_T(control.second, result);
}

std::string XpressConfig::Get(int id, XpressName const & names) {
  XpressName::const_iterator it(names.find(id));
  if (it == names.end())
    return "UNKNOWN";
  else
    return it->second;

}
int XpressConfig::Get(std::string const & name) {
  return ControlIds.find(name)->second;

}
std::string XpressConfig::GetControl(int key) {
  return Get(key, ControlNames);
}
std::string XpressConfig::GetStopStatus(int key) {
  return Get(key, StopStatusNames);
}
std::string XpressConfig::GetMipStatus(int key) {
  return Get(key, MipStatusNames);
}
void XpressConfig::Clear(XpressControl & control) {
  control.first.clear();
  control.second.clear();
}

void XpressConfig::SetBase(XpressControl & control) {

  control.first[XPRS_MAXNODE] = 2000;
  control.first[XPRS_MAXTIME] = 300;
  control.first[XPRS_MIPTHREADS] = 1;
  control.first[XPRS_LPTHREADS] = 1;

  control.second[XPRS_MIPRELSTOP] = 1e-3;
  control.second[XPRS_MIPABSSTOP] = 80000;
}
void XpressConfig::SetCurrent(XpressControl & control) {
  control.first[XPRS_PRESOLVEOPS] = 1049599;
  control.first[XPRS_HEURDIVESTRATEGY] = 4;

  control.first[XPRS_SBITERLIMIT] = 0;

  control.first[XPRS_SCALING] = 0;
  control.first[XPRS_COVERCUTS] = 2;
  control.first[XPRS_CUTSELECT] = -8193;

  control.second[XPRS_FEASTOL] = 1e-5;
}
void XpressConfig::SetCandidate(XpressControl & control, size_t id) {
  switch(id){
  case 1:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_HEURDIVESTRATEGY] = 4;

    control.first[XPRS_SBITERLIMIT] = 100;

    control.first[XPRS_HEURSEARCHTREESELECT] = 0;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_SYMSELECT] = 0;
    control.second[XPRS_HEURSEARCHEFFORT] = 0.5;

    control.first[XPRS_CUTSTRATEGY] = 3;
    control.first[XPRS_BRANCHDISJ] = 3;
    control.first[XPRS_ROOTPRESOLVE] = 1;
    control.first[XPRS_VARSELECTION] = 2;

    // control.second[XPRS_FEASTOL] = 1e-5;
    // control.first[XPRS_SCALING] = 0;

    break;
  case 2:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_HEURSEARCHTREESELECT] = 3;
    control.first[XPRS_LOCALCHOICE] = 1;
    control.first[XPRS_SBBEST] = 500;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_SYMSELECT] = 2;
    control.second[XPRS_PERTURB] = 0;
    break;
  case 3:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_PREPROBING] = 1;
    control.first[XPRS_BRANCHDISJ] = 0;
    control.first[XPRS_HEURDIVESTRATEGY] = 5;  
    break;
  case 4:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_HEURDIVESTRATEGY] = 4;
    control.first[XPRS_HEURSEARCHTREESELECT] = 0;
    control.first[XPRS_SBITERLIMIT] = 100;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_SYMSELECT] = 0;
    control.second[XPRS_HEURSEARCHEFFORT] = 0.5;
    break;
  case 5:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_HEURSEARCHTREESELECT] = 3;
    control.first[XPRS_LOCALCHOICE] = 1;
    control.first[XPRS_SBBEST] = 500;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_SYMSELECT] = 2;
    control.second[XPRS_PERTURB] = 0;

    control.first[XPRS_CUTSELECT] = -8193;
    control.first[XPRS_SCALING] = 0;  

    control.second[XPRS_FEASTOL] = 1e-5;
    break;
  case 6:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_HEURSEARCHTREESELECT] = 3;
    control.first[XPRS_LOCALCHOICE] = 1;
    control.first[XPRS_SBBEST] = 500;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_SYMSELECT] = 2;
    control.second[XPRS_PERTURB] = 0;

    control.first[XPRS_CUTSELECT] = -8193;
    control.first[XPRS_SCALING] = 0;
    control.first[XPRS_HEURBEFORELP] = 0;  

    control.second[XPRS_FEASTOL] = 1e-5;
    break;
  case 7:
    control.first[XPRS_THREADS]=1;
    control.first[XPRS_HEURDIVESTRATEGY]=6;
    control.first[XPRS_COVERCUTS]=5;
    control.first[XPRS_GOMCUTS]=3;
    break;
  case 8:
    control.first[XPRS_THREADS]=1;
    control.first[XPRS_HEURDIVESTRATEGY]=6;
    control.first[XPRS_COVERCUTS]=5;
    control.first[XPRS_GOMCUTS]=3;

    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_HEURSEARCHTREESELECT] = 3;
    control.first[XPRS_LOCALCHOICE] = 1;
    control.first[XPRS_SBBEST] = 500;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_SYMSELECT] = 2;
    control.second[XPRS_PERTURB] = 0;

    control.first[XPRS_CUTSELECT] = -8193;
    control.first[XPRS_SCALING] = 0;
    control.first[XPRS_HEURBEFORELP] = 0;  

    control.second[XPRS_FEASTOL] = 1e-5;
    break;
  case 9:
    control.second[XPRS_CUTFACTOR]=0.5;
		control.first[XPRS_CUTSELECT]=-16385;
		control.first[XPRS_HEURDIVESPEEDUP]=4;
		control.first[XPRS_HEURDIVESTRATEGY]=10;
		control.second[XPRS_HEURSEARCHEFFORT]=0.5;
		control.first[XPRS_LNPBEST]=200;
		control.first[XPRS_MAXNODE]=2000;
		control.first[XPRS_MIPFRACREDUCE]=0;
		control.first[XPRS_PREPROBING]=0;
		control.first[XPRS_SYMMETRY]=0;
		control.first[XPRS_THREADS]=1;
    break;
  case 10:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.second[XPRS_CUTFACTOR]=0.5;
    control.first[XPRS_CUTSELECT]=-16385;
    control.first[XPRS_CUTSTRATEGY]=3;
    control.first[XPRS_HEURDIVESPEEDUP]=0;
    control.first[XPRS_HEURDIVESTRATEGY]=10;
    control.second[XPRS_HEURSEARCHEFFORT]=0.5;
    control.first[XPRS_HEURSEARCHROOTSELECT]=3;
    control.first[XPRS_LNPITERLIMIT]=0;
    control.first[XPRS_MAXNODE]=2000;
    control.first[XPRS_MIPFRACREDUCE]=0;
    control.second[XPRS_PERTURB]=0;
    control.first[XPRS_PREPROBING]=0;
    control.first[XPRS_SYMMETRY]=0;
    control.first[XPRS_THREADS]=1;
	break;
  case 11:
    control.first[XPRS_CUTSTRATEGY]=3;
    control.first[XPRS_DUALGRADIENT]=0;
    control.first[XPRS_LNPBEST]=200;
    control.first[XPRS_MAXNODE]=2000;
    control.second[XPRS_PERTURB]=0;
    control.first[XPRS_PREPROBING]=0;
    control.first[XPRS_SYMMETRY]=0;
    control.first[XPRS_THREADS]=1;
    break;
  case 12:
    control.first[XPRS_PRESOLVEOPS] = 1049599;
    control.first[XPRS_THREADS]=1;
    break;
  case 13:
    control.second[XPRS_CUTFACTOR]=1;
    control.first[XPRS_CUTSTRATEGY]=2;
    control.first[XPRS_GOMCUTS]=10;
    control.first[XPRS_HEURDIVESTRATEGY]=6;
    control.first[XPRS_LNPBEST]=0;
    control.first[XPRS_MAXNODE]=2000;
    control.first[XPRS_PREPROBING]=1;
    control.first[XPRS_PRESOLVEOPS]=1049599;
    control.first[XPRS_ROOTPRESOLVE]=1;
    control.first[XPRS_SYMMETRY]=0;
    control.first[XPRS_THREADS]=1;
    break;
  case 14:
    control.first[XPRS_DUALGRADIENT]=1;
    control.first[XPRS_GOMCUTS]=10;
    control.first[XPRS_HEURDIVESTRATEGY]=4;
    control.first[XPRS_LNPITERLIMIT]=0;
    control.first[XPRS_MAXNODE]=2000;
    control.first[XPRS_PRESOLVEOPS]=1049599;
    control.first[XPRS_SYMMETRY]=0;
    control.first[XPRS_THREADS]=1;
    break;
  case 15:
    control.first[XPRS_MIPRELSTOP]=0.001;
    control.first[XPRS_THREADS]=1;
    control.first[XPRS_HEURDIVESTRATEGY]=6;
    control.first[XPRS_COVERCUTS]=5;
    control.first[XPRS_GOMCUTS]=5;
    break;
  case 16:
    control.first[XPRS_COVERCUTS]=0;
    control.second[XPRS_CUTFACTOR]=5;
    control.first[XPRS_CUTSTRATEGY]=3;
    control.first[XPRS_GOMCUTS]=6;
    control.first[XPRS_HEURDIVESPEEDUP]=4;
    control.first[XPRS_HEURDIVESTRATEGY]=4;
    control.second[XPRS_HEURSEARCHEFFORT]=2;
    control.first[XPRS_MIPPRESOLVE]=3;
    control.first[XPRS_PRESOLVEOPS]=1049599;
    control.first[XPRS_SYMMETRY]=0;
    control.first[XPRS_THREADS]=1;
    break;
  case 17:
    control.second[XPRS_CUTFACTOR]=5;
    control.first[XPRS_CUTSTRATEGY]=1;
    control.first[XPRS_GOMCUTS]=9;
    control.first[XPRS_HEURDIVESTRATEGY]=4;
    control.second[XPRS_HEURSEARCHEFFORT]=2;
    control.first[XPRS_HEURSEARCHROOTSELECT]=0;
    control.first[XPRS_MIPFRACREDUCE]=0;
    control.first[XPRS_PRESOLVEOPS]=1049599;
    control.first[XPRS_ROOTPRESOLVE]=1;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_MAXNODE] = 10;
    break;
  case 18:
    control.second[XPRS_CUTFACTOR]=5;
    control.first[XPRS_CUTSTRATEGY]=1;
    control.first[XPRS_GOMCUTS]=9;
    control.first[XPRS_HEURDIVESTRATEGY]=4;
    control.second[XPRS_HEURSEARCHEFFORT]=2;
    control.first[XPRS_HEURSEARCHROOTSELECT]=0;
    control.first[XPRS_MIPFRACREDUCE]=0;
    control.first[XPRS_PRESOLVEOPS]=1049599;
    control.first[XPRS_ROOTPRESOLVE]=0;
    control.first[XPRS_SYMMETRY] = 0;
    control.first[XPRS_MAXNODE] = 10;
    break;
  default:
    throw std::logic_error("UNIMPLEMENTED CONFIGURATION");
    break;
  }
}
void XpressConfig::SetIndicator(XpressControl & control) {
  control.first[XPRS_ELEMS] = std::numeric_limits<int>::max();
  control.first[XPRS_COLS] = std::numeric_limits<int>::max();
  control.first[XPRS_ROWS] = std::numeric_limits<int>::max();
  control.first[XPRS_MIPENTS] = std::numeric_limits<int>::max();
  control.first[XPRS_NODES] = std::numeric_limits<int>::max();

  control.first[XPRS_ORIGINALCOLS] = std::numeric_limits<int>::max();
  control.first[XPRS_ORIGINALROWS] = std::numeric_limits<int>::max();
  control.first[XPRS_ORIGINALMIPENTS] = std::numeric_limits<int>::max();

  control.first[XPRS_MIPSOLS] = std::numeric_limits<int>::max();

  control.first[XPRS_MIPSTATUS] = std::numeric_limits<int>::max();
  control.first[XPRS_STOPSTATUS] = std::numeric_limits<int>::max();

  control.second[XPRS_BESTBOUND] = std::numeric_limits<int>::max();
  control.second[XPRS_MIPBESTOBJVAL] = std::numeric_limits<int>::max();

}

void XpressConfig::Set(XpressControl const & control, XPRSprob prob) {
  for (XpressIntControl::const_iterator it(control.first.begin());
    it != control.first.end(); ++it) {
      XPRSsetintcontrol(prob, it->first, it->second);
  }
  for (XpressDblControl::const_iterator it(control.second.begin());
    it != control.second.end(); ++it) {
      XPRSsetdblcontrol(prob, it->first, it->second);
  }
}
void XpressConfig::DefaultControl(XpressControlValues & result) {
  XPRSprob prob;
  XPRScreateprob(&prob);
  int intValue(0);
  double dblValue(0);
  XPRSsetdefaults(prob);
  for (auto & int_control : result.first) {
    XPRSgetintcontrol(prob, int_control.first, &intValue);
    int_control.second.insert(intValue);
  }
  for (auto & dbl_control : result.second) {
    XPRSgetdblcontrol(prob, dbl_control.first, &dblValue);
    dbl_control.second.insert(dblValue);
  }
  XPRSdestroyprob(prob);

}

void XpressConfig::Get(XpressControl & control, XPRSprob prob) {
  for (XpressIntControl::iterator it(control.first.begin());
    it != control.first.end(); ++it) {
      if (it->first >= 8000)
        XPRSgetintcontrol(prob, it->first, &it->second);
      else
        XPRSgetintattrib(prob, it->first, &it->second);
  }
  for (XpressDblControl::iterator it(control.second.begin());
    it != control.second.end(); ++it) {
      if (it->first >= 8000)
        XPRSgetdblcontrol(prob, it->first, &it->second);
      else
        XPRSgetdblattrib(prob, it->first, &it->second);
  }
}
