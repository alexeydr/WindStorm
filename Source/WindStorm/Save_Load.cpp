


#include "Save_Load.h"
#include "WindStorm\HeroCharacter.h"
#include "WindStorm\AllyCharacter.h"
#include "Engine\Engine.h"
#include "GameFramework/Character.h"
#include "Kismet\GameplayStatics.h"
#include "WindStorm\MySaveGame.h"

void USave_Load::SaveGame(UObject * WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);

	if (UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass())))
	{
		AHeroCharacter* MainChar = Cast<AHeroCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));

		SaveGameInstance->MainCharLocation = MainChar->GetActorLocation();
		SaveGameInstance->MainCharTemp = MainChar->GetTemperature();
		SaveGameInstance->MainCharHealth = MainChar->GetHealth();

		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(World, AHeroCharacter::StaticClass(), FoundActors);
		{
			for (auto Elem : FoundActors)
			{
				if (AHeroCharacter* Char = Cast<AHeroCharacter>(Elem))
				{
					if (Char->CharName == "Ally")
					{
						SaveGameInstance->AllyLocation = Elem->GetActorLocation();
						SaveGameInstance->AllyHealth = Char->GetHealth();
						SaveGameInstance->AllyTemp = Char->GetTemperature();
					}
				}
			}
		}

		UGameplayStatics::SaveGameToSlot(SaveGameInstance, "Save", 0);

	}

}

void USave_Load::LoadGame(UObject * WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	UMySaveGame* LoadedGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("Save", 0));
	if (LoadedGame && World)
	{
		AHeroCharacter* MainChar = Cast<AHeroCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));
		MainChar->SetActorLocation(LoadedGame->MainCharLocation);
		MainChar->SetTemperature(LoadedGame->MainCharTemp);
		MainChar->SetHealth(LoadedGame->MainCharHealth);

		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(World, AHeroCharacter::StaticClass(), FoundActors);
		{
			for (auto Elem : FoundActors)
			{
				if (AHeroCharacter* Char = Cast<AHeroCharacter>(Elem))
				{
					if (Char->CharName == "Ally")
					{
						Elem->SetActorLocation(LoadedGame->AllyLocation);
						Char->SetTemperature(LoadedGame->AllyTemp);
						Char->SetHealth(LoadedGame->AllyHealth);
					}
				}
				
			}
		}

	}

}