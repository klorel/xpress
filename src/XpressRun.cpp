/*
* XpressRun.cpp
*
*  Created on: Aug 6, 2014
*      Author: crystal
*/

#include "XpressRun.h"
#include "Instance.h"
#include "xprs.h"
#include "XpressConfig.h"
#include "Timer.h"
/**************************************************************************************\
* Name:         errormsg                                                               *
* Purpose:      Display error information about failed subroutines.                    *
* Arguments:    const char *sSubName   Subroutine name                                 *
*               int nLineNo            Line number                                     *
*               int nErrCode           Error code                                      *
* Return Value: None                                                                   *
\**************************************************************************************/
void errormsg(XPRSprob probg, const char *sSubName, int nLineNo, int nErrCode) {
  int nErrNo; /* Optimizer error number */

  /* Print error message */
  printf("The subroutine %s has failed on line %d\n", sSubName, nLineNo);

  /* Append the error code, if it exists */
  if (nErrCode != -1)
    printf("with error code %d.\n\n", nErrCode);

  /* Append Optimizer error number, if available */
  if (nErrCode == 32) {
    XPRSgetintattrib(probg, XPRS_ERRORCODE, &nErrNo);
    printf("The Optimizer error number is: %d.\n\n", nErrNo);
  }
  /* Free memory, close files and exit */
  XPRSdestroyprob(probg);
  XPRSfree();
  std::exit(nErrCode);
}
void XPRS_CC Message(XPRSprob my_prob, void* my_object,
                     const char *msg, int len, int msgtype)
{
  switch(msgtype)
  {
  case 4: /* error */
  case 3: /* warning */
  case 2: /* not used */
  case 1: /* information */
    printf("%s\n", msg);
    break;
  default: /* exiting - buffers need flushing */
    fflush(stdout);
    break;
  }
}

#define __XPRS_CALL_1(__NAME__,__PROB__,__ARG1__) nReturn = __NAME__(__ARG1__);\
  if (nReturn)\
  errormsg(__PROB__, #__NAME__, __LINE__, nReturn);

#define __XPRS_CALL_2(__NAME__,__PROB__,__ARG1__,__ARG2__) nReturn = __NAME__(__ARG1__,__ARG2__);\
  if (nReturn)\
  errormsg(__PROB__, #__NAME__, __LINE__, nReturn);

#define __XPRS_CALL_3(__NAME__,__PROB__,__ARG1__,__ARG2__,__ARG3__) nReturn = __NAME__(__ARG1__,__ARG2__,__ARG3__);\
  if (nReturn)\
  errormsg(__PROB__, #__NAME__, __LINE__, nReturn);

XpressRun::XpressRun(Instance const & instance)
  : _instance(instance),
  _printLog(false) {

}

XpressRun::~XpressRun() {
}

bool &XpressRun::printLog() {
  return _printLog;
}
bool XpressRun::printLog() const {
  return _printLog;
}

void XpressRun::exportMPS() {
  XPRSprob prob;
  int nReturn;
  __XPRS_CALL_1(XPRScreateprob, prob, &prob);

  std::string const fullPath(_instance.fullPath());
  std::cout << "fullPath : " << fullPath << std::endl;
  switch (_instance.fileType()) {
  case Instance::SVF:
    XPRSrestore(prob, fullPath.c_str(), NULL);
    break;
  case Instance::MPS:
  default:
    XPRSreadprob(prob, fullPath.c_str(), NULL);
    break;
  }
  XPRSsetcbmessage(prob, _printLog ? Message: NULL, NULL);
  __XPRS_CALL_3(XPRSsetintcontrol, prob, prob, XPRS_OUTPUTLOG,_printLog ? XPRS_OUTPUTLOG_FULL_OUTPUT:XPRS_OUTPUTLOG_NO_OUTPUT);
  XPRSwriteprob(prob, _instance.name().c_str(), "px");
  __XPRS_CALL_1(XPRSdestroyprob, prob, prob);

}

void XpressRun::launch(XpressControl const & input, XpressControl & output, XpressResult & result) {
  int const xprsoutput(_printLog ? XPRS_OUTPUTLOG_FULL_OUTPUT:XPRS_OUTPUTLOG_NO_OUTPUT);
  XPRSprob prob;
  int nReturn;
  __XPRS_CALL_1(XPRScreateprob, prob, &prob);
  std::string const fullPath(_instance.fullPath());
  XPRSsetcbmessage(prob, _printLog ? Message: NULL, NULL);
  __XPRS_CALL_3(XPRSsetintcontrol, prob, prob, XPRS_OUTPUTLOG,xprsoutput);
  if(_printLog)
    std::cout << "fullPath : " << fullPath << std::endl;
  switch (_instance.fileType()) {
  case Instance::SVF:
    XPRSrestore(prob, fullPath.c_str(), NULL);
    break;
  case Instance::MPS:
  default:
    XPRSreadprob(prob, fullPath.c_str(), NULL);
    break;
  }
  XpressConfig::Set(input, prob);
  __XPRS_CALL_3(XPRSsetintcontrol, prob, prob, XPRS_OUTPUTLOG,xprsoutput);
  Timer timer;
  __XPRS_CALL_2(XPRSmipoptimize, prob, prob, "");
  result["MIP_REAL"] = Str(timer.elapsed());
  //XPRSfixglobals(prob, 1);

  // warmstart
  //XPRSsetintcontrol(prob, XPRS_KEEPBASIS, 1);
  //XPRSlpoptimize(prob, "");
  // no warmstart
  //XPRSsetintcontrol(prob, XPRS_KEEPBASIS, 0);
  //XPRSlpoptimize(prob, "");
  XpressConfig::Get(output, prob);

  XpressConfig::Print(output, result);
  //  XpressConfig::Print(result);
  result["INSTANCE"] = _instance.name();
  /* Free memory, close files */
  __XPRS_CALL_1(XPRSdestroyprob, prob, prob);
}

double XpressRun::Init() {
  int nOptimizerVersion;
  XPRSinit(NULL);
  XPRSprob prob;
  XPRScreateprob(&prob);
  XPRSgetintcontrol(prob, XPRS_VERSION, &nOptimizerVersion);
  XPRSdestroyprob(prob);
  return nOptimizerVersion / 100.0;
}
void XpressRun::Free() {
  XPRSfree();
}
