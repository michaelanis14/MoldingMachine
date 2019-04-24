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

#include "MoldingMachine.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MoldingMachine_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MoldingMachine, g_nStringIdMoldingMachine)

const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anDataInputNames[] = {g_nStringIdMouldAreaFree};

const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anDataOutputNames[] = {g_nStringIdSTATE, g_nStringIdInPosition_1, g_nStringIdInPosition_2};

const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_MoldingMachine::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_MoldingMachine::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_MoldingMachine::scm_anEOWith[] = {0, 1, 2, 255};
const TForteInt16 FORTE_MoldingMachine::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anEventOutputNames[] = {g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anInternalsNames[] = {g_nStringIdLOGIC};

const CStringDictionary::TStringId FORTE_MoldingMachine::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_MoldingMachine::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_MoldingMachine::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_MoldingMachine::setInitialValues(){
  MouldAreaFree() = false;
  STATE() = "FALSE";
  InPosition_1() = false;
  InPosition_2() = false;
}

void FORTE_MoldingMachine::alg_Molding(void){
STATE() = "Molding";
InPosition_1() = true;
InPosition_2() = false;
}

void FORTE_MoldingMachine::alg_Opening(void){
STATE() = "Opening Completed";
InPosition_1() = false;
InPosition_2() = true;
}

void FORTE_MoldingMachine::alg_Robot(void){
STATE() = "Robot Enters";
InPosition_1() = false;
InPosition_2() = true;
}

void FORTE_MoldingMachine::alg_Closing(void){
STATE() = "Closing Completed";
InPosition_1() = true;
InPosition_2() = false;
}


void FORTE_MoldingMachine::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_MoldingMachine::enterStateRobot(void){
  m_nECCState = scm_nStateRobot;
  alg_Robot();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_MoldingMachine::enterStateOpening(void){
  m_nECCState = scm_nStateOpening;
  alg_Opening();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_MoldingMachine::enterStateMolding(void){
  m_nECCState = scm_nStateMolding;
  alg_Molding();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_MoldingMachine::enterStateClosing(void){
  m_nECCState = scm_nStateClosing;
  alg_Closing();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_MoldingMachine::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventREQID == pa_nEIID) && ((MouldAreaFree())))
          enterStateClosing();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRobot:
        if((scm_nEventREQID == pa_nEIID) && ((MouldAreaFree())))
          enterStateClosing();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOpening:
        if((scm_nEventREQID == pa_nEIID) && ((MouldAreaFree() != true)))
          enterStateRobot();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateMolding:
        if((scm_nEventREQID == pa_nEIID) && ((MouldAreaFree())))
          enterStateOpening();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateClosing:
        if((scm_nEventREQID == pa_nEIID) && ((MouldAreaFree())))
          enterStateMolding();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


