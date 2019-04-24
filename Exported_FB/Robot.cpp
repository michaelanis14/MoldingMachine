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

#include "Robot.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Robot_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Robot, g_nStringIdRobot)

const CStringDictionary::TStringId FORTE_Robot::scm_anDataInputNames[] = {g_nStringIdInPosition_1, g_nStringIdInPosition_2};

const CStringDictionary::TStringId FORTE_Robot::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Robot::scm_anDataOutputNames[] = {g_nStringIdSTATE, g_nStringIdMouldAreaFree, g_nStringIdEnableMovement};

const CStringDictionary::TStringId FORTE_Robot::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdINT};

const TForteInt16 FORTE_Robot::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_Robot::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_Robot::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_Robot::scm_anEOWith[] = {1, 2, 0, 255};
const TForteInt16 FORTE_Robot::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_Robot::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_Robot::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_Robot::setInitialValues(){
  MouldAreaFree() = false;
  EnableMovement() = 3;
}

void FORTE_Robot::alg_Move_In_ALG(void){
STATE() = "MOVE_IN";
MouldAreaFree() = false;
EnableMovement() = 1;

}

void FORTE_Robot::alg_Move_Out_ALG(void){
STATE() = "MOVE_OUT";
MouldAreaFree() = true;
EnableMovement() = 3;
}

void FORTE_Robot::alg_Grap_ALG(void){
STATE() = "GRAP";
MouldAreaFree() = false;
EnableMovement() = 1;
}

void FORTE_Robot::alg_Release_ALG(void){
STATE() = "Release";
MouldAreaFree() = true;
EnableMovement() = 3;
}

void FORTE_Robot::alg_Ready_ALG(void){
STATE() = "Ready";
MouldAreaFree() = true;
EnableMovement() = 0;
}


void FORTE_Robot::enterStateStart(void){
  m_nECCState = scm_nStateStart;
}

void FORTE_Robot::enterStateMove_In(void){
  m_nECCState = scm_nStateMove_In;
  alg_Move_In_ALG();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Robot::enterStateGrap(void){
  m_nECCState = scm_nStateGrap;
  alg_Grap_ALG();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Robot::enterStateMove_Out(void){
  m_nECCState = scm_nStateMove_Out;
  alg_Move_Out_ALG();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Robot::enterStateRelease(void){
  m_nECCState = scm_nStateRelease;
  alg_Release_ALG();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Robot::enterStateReady(void){
  m_nECCState = scm_nStateReady;
  alg_Ready_ALG();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Robot::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateStart:
        if(1)
          enterStateReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateMove_In:
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2())))
          enterStateGrap();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGrap:
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2())))
          enterStateMove_Out();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateMove_Out:
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2())))
          enterStateRelease();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRelease:
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2())))
          enterStateMove_In();
        else
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2() != true)))
          enterStateReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReady:
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2())))
          enterStateMove_In();
        else
        if((scm_nEventREQID == pa_nEIID) && ((InPosition_2() != true)))
          enterStateReady();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


