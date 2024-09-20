if ["$1" = "--gz"]; then
~/UnrealEngine/Engine/Binaries/Linux/UnrealEditor ~/repos/Colosseum/Unreal/Environments/Blocks/Blocks.uproject -settings='~/repos/Colosseum/gz-settings.json'

else
~/UnrealEngine/Engine/Binaries/Linux/UnrealEditor ~/repos/Colosseum/Unreal/Environments/Blocks/Blocks.uproject -settings='~/repos/Colosseum/settings.json'

fi