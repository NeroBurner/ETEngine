#pragma once
#include <EtCore/Helper/LinkerUtils.h>

#include <EtFramework/SceneGraph/ComponentDescriptor.h>


namespace demo {


//---------------------------------
// ControledLightComponent
//
// Tag component that marks a light for rotation and brightness controlls
//
struct ControledLightComponent final
{
	ECS_DECLARE_COMPONENT
};


//---------------------------------
// ControledLightComponentDesc
//
// Serialize / Deserialize
//
class ControledLightComponentDesc final : public fw::ComponentDescriptor<ControledLightComponent>
{
	// definitions
	//-------------
	RTTR_ENABLE(ComponentDescriptor<ControledLightComponent>)
	DECLARE_FORCED_LINKING()

	// construct destruct
	//--------------------
public:
	ControledLightComponentDesc() : ComponentDescriptor<ControledLightComponent>() {}

	// ComponentDescriptor interface
	//-------------------------------
	ControledLightComponent* MakeData() override;
};


} // namespace demo

