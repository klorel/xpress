/*
 * XpressConfig.h
 *
 *  Created on: Aug 7, 2014
 *      Author: crystal
 */

#ifndef XPRESSCONFIG_H_
#define XPRESSCONFIG_H_
#include "common.h"
#include "xprs.h"


struct XpressConfig {
 public:
  static void Clear(XpressControl &);

  static void SetIndicator(XpressControl &);

  static void SetBase(XpressControl &);
  static void SetCurrent(XpressControl &);
  static void SetCandidate(XpressControl &, size_t);

  static void Set(XpressControl const &, XPRSprob prob);
  static void Get(XpressControl &, XPRSprob prob);

  static void DefaultControl( XpressControlValues&);


  static void Init();

  static void Print(XpressResult const &);

  static void Print(XpressControlValues const &);

  static void Print(XpressControl const &);
  template<class T> static void Print_T(T const &);

  static void Print(XpressControl const &, XpressResult & result);
  template<class T> static void Print_T(T const &, XpressResult & result);

  static std::string GetControl(int);
  static std::string GetStopStatus(int);
  static std::string GetMipStatus(int);

  static std::string Get(int, XpressName const &);
  static int Get(std::string const &);
  static int GetXprsType(int id);
 private:
  static XpressControlValues DefaultValues;
  static XpressCtrId ControlTypes;
  static XpressCtrId ControlIds;
  static XpressName ControlNames;
  static XpressName StopStatusNames;
  static XpressName MipStatusNames;
};
template<class T> inline void XpressConfig::Print_T(T const & t) {
  for (typename T::const_iterator it(t.begin()); it != t.end(); ++it) {
    std::cout << std::setw(20) << GetControl(it->first);
    if (it->first == XPRS_MIPSTATUS)
      std::cout << std::setw(20) << GetMipStatus(it->second);
    else if (it->first == XPRS_STOPSTATUS)
      std::cout << std::setw(20) << GetStopStatus(it->second);
    else
      std::cout << std::setw(20) << std::setprecision(10) << it->second;
    std::cout << std::endl;
  }
}
template<class T> inline void XpressConfig::Print_T(T const & t,
                                                    XpressResult & result) {
  std::stringstream buffer;
  for (typename T::const_iterator it(t.begin()); it != t.end(); ++it) {
    buffer.str("");
    if (it->first == XPRS_MIPSTATUS)
      buffer << GetMipStatus(it->second);
    else if (it->first == XPRS_STOPSTATUS)
      buffer << GetStopStatus(it->second);
    else
      buffer << std::setprecision(10) << it->second;
    result[GetControl(it->first)] = buffer.str();

  }
}

#endif /* XPRESSCONFIG_H_ */
