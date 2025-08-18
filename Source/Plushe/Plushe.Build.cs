// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Plushe : ModuleRules
{
	public Plushe(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GameplayTasks", "NavigationSystem", "UMG", "AIModule" });
	}
}
