using UnrealBuildTool;
using System.IO;

public class YoureFired : ModuleRules
{
	public YoureFired(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"NavigationSystem",
			"AIModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			ModuleDirectory,
			Path.Combine(ModuleDirectory, "Models"),
			Path.Combine(ModuleDirectory, "Controllers"),
			Path.Combine(ModuleDirectory, "Enemies"),
			Path.Combine(ModuleDirectory, "Environment"),
			Path.Combine(ModuleDirectory, "Items")
		});
	}
}
