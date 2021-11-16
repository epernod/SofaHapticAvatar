/******************************************************************************
* License version                                                             *
*                                                                             *
* Authors:                                                                    *
* Contact information:                                                        *
******************************************************************************/

#include <SofaHapticAvatar/HapticAvatar_ArticulatedDeviceController.h>

namespace sofa::HapticAvatar
{

using namespace sofa::helper::system::thread;

//constructeur
HapticAvatar_ArticulatedDeviceController::HapticAvatar_ArticulatedDeviceController()
    : HapticAvatar_BaseDeviceController()
    , d_toolPosition(initData(&d_toolPosition, "toolPosition", "Output data position of the tool"))    
    , l_forceFeedback(initLink("forceFeedBack", "link to the forceFeedBack component, if not set will search through graph and take first one encountered."))
    , m_forceFeedback(nullptr)
{
    this->f_listening.setValue(true);
}


} // namespace sofa::HapticAvatar
