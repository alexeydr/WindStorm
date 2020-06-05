

using UnrealBuildTool;
using System.Collections.Generic;

public class WindStormTarget : TargetRules
{
	public WindStormTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "WindStorm" } );
	}
}
