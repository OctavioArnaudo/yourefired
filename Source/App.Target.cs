using UnrealBuildTool;
using System.Collections.Generic;

public class YoureFiredTarget : TargetRules
{
	public YoureFiredTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("App");
	}
}
