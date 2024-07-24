// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPlusPlus/MyAnimInstance.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyAnimInstance() {}
// Cross Module References
	CPLUSPLUS_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
	CPLUSPLUS_API UClass* Z_Construct_UClass_UMyAnimInstance();
	CPLUSPLUS_API UClass* Z_Construct_UClass_UMyAnimInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_CPlusPlus();
// End Cross Module References
	void UMyAnimInstance::StaticRegisterNativesUMyAnimInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyAnimInstance);
	UClass* Z_Construct_UClass_UMyAnimInstance_NoRegister()
	{
		return UMyAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMyAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Character_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsInAir_MetaData[];
#endif
		static void NewProp_bIsInAir_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInAir;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsInputAccelerating_MetaData[];
#endif
		static void NewProp_bIsInputAccelerating_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInputAccelerating;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsShooting_MetaData[];
#endif
		static void NewProp_bIsShooting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsShooting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsJumping_MetaData[];
#endif
		static void NewProp_bIsJumping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsJumping;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_CPlusPlus,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "MyAnimInstance.h" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Character_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Character" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyAnimInstance, Character), Z_Construct_UClass_AMyCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Character_MetaData), Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Character_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyAnimInstance, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed_MetaData), Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->bIsInAir = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir = { "bIsInAir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir_MetaData), Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->bIsInputAccelerating = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating = { "bIsInputAccelerating", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating_MetaData), Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->bIsShooting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting = { "bIsShooting", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting_MetaData), Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MyAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping_SetBit(void* Obj)
	{
		((UMyAnimInstance*)Obj)->bIsJumping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping = { "bIsJumping", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMyAnimInstance), &Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping_MetaData), Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Character,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInAir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsInputAccelerating,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsShooting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyAnimInstance_Statics::NewProp_bIsJumping,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyAnimInstance_Statics::ClassParams = {
		&UMyAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyAnimInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyAnimInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMyAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UMyAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyAnimInstance.OuterSingleton, Z_Construct_UClass_UMyAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyAnimInstance.OuterSingleton;
	}
	template<> CPLUSPLUS_API UClass* StaticClass<UMyAnimInstance>()
	{
		return UMyAnimInstance::StaticClass();
	}
	UMyAnimInstance::UMyAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyAnimInstance);
	UMyAnimInstance::~UMyAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyAnimInstance, UMyAnimInstance::StaticClass, TEXT("UMyAnimInstance"), &Z_Registration_Info_UClass_UMyAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyAnimInstance), 3572413220U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyAnimInstance_h_3346962915(TEXT("/Script/CPlusPlus"),
		Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
