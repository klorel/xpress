#include "common.h"
#include "Instance.h"
#include "XpressRun.h"
#include "XpressConfig.h"

void readStrategy(std::string const & fileName, XpressControlValues & result) {
  std::ifstream file(fileName.c_str());
  std::string name;
  double value;
  std::set<std::string> names;
  while (file >> name) {
    file >> value;
//    std::cout << name << " : " << value << std::endl;
    int id(XpressConfig::Get(name));
//    std::cout << "id : "<<id<<std::endl;
    int type(XpressConfig::GetXprsType(id));
    if (type == XPRS_TYPE_DOUBLE)
      result.second[id].insert(value);
    else
      result.first[id].insert(value);
    if (id == 0)
      names.insert(name);
  }
  for (auto const & name : names) {
    std::cout << "__NEW_CONTROL__(" << name << ")" << std::endl;
  }
  size_t n(1);
  for (auto const & it : result.first) {
    n *= it.second.size();
  }
  for (auto const & it : result.second) {
    n *= it.second.size();
  }
  std::cout << "read " << result.first.size() + result.second.size()
            << " parameters" << std::endl;
  std::cout << "number of runs : " << n << std::endl;
}

int main(int argc, char ** argv) {
//
  std::cout << "argc = "<<argc<<std::endl;
  int useCandidate( argc>1 ? atoi(argv[1]):false);
  std::stringstream buffer;
  buffer << "7.7.P"<<useCandidate;
  std::string const paramName(buffer.str());
  std::cout << "PARAMETERS : " <<paramName<< std::endl;
  XpressConfig::Init();

//  XpressControlValues ctrValues;
//  readStrategy("../acs.txt", ctrValues);
////  XpressConfig::Print(ctrValues);
//  XpressConfig::DefaultControl(ctrValues);
////  XpressConfig::Print(ctrValues);
//  std::exit(-1);
  //

  std::cout << Instance::AllInstances.size() << " instances" << std::endl;
//
  XpressControl input;
  XpressConfig::SetBase(input);
  if(useCandidate==0)
     XpressConfig::SetCurrent(input);
  else
    XpressConfig::SetCandidate(input, useCandidate);

  XpressControl output;
  XpressConfig::SetIndicator(output);

  XpressResults results;
  Instances problematic;
  //problematic.insert("J1_S51-PDT4158");
  //problematic.insert("J1_S291-PDT4032");
  //problematic.insert("modeleXPRESS_150_0");
  //problematic.insert("J3_S51-PDT4032");
  problematic = Instance::AllInstances;
  std::cout << "BEGINNING LOOP" << std::endl;
  size_t i(0);

  for (Instances::const_iterator it(problematic.begin());
      it != problematic.end(); ++it, ++i) {
    Instance instance(it);
    std::cout << std::setw(8)<<paramName;
    std::cout << std::setw(4) << i + 1 << "/" << problematic.size();
    std::cout << std::setw(25) << instance.name();
    std::cout << std::endl;
    XpressRun run(instance);
    run.printLog() = problematic.size()==1;
    run.launch(input, output, results[i]);
    results[i]["PARAMETERS"] = paramName;
//    run.exportMPS();
//    if (i > 0)
//      break;
  }

  Headers headers;  
  headers.push_back("PARAMETERS");
  headers.push_back("INSTANCE");
  headers.push_back("NODES");
  headers.push_back("MIPSTATUS");
  headers.push_back("STOPSTATUS");
  headers.push_back("BESTBOUND");
  headers.push_back("MIPBESTOBJVAL");
  headers.push_back("MIPSOLS");
  headers.push_back("MIP_REAL");
  std::stringstream out;

  std::copy(headers.begin(), headers.end(),
            std::ostream_iterator<std::string>(out, ";"));
  out << std::endl;
  if (!results.empty()) {
    for (XpressResults::const_iterator it(results.begin()); it != results.end();
        ++it) {
      for (Headers::const_iterator jt(headers.begin()); jt != headers.end();
          ++jt) {
        out << it->second.find(*jt)->second << ";";
      }
      out << std::endl;
    }
    std::cout << out.str() << std::endl;
  }
  std::stringstream resultName;
  resultName<<"result_P"<<useCandidate<<".csv";
  std::ofstream file(resultName.str().c_str());
  file << out.str();
  file.close();
  XpressRun::Free();
  return 0;
}
