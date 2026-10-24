using UnrealBuildTool;
using System.Collections.Generic;

public class YoureFiredEditorTarget : TargetRules
{
	public YoureFiredEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("YoureFired");
	}
}
