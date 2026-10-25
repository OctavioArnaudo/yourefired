using UnrealBuildTool;
using System.IO;

public class App : ModuleRules
{
	public App(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"NavigationSystem",
			"AIModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		var includePaths = new System.Collections.Generic.List<string> { ModuleDirectory };
		foreach (var subDir in new string[] { "Models", "Controllers", "Services", "Views", "Interfaces", "Enemies", "Environment", "Items" })
		{
			var fullPath = Path.Combine(ModuleDirectory, subDir);
			if (Directory.Exists(fullPath))
			{
				includePaths.Add(fullPath);
			}
		}
		PublicIncludePaths.AddRange(includePaths);
	}
}
