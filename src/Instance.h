/*
 * Instance.h
 *
 *  Created on: Aug 6, 2014
 *      Author: crystal
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "common.h"

typedef std::set<std::string> Instances;

class Instance {
 public:
  enum FileType{MPS,SVF};
 public:
  static std::string Root;
  static std::string PathSep;
  static Instances AllInstances;
  static void Init();
 public:
  Instance(Instances::const_iterator);
  virtual ~Instance();
  std::string name()const;
  std::string fullPath()const;
  void setMip();
  void setLp();
  bool isMip()const;
  FileType fileType()const;
 private:
  Instances::const_iterator const _it;
  bool _isMip;
  FileType _fileType;
};

#endif /* INSTANCE_H_ */
