// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPlusPlus/NPC.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNPC() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
	CPLUSPLUS_API UClass* Z_Construct_UClass_ANPC();
	CPLUSPLUS_API UClass* Z_Construct_UClass_ANPC_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_CPlusPlus();
// End Cross Module References
	DEFINE_FUNCTION(ANPC::execOnOverlapBegin)
	{
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedActor,Z_Param_OtherActor);
		P_NATIVE_END;
	}
	void ANPC::StaticRegisterNativesANPC()
	{
		UClass* Class = ANPC::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &ANPC::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics
	{
		struct NPC_eventOnOverlapBegin_Parms
		{
			AActor* OverlappedActor;
			AActor* OtherActor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NPC_eventOnOverlapBegin_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NPC_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::NewProp_OverlappedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::NewProp_OtherActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NPC.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANPC, nullptr, "OnOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::NPC_eventOnOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::NPC_eventOnOverlapBegin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANPC_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANPC_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANPC);
	UClass* Z_Construct_UClass_ANPC_NoRegister()
	{
		return ANPC::StaticClass();
	}
	struct Z_Construct_UClass_ANPC_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tree_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Tree;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANPC_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_CPlusPlus,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANPC_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANPC_OnOverlapBegin, "OnOverlapBegin" }, // 3681006589
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANPC_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "NPC.h" },
		{ "ModuleRelativePath", "NPC.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANPC_Statics::NewProp_Tree_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "AI" },
		{ "ModuleRelativePath", "NPC.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANPC_Statics::NewProp_Tree = { "Tree", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANPC, Tree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Statics::NewProp_Tree_MetaData), Z_Construct_UClass_ANPC_Statics::NewProp_Tree_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANPC_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANPC_Statics::NewProp_Tree,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANPC_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANPC>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANPC_Statics::ClassParams = {
		&ANPC::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANPC_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Statics::Class_MetaDataParams), Z_Construct_UClass_ANPC_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANPC()
	{
		if (!Z_Registration_Info_UClass_ANPC.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANPC.OuterSingleton, Z_Construct_UClass_ANPC_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANPC.OuterSingleton;
	}
	template<> CPLUSPLUS_API UClass* StaticClass<ANPC>()
	{
		return ANPC::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANPC);
	ANPC::~ANPC() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_NPC_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_NPC_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANPC, ANPC::StaticClass, TEXT("ANPC"), &Z_Registration_Info_UClass_ANPC, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANPC), 3262114206U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_NPC_h_3051795907(TEXT("/Script/CPlusPlus"),
		Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_NPC_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Engine_5_Unreal_Projects_CPlusPlus_Source_CPlusPlus_NPC_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
