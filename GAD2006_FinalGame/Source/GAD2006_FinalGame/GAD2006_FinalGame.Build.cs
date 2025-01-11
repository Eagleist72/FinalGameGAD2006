// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAD2006_FinalGame : ModuleRules
{
	public GAD2006_FinalGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
