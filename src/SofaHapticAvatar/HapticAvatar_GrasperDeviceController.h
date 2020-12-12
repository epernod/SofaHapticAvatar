/******************************************************************************
* License version                                                             *
*                                                                             *
* Authors:                                                                    *
* Contact information:                                                        *
******************************************************************************/
#pragma once

#include <SofaHapticAvatar/HapticAvatar_ArticulatedDeviceController.h>
#include <SofaHapticAvatar/HapticAvatar_IBoxController.h>
#include <sofa/core/collision/NarrowPhaseDetection.h>

namespace sofa::HapticAvatar
{

using namespace sofa::defaulttype;

// Set class to store Jaws Data information instead of struct so in the future could have a hiearchy of different tools.
class SOFA_HAPTICAVATAR_API HapticAvatarJaws
{
public:
    HapticAvatarJaws();


public:
    float m_MaxOpeningAngle;
    float m_jawLength;
    float m_jaw1Radius;
    float m_jaw2Radius;
    float m_shaftRadius;
};


/**
* Haptic Avatar driver
*/
class SOFA_HAPTICAVATAR_API HapticAvatar_GrasperDeviceController : public HapticAvatar_ArticulatedDeviceController
{
public:
    SOFA_CLASS(HapticAvatar_GrasperDeviceController, HapticAvatar_ArticulatedDeviceController);
    typedef helper::vector<core::collision::DetectionOutput> ContactVector;

    /// Default constructor
    HapticAvatar_GrasperDeviceController();

    /// handleEvent component method to catch collision info
    void handleEvent(core::objectmodel::Event *) override;
    
    /// General Haptic thread methods
    static void Haptics(std::atomic<bool>& terminate, void * p_this, void * p_driver);

    /// Thread methods to cpy data from m_hapticData to m_simuData
    static void CopyData(std::atomic<bool>& terminate, void * p_this);

protected:
    /// Internal method to init specific collision components
    void initImpl() override;

    /// override method to create the different threads
    bool createHapticThreads() override;

    /// override method to update specific tool position
    void updatePositionImpl() override;

    /// Internal method to draw specific informations
    void drawImpl(const sofa::core::visual::VisualParams*) override {}

public:
    /// link to the IBox controller component 
    SingleLink<HapticAvatar_GrasperDeviceController, HapticAvatar_IBoxController, BaseLink::FLAG_STOREPATH | BaseLink::FLAG_STRONGLINK> l_iboxCtrl;

protected:
    /// Pointer to the IBoxController component
    HapticAvatar_IBoxController * m_iboxCtrl;

    /// Jaws specific informations
    HapticAvatarJaws m_jawsData;
};

} // namespace sofa::HapticAvatar
