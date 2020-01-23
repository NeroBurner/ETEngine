#include "stdafx.h"
#include "ResourceManager.h"

#include "AssetDatabase.h"


namespace et {
namespace core {


//===================
// Resource Manager
//===================


// static
ResourceManager* ResourceManager::s_Instance = nullptr;


//----------------------------------
// ResourceManager::SetInstance
//
// Initializes the singleton with a derived implementation
//
void ResourceManager::SetInstance(ResourceManager* const instance)
{
	s_Instance = instance;
	s_Instance->Init();
}

//----------------------------------
// ResourceManager::DestroyInstance
//
// Deinitializes the singleton
//
void ResourceManager::DestroyInstance()
{
	s_Instance->Deinit();
	SafeDelete(s_Instance);
}

//----------------------------------
// ResourceManager::SetAssetReferences
//
// Runs the setter function on each asset reference in the DB
//
void ResourceManager::SetAssetReferences(AssetDatabase&db, T_ReferenceAssetGetter const& fnc) const
{
	for (AssetDatabase::AssetCache& cache : db.caches)
	{
		// every asset per cache
		for (I_Asset* asset : cache.cache)
		{
			for (I_Asset::Reference& reference : asset->m_References)
			{
				reference.m_Asset = fnc(GetHash(reference.m_Name));
			}
		}
	}
}


} // namespace core
} // namespace et
