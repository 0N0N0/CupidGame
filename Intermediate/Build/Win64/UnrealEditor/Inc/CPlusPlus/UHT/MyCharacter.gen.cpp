// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPlusPlus/MyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacter() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	CPLUSPLUS_API UClass* Z_Construct_UClass_AMyCharacter();
	CPLUSPLUS_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CPlusPlus();
// End Cross Module References
	DEFINE_FUNCTION(AMyCharacter::execSpawnActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnActor();
		P_NATIVE_END;
	}
	void AMyCharacter::StaticRegisterNativesAMyCharacter()
	{
		UClass* Class = AMyCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnActor", &AMyCharacter::execSpawnActor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyCharacter_SpawnActor_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_SpawnActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_SpawnActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "SpawnActor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_SpawnActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyCharacter_SpawnActor_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AMyCharacter_SpawnActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyCharacter_SpawnActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyCharacter);
	UClass* Z_Construct_UClass_AMyCharacter_NoRegister()
	{
		return AMyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actorBPToSpawn_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_actorBPToSpawn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsJumping_MetaData[];
#endif
		static void NewProp_IsJumping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsJumping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsShooting_MetaData[];
#endif
		static void NewProp_IsShooting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsShooting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShootAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShootingMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootingMontage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_CPlusPlus,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyCharacter_SpawnActor, "SpawnActor" }, // 718357393
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyCharacter.h" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_actorBPToSpawn_MetaData[] = {
		{ "Category", "MyCharacter" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_actorBPToSpawn = { "actorBPToSpawn", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, actorBPToSpawn), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_actorBPToSpawn_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_actorBPToSpawn_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->IsJumping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping = { "IsJumping", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Action" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->IsShooting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting = { "IsShooting", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootAction_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootingMontage_MetaData[] = {
		{ "Category", "Animation montage" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootingMontage = { "ShootingMontage", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, ShootingMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootingMontage_MetaData), Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootingMontage_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_actorBPToSpawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsJumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_IsShooting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_ShootingMontage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyCharacter_Statics::ClassParams = {
		&AMyCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AMyCharacter()
	{
		if (!Z_Registration_Info_UClass_AMyCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyCharacter.OuterSingleton, Z_Construct_UClass_AMyCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyCharacter.OuterSingleton;
	}
	template<> CPLUSPLUS_API UClass* StaticClass<AMyCharacter>()
	{
		return AMyCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacter);
	AMyCharacter::~AMyCharacter() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyCharacter, AMyCharacter::StaticClass, TEXT("AMyCharacter"), &Z_Registration_Info_UClass_AMyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyCharacter), 4000953897U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyCharacter_h_302767832(TEXT("/Script/CPlusPlus"),
		Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_MyCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
