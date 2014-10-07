/*
 * XpressRun.h
 *
 *  Created on: Aug 6, 2014
 *      Author: crystal
 */

#ifndef XPRESSRUN_H_
#define XPRESSRUN_H_

#include "common.h"

class XpressRun {
 public:
  static double Init();
  static void Free();
 public:
  XpressRun(Instance const &);
  virtual ~XpressRun();

 public:
  void exportMPS();
  void launch(XpressControl const & input, XpressControl & output,
              XpressResult & result);
  bool & printLog();
  bool printLog() const ;
 private:
  Instance const & _instance;
  bool _printLog;
};

#endif /* XPRESSRUN_H_ */
