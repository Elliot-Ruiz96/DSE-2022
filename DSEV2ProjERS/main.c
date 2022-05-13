// ---------------------------------------------------------------------------------------------------------------------
// Team:         Ruiz Sanchez, Elliot
//               Lara, Osvaldo
//               Hernandez, Eber      
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:    This software is team Alpha Dinamita property.
//               Duplication or disclosure without team written authorization is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:      Electronic Sensor TM4C129E 
// Language:     ANSI-C
// ---------------------------------------------------------------------------------------------------------------------
// Component:    main
// ---------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Body Identification
//----------------------------------------------------------------------------------------------------------------------
#define HMIGENERICSMDL_C "HMIGENERICSMDL_C"

//----------------------------------------------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//----------------------------------------------------------------------------------------------------------------------
#include "SWC.h"
#include "HMIGenericSMdl.h"

//----------------------------------------------------------------------------------------------------------------------
// Local constants
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local macros
//----------------------------------------------------------------------------------------------------------------------
#define IDLE_STATE          0x00U
#define CLOCK_STATE         0x01U
#define CONFIG_HOURS_STATE  0x02U
#define CONFIG_MINS_STATE   0x03U
#define DIAGNOTIC_STATE     0x04U

//----------------------------------------------------------------------------------------------------------------------
// Local types
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant local data
// ---------------------------------------------------------------------------------------------------------------------

///@brief   HMIGenericSMdl specific initial output data values.
static tHMIGenericSMdl_OutputData const sInitialOutputL =
{
    // tHMIGenericSMdlFuncOutput related initial values
    {
    	0U,
		(boolean)HMI_GENERIC_INACTIVE,
		HMI_GENERIC_INACTIVE
    },
};

//-----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Local function prototypes
//----------------------------------------------------------------------------------------------------------------------

///@brief Final State to display in screeb Logic.
static void Display_Value_Processing(tpHMIGenericSMdl_Context pThis);

//======================================================================================================================
// LOCAL FUNCTIONS
//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
/// @brief    Display Screen Procesing
///
/// @param    tpSWC_Context pCommon - a pointer to the specific context instance
/// @param    tpHMIGenericSMdl_Context pThis - a pointer to the specific context instance
///
/// @return   void
//----------------------------------------------------------------------------------------------------------------------
static void Display_Value_Processing(tpHMIGenericSMdl_Context pThis)
{
	pThis->pSetpoint->FuncOutput.StateActive = IDLE_STATE;
    uint8

	/*Display Screen Functional Logic*/
    switch(pThis->pSetpoint->FuncOutput.StateActive)
    case IDLE_STATE:
        if(FALSE != pThis->pIn->FuncInput.Button1Pressed)
        {
            /* If Button 1 is holded for less than 10 ms */
            AppLib_Is_Timer_Elapsed(fl_psFeatureConfig->ScreenDisplayIdleCounter, fl_psConfig->ScreenDisplayIdleCount, &fl_bTimerStatus);
            if (FALSE != fl_bTimerStatus)
            {
                pThis->pSetpoint->FuncOutput.StateActive = IDLE_STATE;
            }
            else
            {
                /* If Button 1 is holded for less than 800 ms */
                AppLib_Start_Timer(fl_psFeatureConfig->ScreenDisplayClockCounter);
                AppLib_Is_Timer_Elapsed(fl_psFeatureConfig->ScreenDisplayClockCounter, fl_psConfig->ScreenDisplayClockCount, &fl_bTimerStatus);
                if(FALSE != fl_bTimerStatus)
                {
                    pThis->pSetpoint->FuncOutput.StateActive = CLOCK_STATE;
                    AppLib_Start_Timer(fl_psFeatureConfig->ScreenDisplayClock2Counter);
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            /* Do nothing */
        }
        ;
        break;
    case CLOCK_STATE:
        if(FALSE != pThis->pIn->FuncInput.Button1Pressed)
        {
            /* If Button 1 is holded for less than 100 ms */
            AppLib_Is_Timer_Elapsed(fl_psFeatureConfig->ScreenDisplayClock2Counter, fl_psConfig->ScreenDisplayClock2Count, &fl_bTimerStatus);
            if (FALSE != fl_bTimerStatus)
            {
                pThis->pSetpoint->FuncOutput.StateActive = CLOCK_STATE;
            }
            else
            {
                /* If Button 1 is holded for less than 2000 ms */
                AppLib_Start_Timer(fl_psFeatureConfig->ScreenDisplayConfigCounter);
                AppLib_Is_Timer_Elapsed(fl_psFeatureConfig->ScreenDisplayConfigCounter, fl_psConfig->ScreenDisplayConfigCount, &fl_bTimerStatus);
                if(FALSE != fl_bTimerStatus)
                {
                    pThis->pSetpoint->FuncOutput.StateActive = CONFIG_HOURS_STATE;
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            /* Do nothing */
        }
        break;
    case CONFIG_HOURS_STATE:
    break;
    case CONFIG_MINS_STATE:
    break;
    case DIAGNOTIC_STATE:
    break;
    default:
    break;

/* Revision Notes=================================================*/
/**====================================================================================================================================
**     CDSID        Date         Traceability              Description
**====================================================================================================================================
**    eruiz3      30-Apr-2022       1047714       Initial version
**==================================================================================================================================== */
/* end of file =============================================================*/
