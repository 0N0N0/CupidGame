// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPlusPlus/CPlusPlusGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPlusPlusGameMode() {}
// Cross Module References
	CPLUSPLUS_API UClass* Z_Construct_UClass_ACPlusPlusGameMode();
	CPLUSPLUS_API UClass* Z_Construct_UClass_ACPlusPlusGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CPlusPlus();
// End Cross Module References
	void ACPlusPlusGameMode::StaticRegisterNativesACPlusPlusGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPlusPlusGameMode);
	UClass* Z_Construct_UClass_ACPlusPlusGameMode_NoRegister()
	{
		return ACPlusPlusGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACPlusPlusGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPlusPlusGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CPlusPlus,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPlusPlusGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPlusPlusGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CPlusPlusGameMode.h" },
		{ "ModuleRelativePath", "CPlusPlusGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPlusPlusGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPlusPlusGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPlusPlusGameMode_Statics::ClassParams = {
		&ACPlusPlusGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPlusPlusGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPlusPlusGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ACPlusPlusGameMode()
	{
		if (!Z_Registration_Info_UClass_ACPlusPlusGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPlusPlusGameMode.OuterSingleton, Z_Construct_UClass_ACPlusPlusGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPlusPlusGameMode.OuterSingleton;
	}
	template<> CPLUSPLUS_API UClass* StaticClass<ACPlusPlusGameMode>()
	{
		return ACPlusPlusGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPlusPlusGameMode);
	ACPlusPlusGameMode::~ACPlusPlusGameMode() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_CPlusPlusGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_CPlusPlusGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPlusPlusGameMode, ACPlusPlusGameMode::StaticClass, TEXT("ACPlusPlusGameMode"), &Z_Registration_Info_UClass_ACPlusPlusGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPlusPlusGameMode), 3726598677U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_CPlusPlusGameMode_h_3327707891(TEXT("/Script/CPlusPlus"),
		Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_CPlusPlusGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_CPlusPlusGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
