/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MoldingMachine
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2019-03-27/michael - null - 
 *************************************************************************/

#ifndef _MOLDINGMACHINE_H_
#define _MOLDINGMACHINE_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>

class FORTE_MoldingMachine: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_MoldingMachine)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &MouldAreaFree() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &STATE() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_BOOL &InPosition_1() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &InPosition_2() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &LOGIC() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 3, 1, 0);

virtual void setInitialValues();
  void alg_Molding(void);
  void alg_Opening(void);
  void alg_Robot(void);
  void alg_Closing(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateRobot = 1;
  static const TForteInt16 scm_nStateOpening = 2;
  static const TForteInt16 scm_nStateMolding = 3;
  static const TForteInt16 scm_nStateClosing = 4;

  void enterStateSTART(void);
  void enterStateRobot(void);
  void enterStateOpening(void);
  void enterStateMolding(void);
  void enterStateClosing(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_MoldingMachine(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_MoldingMachine(){};

};

#endif //close the ifdef sequence from the beginning of the file

