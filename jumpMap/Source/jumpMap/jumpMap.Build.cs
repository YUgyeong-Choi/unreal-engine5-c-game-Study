// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class jumpMap : ModuleRules
{
	public jumpMap(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"jumpMap",
			"jumpMap/Variant_Platforming",
			"jumpMap/Variant_Platforming/Animation",
			"jumpMap/Variant_Combat",
			"jumpMap/Variant_Combat/AI",
			"jumpMap/Variant_Combat/Animation",
			"jumpMap/Variant_Combat/Gameplay",
			"jumpMap/Variant_Combat/Interfaces",
			"jumpMap/Variant_Combat/UI",
			"jumpMap/Variant_SideScrolling",
			"jumpMap/Variant_SideScrolling/AI",
			"jumpMap/Variant_SideScrolling/Gameplay",
			"jumpMap/Variant_SideScrolling/Interfaces",
			"jumpMap/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
