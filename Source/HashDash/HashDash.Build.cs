// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HashDash : ModuleRules
{
	public HashDash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule" });
        PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Slate", "SlateCore" });
    }
}
