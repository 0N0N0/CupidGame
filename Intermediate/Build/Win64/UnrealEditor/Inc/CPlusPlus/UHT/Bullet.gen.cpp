// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPlusPlus/Bullet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBullet() {}
// Cross Module References
	CPLUSPLUS_API UClass* Z_Construct_UClass_ABullet();
	CPLUSPLUS_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CPlusPlus();
// End Cross Module References
	void ABullet::StaticRegisterNativesABullet()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABullet);
	UClass* Z_Construct_UClass_ABullet_NoRegister()
	{
		return ABullet::StaticClass();
	}
	struct Z_Construct_UClass_ABullet_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABullet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CPlusPlus,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABullet_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Bullet.h" },
		{ "ModuleRelativePath", "Bullet.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABullet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABullet>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABullet_Statics::ClassParams = {
		&ABullet::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::Class_MetaDataParams), Z_Construct_UClass_ABullet_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ABullet()
	{
		if (!Z_Registration_Info_UClass_ABullet.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABullet.OuterSingleton, Z_Construct_UClass_ABullet_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABullet.OuterSingleton;
	}
	template<> CPLUSPLUS_API UClass* StaticClass<ABullet>()
	{
		return ABullet::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABullet);
	ABullet::~ABullet() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_Bullet_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_Bullet_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABullet, ABullet::StaticClass, TEXT("ABullet"), &Z_Registration_Info_UClass_ABullet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABullet), 3464086605U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_Bullet_h_2158211247(TEXT("/Script/CPlusPlus"),
		Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_Bullet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_Bullet_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
