#pragma once

#include <EtCore/Content/AssetStub.h>
#include <EtCore/Reflection/registerMath.h>
#include <EtRendering/GraphicsTypes/Shader.h>
#include <EtRendering/GraphicsTypes/Mesh.h>
#include <EtRendering/GraphicsTypes/EnvironmentMap.h>
#include <EtRendering/GraphicsTypes/SpriteFont.h>
#include <EtRendering/GraphicsTypes/TextureData.h>
#include <EtRendering/MaterialSystem/MaterialData.h>
#include <EtRendering/MaterialSystem/MaterialInstance.h>
#include <EtRendering/GraphicsTypes/PostProcessingSettings.h>


namespace et {
namespace render {


//---------------------------------
// ForceLinking
//
// Add classes here that the linker thinks wouldn't be used by this project but are in fact used by reflection
//
void ForceLinking()
{
	core::FORCE_LINKING(StubAsset)
	FORCE_LINKING(ShaderAsset)
	FORCE_LINKING(MeshAsset)
	FORCE_LINKING(MaterialAsset)
	FORCE_LINKING(MaterialInstanceAsset)
	FORCE_LINKING(EnvironmentMapAsset)
	FORCE_LINKING(FontAsset)
	FORCE_LINKING(TextureAsset)
	core::FORCE_LINKING(MathRegistrationLinkEnforcer)
	FORCE_LINKING(PostProcessingSettings)
}


} // namespace render
} // namespace et
