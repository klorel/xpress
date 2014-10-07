/*
* Instance.cpp
*
*  Created on: Aug 6, 2014
*      Author: crystal
*/

#include "Instance.h"

#ifdef _WIN32
std::string Instance::PathSep = "\\\\";
#else
std::string Instance::PathSep = "/";
#endif

std::string Instance::Root = "..";
Instances Instance::AllInstances = Instances();

Instance::Instance(Instances::const_iterator it)
  : _it(it),
  _isMip(true), _fileType(MPS){
    Init();
}

Instance::~Instance() {
  // TODO Auto-generated destructor stub
}
std::string Instance::name() const {
  return *_it;
}
std::string Instance::fullPath() const {
  switch (_fileType) {
  case SVF:
    if (_isMip)
      return Root + Instance::PathSep+"MIP" +Instance::PathSep+ *_it + ".svf";
    else
      return Root + Instance::PathSep+"LP"+ Instance::PathSep+ *_it + ".svf";
    break;

  case MPS:
  default:
    if (_isMip)
      return Root + Instance::PathSep+"mps_mip"+Instance::PathSep+*_it+".mps";
    else
      return Root + Instance::PathSep+"LP"+Instance::PathSep+ *_it + ".mps";
    break;
  }
}

void Instance::setMip() {
  _isMip = true;
}
void Instance::setLp() {
  _isMip = false;
}
bool Instance::isMip() const {
  return _isMip;
}
Instance::FileType Instance::fileType()const{
  return _fileType;

}
void addEchantillon(Instances & AllInstances){
  AllInstances.insert("J1_S1-PDT3402");
  AllInstances.insert("J1_S102-PDT126");
  AllInstances.insert("J1_S11-PDT4242");
  AllInstances.insert("J1_S113-PDT4494");
  AllInstances.insert("J1_S115-PDT5964");
  AllInstances.insert("J1_S115-PDT7476");
  AllInstances.insert("J1_S124-PDT3108");
  AllInstances.insert("J1_S13-PDT7098");
  AllInstances.insert("J1_S131-PDT6594");
  AllInstances.insert("J1_S136-PDT588");
  AllInstances.insert("J1_S136-PDT6342");
  AllInstances.insert("J1_S138-PDT4032");
  AllInstances.insert("J1_S141-PDT1050");
  AllInstances.insert("J1_S144-PDT6468");
  AllInstances.insert("J1_S160-PDT3780");
  AllInstances.insert("J1_S166-PDT2184");
  AllInstances.insert("J1_S167-PDT2898");
  AllInstances.insert("J1_S171-PDT1218");
  AllInstances.insert("J1_S19-PDT1722");
  AllInstances.insert("J1_S190-PDT4200");
  AllInstances.insert("J1_S193-PDT7224");
  AllInstances.insert("J1_S196-PDT1260");
  AllInstances.insert("J1_S202-PDT6594");
  AllInstances.insert("J1_S205-PDT4998");
  AllInstances.insert("J1_S211-PDT3864");
  AllInstances.insert("J1_S219-PDT0");
  AllInstances.insert("J1_S220-PDT1806");
  AllInstances.insert("J1_S224-PDT4620");
  AllInstances.insert("J1_S229-PDT6888");
  AllInstances.insert("J1_S233-PDT6132");
  AllInstances.insert("J1_S247-PDT336");
  AllInstances.insert("J1_S247-PDT6678");
  AllInstances.insert("J1_S260-PDT3192");
  AllInstances.insert("J1_S262-PDT3612");
  AllInstances.insert("J1_S262-PDT4494");
  AllInstances.insert("J1_S262-PDT5208");
  AllInstances.insert("J1_S263-PDT3234");
  AllInstances.insert("J1_S271-PDT84");
  AllInstances.insert("J1_S277-PDT1722");
  AllInstances.insert("J1_S280-PDT2562");
  AllInstances.insert("J1_S281-PDT5292");
  AllInstances.insert("J1_S282-PDT7098");
  AllInstances.insert("J1_S284-PDT1008");
  AllInstances.insert("J1_S284-PDT672");
  AllInstances.insert("J1_S288-PDT5586");
  AllInstances.insert("J1_S291-PDT4032");
  AllInstances.insert("J1_S293-PDT7770");
  AllInstances.insert("J1_S30-PDT6846");
  AllInstances.insert("J1_S300-PDT798");
  AllInstances.insert("J1_S305-PDT3990");
  AllInstances.insert("J1_S307-PDT5292");
  AllInstances.insert("J1_S307-PDT5376");
  AllInstances.insert("J1_S310-PDT5796");
  AllInstances.insert("J1_S323-PDT5796");
  AllInstances.insert("J1_S324-PDT5208");
  AllInstances.insert("J1_S327-PDT1218");
  AllInstances.insert("J1_S331-PDT1638");
  AllInstances.insert("J1_S343-PDT3780");
  AllInstances.insert("J1_S348-PDT6888");
  AllInstances.insert("J1_S357-PDT7980");
  AllInstances.insert("J1_S359-PDT5922");
  AllInstances.insert("J1_S37-PDT546");
  AllInstances.insert("J1_S375-PDT7224");
  AllInstances.insert("J1_S38-PDT2646");
  AllInstances.insert("J1_S380-PDT6636");
  AllInstances.insert("J1_S381-PDT4368");
  AllInstances.insert("J1_S382-PDT5418");
  AllInstances.insert("J1_S388-PDT5628");
  AllInstances.insert("J1_S389-PDT3948");
  AllInstances.insert("J1_S396-PDT7266");
  AllInstances.insert("J1_S40-PDT6006");
  AllInstances.insert("J1_S406-PDT6258");
  AllInstances.insert("J1_S41-PDT5250");
  AllInstances.insert("J1_S41-PDT6174");
  AllInstances.insert("J1_S416-PDT1470");
  AllInstances.insert("J1_S416-PDT5376");
  AllInstances.insert("J1_S42-PDT5124");
  AllInstances.insert("J1_S422-PDT2856");
  AllInstances.insert("J1_S43-PDT7938");
  AllInstances.insert("J1_S431-PDT5334");
  AllInstances.insert("J1_S436-PDT3486");
  AllInstances.insert("J1_S44-PDT84");
  AllInstances.insert("J1_S444-PDT1302");
  AllInstances.insert("J1_S446-PDT7350");
  AllInstances.insert("J1_S448-PDT2352");
  AllInstances.insert("J1_S456-PDT462");
  AllInstances.insert("J1_S462-PDT714");
  AllInstances.insert("J1_S469-PDT5754");
  AllInstances.insert("J1_S473-PDT5208");
  AllInstances.insert("J1_S476-PDT6678");
  AllInstances.insert("J1_S5-PDT1638");
  AllInstances.insert("J1_S50-PDT3654");
  AllInstances.insert("J1_S51-PDT4158");
  AllInstances.insert("J1_S56-PDT4998");
  AllInstances.insert("J1_S58-PDT588");
  AllInstances.insert("J1_S68-PDT630");
  AllInstances.insert("J1_S68-PDT7728");
  AllInstances.insert("J1_S79-PDT3570");
  AllInstances.insert("J1_S79-PDT3948");
  AllInstances.insert("J1_S8-PDT4788");
  AllInstances.insert("J2_S103-PDT3654");
  AllInstances.insert("J2_S107-PDT4410");
  AllInstances.insert("J2_S11-PDT1470");
  AllInstances.insert("J2_S110-PDT1218");
  AllInstances.insert("J2_S114-PDT5586");
  AllInstances.insert("J2_S115-PDT5250");
  AllInstances.insert("J2_S122-PDT3276");
  AllInstances.insert("J2_S130-PDT2856");
  AllInstances.insert("J2_S146-PDT7518");
  AllInstances.insert("J2_S147-PDT2940");
  AllInstances.insert("J2_S150-PDT1344");
  AllInstances.insert("J2_S160-PDT4914");
  AllInstances.insert("J2_S162-PDT5376");
  AllInstances.insert("J2_S166-PDT3108");
  AllInstances.insert("J2_S167-PDT1680");
  AllInstances.insert("J2_S173-PDT5754");
  AllInstances.insert("J2_S182-PDT4998");
  AllInstances.insert("J2_S183-PDT4032");
  AllInstances.insert("J2_S190-PDT4242");
  AllInstances.insert("J2_S197-PDT6300");
  AllInstances.insert("J2_S207-PDT6384");
  AllInstances.insert("J2_S216-PDT1974");
  AllInstances.insert("J2_S217-PDT4116");
  AllInstances.insert("J2_S217-PDT714");
  AllInstances.insert("J2_S218-PDT7518");
  AllInstances.insert("J2_S220-PDT6426");
  AllInstances.insert("J2_S224-PDT1302");
  AllInstances.insert("J2_S226-PDT6552");
  AllInstances.insert("J2_S227-PDT6300");
  AllInstances.insert("J2_S228-PDT3108");
  AllInstances.insert("J2_S231-PDT5838");
  AllInstances.insert("J2_S234-PDT4032");
  AllInstances.insert("J2_S236-PDT1092");
  AllInstances.insert("J2_S237-PDT504");
  AllInstances.insert("J2_S239-PDT5166");
  AllInstances.insert("J2_S241-PDT546");
  AllInstances.insert("J2_S251-PDT504");
  AllInstances.insert("J2_S257-PDT4368");
  AllInstances.insert("J2_S261-PDT4242");
  AllInstances.insert("J2_S262-PDT2730");
  AllInstances.insert("J2_S263-PDT4830");
  AllInstances.insert("J2_S264-PDT4578");
  AllInstances.insert("J2_S264-PDT7602");
  AllInstances.insert("J2_S268-PDT8064");
  AllInstances.insert("J2_S281-PDT1638");
  AllInstances.insert("J2_S281-PDT882");
  AllInstances.insert("J2_S284-PDT6174");
  AllInstances.insert("J2_S286-PDT3192");
  AllInstances.insert("J2_S29-PDT5124");
  AllInstances.insert("J2_S291-PDT3990");
  AllInstances.insert("J2_S298-PDT1974");
  AllInstances.insert("J2_S303-PDT5418");
  AllInstances.insert("J2_S31-PDT1722");
  AllInstances.insert("J2_S31-PDT4410");
  AllInstances.insert("J2_S335-PDT7476");
  AllInstances.insert("J2_S336-PDT5460");
  AllInstances.insert("J2_S345-PDT756");
  AllInstances.insert("J2_S352-PDT6888");
  AllInstances.insert("J2_S36-PDT6258");
  AllInstances.insert("J2_S361-PDT3444");
  AllInstances.insert("J2_S367-PDT2142");
  AllInstances.insert("J2_S37-PDT7518");
  AllInstances.insert("J2_S370-PDT4326");
  AllInstances.insert("J2_S373-PDT3192");
  AllInstances.insert("J2_S375-PDT6846");
  AllInstances.insert("J2_S376-PDT966");
  AllInstances.insert("J2_S378-PDT1512");
  AllInstances.insert("J2_S38-PDT2562");
  AllInstances.insert("J2_S384-PDT42");
  AllInstances.insert("J2_S39-PDT6300");
  AllInstances.insert("J2_S4-PDT3150");
  AllInstances.insert("J2_S404-PDT4494");
  AllInstances.insert("J2_S405-PDT4326");
  AllInstances.insert("J2_S412-PDT2772");
  AllInstances.insert("J2_S414-PDT4116");
  AllInstances.insert("J2_S414-PDT6930");
  AllInstances.insert("J2_S420-PDT7056");
  AllInstances.insert("J2_S423-PDT5838");
  AllInstances.insert("J2_S427-PDT2184");
  AllInstances.insert("J2_S428-PDT1722");
  AllInstances.insert("J2_S433-PDT5838");
  AllInstances.insert("J2_S443-PDT5082");
  AllInstances.insert("J2_S444-PDT168");
  AllInstances.insert("J2_S449-PDT6090");
  AllInstances.insert("J2_S453-PDT588");
  AllInstances.insert("J2_S470-PDT7980");
  AllInstances.insert("J2_S475-PDT2352");
  AllInstances.insert("J2_S482-PDT6720");
  AllInstances.insert("J2_S51-PDT4116");
  AllInstances.insert("J2_S57-PDT4284");
  AllInstances.insert("J2_S61-PDT1260");
  AllInstances.insert("J2_S67-PDT7434");
  AllInstances.insert("J2_S68-PDT6006");
  AllInstances.insert("J2_S70-PDT7182");
  AllInstances.insert("J2_S74-PDT4200");
  AllInstances.insert("J2_S76-PDT504");
  AllInstances.insert("J2_S80-PDT4830");
  AllInstances.insert("J2_S83-PDT6846");
  AllInstances.insert("J2_S91-PDT7560");
  AllInstances.insert("J2_S93-PDT2604");
  AllInstances.insert("J2_S97-PDT1890");
  AllInstances.insert("J2_S98-PDT630");
  AllInstances.insert("J3_S103-PDT7854");
  AllInstances.insert("J3_S104-PDT2394");
  AllInstances.insert("J3_S136-PDT1890");
  AllInstances.insert("J3_S137-PDT5460");
  AllInstances.insert("J3_S140-PDT3360");
  AllInstances.insert("J3_S141-PDT6090");
  AllInstances.insert("J3_S143-PDT6930");
  AllInstances.insert("J3_S145-PDT5124");
  AllInstances.insert("J3_S151-PDT7434");
  AllInstances.insert("J3_S156-PDT5334");
  AllInstances.insert("J3_S157-PDT1554");
  AllInstances.insert("J3_S168-PDT7686");
  AllInstances.insert("J3_S169-PDT5166");
  AllInstances.insert("J3_S186-PDT6552");
  AllInstances.insert("J3_S190-PDT3444");
  AllInstances.insert("J3_S203-PDT4620");
  AllInstances.insert("J3_S204-PDT1512");
  AllInstances.insert("J3_S204-PDT3780");
  AllInstances.insert("J3_S214-PDT4368");
  AllInstances.insert("J3_S217-PDT126");
  AllInstances.insert("J3_S221-PDT2688");
  AllInstances.insert("J3_S223-PDT4788");
  AllInstances.insert("J3_S232-PDT3780");
  AllInstances.insert("J3_S234-PDT6804");
  AllInstances.insert("J3_S248-PDT2646");
  AllInstances.insert("J3_S25-PDT5460");
  AllInstances.insert("J3_S25-PDT7602");
  AllInstances.insert("J3_S256-PDT5754");
  AllInstances.insert("J3_S271-PDT378");
  AllInstances.insert("J3_S275-PDT756");
  AllInstances.insert("J3_S277-PDT3318");
  AllInstances.insert("J3_S286-PDT7266");
  AllInstances.insert("J3_S287-PDT3570");
  AllInstances.insert("J3_S291-PDT3990");
  AllInstances.insert("J3_S301-PDT8022");
  AllInstances.insert("J3_S308-PDT6888");
  AllInstances.insert("J3_S314-PDT8022");
  AllInstances.insert("J3_S314-PDT8022.old");
  AllInstances.insert("J3_S328-PDT6804");
  AllInstances.insert("J3_S329-PDT6678");
  AllInstances.insert("J3_S335-PDT7602");
  AllInstances.insert("J3_S338-PDT7686");
  AllInstances.insert("J3_S340-PDT4116");
  AllInstances.insert("J3_S343-PDT2478");
  AllInstances.insert("J3_S346-PDT5712");
  AllInstances.insert("J3_S349-PDT1848");
  AllInstances.insert("J3_S36-PDT8022");
  AllInstances.insert("J3_S361-PDT3234");
  AllInstances.insert("J3_S369-PDT4746");
  AllInstances.insert("J3_S375-PDT7854");
  AllInstances.insert("J3_S38-PDT378");
  AllInstances.insert("J3_S392-PDT5040");
  AllInstances.insert("J3_S401-PDT4956");
  AllInstances.insert("J3_S41-PDT3192");
  AllInstances.insert("J3_S412-PDT5628");
  AllInstances.insert("J3_S416-PDT4494");
  AllInstances.insert("J3_S425-PDT6342");
  AllInstances.insert("J3_S425-PDT7098");
  AllInstances.insert("J3_S429-PDT2058");
  AllInstances.insert("J3_S43-PDT0");
  AllInstances.insert("J3_S437-PDT7854");
  AllInstances.insert("J3_S457-PDT1512");
  AllInstances.insert("J3_S458-PDT2604");
  AllInstances.insert("J3_S463-PDT5754");
  AllInstances.insert("J3_S474-PDT1890");
  AllInstances.insert("J3_S480-PDT6132");
  AllInstances.insert("J3_S51-PDT4032");
  AllInstances.insert("J3_S55-PDT5124");
  AllInstances.insert("J3_S67-PDT4116");
  AllInstances.insert("J3_S74-PDT4116");
  AllInstances.insert("J3_S77-PDT7938");
  AllInstances.insert("J3_S9-PDT7434");
  AllInstances.insert("J3_S9-PDT966");
  AllInstances.insert("J3_S91-PDT7182");
}
void addOther(Instances & AllInstances){
    AllInstances.insert("modeleXPRESS_150_0");
    AllInstances.insert("modeleXPRESS_150_1008");
    AllInstances.insert("modeleXPRESS_150_1050");
    AllInstances.insert("modeleXPRESS_150_1092");
    AllInstances.insert("modeleXPRESS_150_1134");
    AllInstances.insert("modeleXPRESS_150_1176");
    AllInstances.insert("modeleXPRESS_150_1218");
    AllInstances.insert("modeleXPRESS_150_126");
    AllInstances.insert("modeleXPRESS_150_1260");
    AllInstances.insert("modeleXPRESS_150_1302");
    AllInstances.insert("modeleXPRESS_150_1344");
    AllInstances.insert("modeleXPRESS_150_1386");
    AllInstances.insert("modeleXPRESS_150_1428");
    AllInstances.insert("modeleXPRESS_150_1470");
    AllInstances.insert("modeleXPRESS_150_1512");
    AllInstances.insert("modeleXPRESS_150_1554");
    AllInstances.insert("modeleXPRESS_150_1596");
    AllInstances.insert("modeleXPRESS_150_1638");
    AllInstances.insert("modeleXPRESS_150_168");
    AllInstances.insert("modeleXPRESS_150_1680");
    AllInstances.insert("modeleXPRESS_150_1722");
    AllInstances.insert("modeleXPRESS_150_1764");
    AllInstances.insert("modeleXPRESS_150_1806");
    AllInstances.insert("modeleXPRESS_150_1848");
    AllInstances.insert("modeleXPRESS_150_1890");
    AllInstances.insert("modeleXPRESS_150_1932");
    AllInstances.insert("modeleXPRESS_150_1974");
    AllInstances.insert("modeleXPRESS_150_2016");
    AllInstances.insert("modeleXPRESS_150_2058");
    AllInstances.insert("modeleXPRESS_150_210");
    AllInstances.insert("modeleXPRESS_150_2100");
    AllInstances.insert("modeleXPRESS_150_2142");
    AllInstances.insert("modeleXPRESS_150_2184");
    AllInstances.insert("modeleXPRESS_150_2226");
    AllInstances.insert("modeleXPRESS_150_2268");
    AllInstances.insert("modeleXPRESS_150_2310");
    AllInstances.insert("modeleXPRESS_150_2352");
    AllInstances.insert("modeleXPRESS_150_2394");
    AllInstances.insert("modeleXPRESS_150_2436");
    AllInstances.insert("modeleXPRESS_150_2478");
    AllInstances.insert("modeleXPRESS_150_252");
    AllInstances.insert("modeleXPRESS_150_2520");
    AllInstances.insert("modeleXPRESS_150_2562");
    AllInstances.insert("modeleXPRESS_150_2604");
    AllInstances.insert("modeleXPRESS_150_2646");
    AllInstances.insert("modeleXPRESS_150_2688");
    AllInstances.insert("modeleXPRESS_150_2730");
    AllInstances.insert("modeleXPRESS_150_2772");
    AllInstances.insert("modeleXPRESS_150_2814");
    AllInstances.insert("modeleXPRESS_150_2856");
    AllInstances.insert("modeleXPRESS_150_2898");
    AllInstances.insert("modeleXPRESS_150_294");
    AllInstances.insert("modeleXPRESS_150_2940");
    AllInstances.insert("modeleXPRESS_150_2982");
    AllInstances.insert("modeleXPRESS_150_3024");
    AllInstances.insert("modeleXPRESS_150_3066");
    AllInstances.insert("modeleXPRESS_150_3108");
    AllInstances.insert("modeleXPRESS_150_3150");
    AllInstances.insert("modeleXPRESS_150_3192");
    AllInstances.insert("modeleXPRESS_150_3234");
    AllInstances.insert("modeleXPRESS_150_3276");
    AllInstances.insert("modeleXPRESS_150_3318");
    AllInstances.insert("modeleXPRESS_150_336");
    AllInstances.insert("modeleXPRESS_150_3360");
    AllInstances.insert("modeleXPRESS_150_3402");
    AllInstances.insert("modeleXPRESS_150_3444");
    AllInstances.insert("modeleXPRESS_150_3486");
    AllInstances.insert("modeleXPRESS_150_3528");
    AllInstances.insert("modeleXPRESS_150_3570");
    AllInstances.insert("modeleXPRESS_150_3612");
    AllInstances.insert("modeleXPRESS_150_3654");
    AllInstances.insert("modeleXPRESS_150_3696");
    AllInstances.insert("modeleXPRESS_150_3738");
    AllInstances.insert("modeleXPRESS_150_378");
    AllInstances.insert("modeleXPRESS_150_3780");
    AllInstances.insert("modeleXPRESS_150_3822");
    AllInstances.insert("modeleXPRESS_150_3864");
    AllInstances.insert("modeleXPRESS_150_3906");
    AllInstances.insert("modeleXPRESS_150_3948");
    AllInstances.insert("modeleXPRESS_150_3990");
    AllInstances.insert("modeleXPRESS_150_4032");
    AllInstances.insert("modeleXPRESS_150_4074");
    AllInstances.insert("modeleXPRESS_150_4116");
    AllInstances.insert("modeleXPRESS_150_4158");
    AllInstances.insert("modeleXPRESS_150_42");
    AllInstances.insert("modeleXPRESS_150_420");
    AllInstances.insert("modeleXPRESS_150_4200");
    AllInstances.insert("modeleXPRESS_150_4242");
    AllInstances.insert("modeleXPRESS_150_4284");
    AllInstances.insert("modeleXPRESS_150_4326");
    AllInstances.insert("modeleXPRESS_150_4368");
    AllInstances.insert("modeleXPRESS_150_4410");
    AllInstances.insert("modeleXPRESS_150_4452");
    AllInstances.insert("modeleXPRESS_150_4494");
    AllInstances.insert("modeleXPRESS_150_4536");
    AllInstances.insert("modeleXPRESS_150_4578");
    AllInstances.insert("modeleXPRESS_150_462");
    AllInstances.insert("modeleXPRESS_150_4620");
    AllInstances.insert("modeleXPRESS_150_4662");
    AllInstances.insert("modeleXPRESS_150_4704");
    AllInstances.insert("modeleXPRESS_150_4746");
    AllInstances.insert("modeleXPRESS_150_4788");
    AllInstances.insert("modeleXPRESS_150_4830");
    AllInstances.insert("modeleXPRESS_150_4872");
    AllInstances.insert("modeleXPRESS_150_4914");
    AllInstances.insert("modeleXPRESS_150_4956");
    AllInstances.insert("modeleXPRESS_150_4998");
    AllInstances.insert("modeleXPRESS_150_504");
    AllInstances.insert("modeleXPRESS_150_5040");
    AllInstances.insert("modeleXPRESS_150_5082");
    AllInstances.insert("modeleXPRESS_150_5124");
    AllInstances.insert("modeleXPRESS_150_5166");
    AllInstances.insert("modeleXPRESS_150_5208");
    AllInstances.insert("modeleXPRESS_150_5250");
    AllInstances.insert("modeleXPRESS_150_5292");
    AllInstances.insert("modeleXPRESS_150_5334");
    AllInstances.insert("modeleXPRESS_150_5376");
    AllInstances.insert("modeleXPRESS_150_5418");
    AllInstances.insert("modeleXPRESS_150_546");
    AllInstances.insert("modeleXPRESS_150_5460");
    AllInstances.insert("modeleXPRESS_150_5502");
    AllInstances.insert("modeleXPRESS_150_5544");
    AllInstances.insert("modeleXPRESS_150_5586");
    AllInstances.insert("modeleXPRESS_150_5628");
    AllInstances.insert("modeleXPRESS_150_5670");
    AllInstances.insert("modeleXPRESS_150_5712");
    AllInstances.insert("modeleXPRESS_150_5754");
    AllInstances.insert("modeleXPRESS_150_5796");
    AllInstances.insert("modeleXPRESS_150_5838");
    AllInstances.insert("modeleXPRESS_150_588");
    AllInstances.insert("modeleXPRESS_150_5880");
    AllInstances.insert("modeleXPRESS_150_5922");
    AllInstances.insert("modeleXPRESS_150_5964");
    AllInstances.insert("modeleXPRESS_150_6006");
    AllInstances.insert("modeleXPRESS_150_6048");
    AllInstances.insert("modeleXPRESS_150_6090");
    AllInstances.insert("modeleXPRESS_150_6132");
    AllInstances.insert("modeleXPRESS_150_6174");
    AllInstances.insert("modeleXPRESS_150_6216");
    AllInstances.insert("modeleXPRESS_150_6258");
    AllInstances.insert("modeleXPRESS_150_630");
    AllInstances.insert("modeleXPRESS_150_6300");
    AllInstances.insert("modeleXPRESS_150_6342");
    AllInstances.insert("modeleXPRESS_150_6384");
    AllInstances.insert("modeleXPRESS_150_6426");
    AllInstances.insert("modeleXPRESS_150_6468");
    AllInstances.insert("modeleXPRESS_150_6510");
    AllInstances.insert("modeleXPRESS_150_6552");
    AllInstances.insert("modeleXPRESS_150_6594");
    AllInstances.insert("modeleXPRESS_150_6636");
    AllInstances.insert("modeleXPRESS_150_6678");
    AllInstances.insert("modeleXPRESS_150_672");
    AllInstances.insert("modeleXPRESS_150_6720");
    AllInstances.insert("modeleXPRESS_150_6762");
    AllInstances.insert("modeleXPRESS_150_6804");
    AllInstances.insert("modeleXPRESS_150_6846");
    AllInstances.insert("modeleXPRESS_150_6888");
    AllInstances.insert("modeleXPRESS_150_6930");
    AllInstances.insert("modeleXPRESS_150_6972");
    AllInstances.insert("modeleXPRESS_150_7014");
    AllInstances.insert("modeleXPRESS_150_7056");
    AllInstances.insert("modeleXPRESS_150_7098");
    AllInstances.insert("modeleXPRESS_150_714");
    AllInstances.insert("modeleXPRESS_150_7140");
    AllInstances.insert("modeleXPRESS_150_7182");
    AllInstances.insert("modeleXPRESS_150_7224");
    AllInstances.insert("modeleXPRESS_150_7266");
    AllInstances.insert("modeleXPRESS_150_7308");
    AllInstances.insert("modeleXPRESS_150_7350");
    AllInstances.insert("modeleXPRESS_150_7392");
    AllInstances.insert("modeleXPRESS_150_7434");
    AllInstances.insert("modeleXPRESS_150_7476");
    AllInstances.insert("modeleXPRESS_150_7518");
    AllInstances.insert("modeleXPRESS_150_756");
    AllInstances.insert("modeleXPRESS_150_7560");
    AllInstances.insert("modeleXPRESS_150_7602");
    AllInstances.insert("modeleXPRESS_150_7644");
    AllInstances.insert("modeleXPRESS_150_7686");
    AllInstances.insert("modeleXPRESS_150_7728");
    AllInstances.insert("modeleXPRESS_150_7770");
    AllInstances.insert("modeleXPRESS_150_7812");
    AllInstances.insert("modeleXPRESS_150_7854");
    AllInstances.insert("modeleXPRESS_150_7896");
    AllInstances.insert("modeleXPRESS_150_7938");
    AllInstances.insert("modeleXPRESS_150_798");
    AllInstances.insert("modeleXPRESS_150_7980");
    AllInstances.insert("modeleXPRESS_150_8022");
    AllInstances.insert("modeleXPRESS_150_8064");
    AllInstances.insert("modeleXPRESS_150_8106");
    AllInstances.insert("modeleXPRESS_150_8148");
    AllInstances.insert("modeleXPRESS_150_84");
    AllInstances.insert("modeleXPRESS_150_840");
    AllInstances.insert("modeleXPRESS_150_882");
    AllInstances.insert("modeleXPRESS_150_924");
    AllInstances.insert("modeleXPRESS_150_966");
}
void Instance::Init() {
  if (AllInstances.empty()) {
    addEchantillon(AllInstances);
    //addOther(AllInstances);
    //    for (Instances::const_iterator it(AllInstances.begin());
    //        it != AllInstances.end(); ++it) {
    //      std::cout << "AllInstances.insert(" << "\"" << *it << "\"" << ");"
    //                << std::endl;
    //      std::cout << *it << std::endl;
    //    }
    std::cout << "AllInstances.size() : " << AllInstances.size() << std::endl;
    //    std::exit(0);

  }

}
