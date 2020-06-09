


#include "MyGameInstance.h"
#include "GameFramework/Character.h"
#include "WindStorm\Save_Load.h"
#include "Kismet\GameplayStatics.h"
#include "Engine\Engine.h"

UMyGameInstance::UMyGameInstance()
{
	Load_Map_Delegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UMyGameInstance::ChangeLevel);
}

void UMyGameInstance::ChangeLevel(UWorld* World)
{
	USave_Load::LoadGame(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
}

void UMyGameInstance::OpenLevel(FName LocName)
{
	UGameplayStatics::OpenLevel(GetWorld(), LocName);
}
