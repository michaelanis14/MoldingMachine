/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Robot
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2019-04-03/michael - null - 
 *************************************************************************/

#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <forte_int.h>

class FORTE_Robot: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Robot)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &InPosition_1() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &InPosition_2() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &STATE() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_BOOL &MouldAreaFree() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_INT &EnableMovement() {
    return *static_cast<CIEC_INT*>(getDO(2));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 2, 3, 0, 0);

virtual void setInitialValues();
  void alg_Move_In_ALG(void);
  void alg_Move_Out_ALG(void);
  void alg_Grap_ALG(void);
  void alg_Release_ALG(void);
  void alg_Ready_ALG(void);
  static const TForteInt16 scm_nStateStart = 0;
  static const TForteInt16 scm_nStateMove_In = 1;
  static const TForteInt16 scm_nStateGrap = 2;
  static const TForteInt16 scm_nStateMove_Out = 3;
  static const TForteInt16 scm_nStateRelease = 4;
  static const TForteInt16 scm_nStateReady = 5;

  void enterStateStart(void);
  void enterStateMove_In(void);
  void enterStateGrap(void);
  void enterStateMove_Out(void);
  void enterStateRelease(void);
  void enterStateReady(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Robot(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Robot(){};

};

#endif //close the ifdef sequence from the beginning of the file

