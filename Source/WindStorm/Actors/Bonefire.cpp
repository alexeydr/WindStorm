


#include "Bonefire.h"
#include "WindStorm\HeroCharacter.h"
#include "TimerManager.h"
#include "Stick.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine\World.h"

void ABonefire::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle FuzeTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &ABonefire::OnWarm, 0.5, true);

	GetWorld()->GetTimerManager().SetTimer(BurnHandle, this, &ABonefire::OnLifetimeComplete, Lifetime, false);
}

void ABonefire::OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::OnBeginOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	AHeroCharacter* Char = Cast<AHeroCharacter>(OtherActor);
	if (Char)
	{
		Chars.Add(Char);
	}
	this->ShowTime();
}

void ABonefire::OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	Super::OnEndOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
	
	AHeroCharacter* Char = Cast<AHeroCharacter>(OtherActor);
	if (Char)
	{
		Chars.Remove(Char);
	}
	this->ShowTime();
}


void ABonefire::OnWarm()
{
	for (auto Elem: Chars)
	{
		Elem->AddTemperature(4.f);
	}
}

void ABonefire::OnLifetimeComplete()
{
	if (WidgetRef)
	{
		APlayerController* PC = Cast<APlayerController>(MainChar->GetController());
		if (PC)
		{
			PC->bShowMouseCursor = false;
		}
		WidgetRef->RemoveFromParent();
	}
	this->Destroy();
}

void ABonefire::OnAddStick(float Time)
{
	float Remaining = GetWorld()->GetTimerManager().GetTimerRemaining(BurnHandle);
	Remaining += Time;

	Lifetime = Remaining;
	GetWorld()->GetTimerManager().SetTimer(BurnHandle, this, &ABonefire::OnLifetimeComplete, Lifetime, false);
	
	this->ShowTime();
	this->ShowTime();

}

void ABonefire::ActionOnInteract()
{
	Super::ActionOnInteract();


	APlayerController* PC = Cast<APlayerController>(MainChar->GetController());
	if (PC && UI_Class && StickInInvUI)
	{

		WidgetRef = CreateWidget<UBonefire_UI>(GetWorld(), UI_Class);

		if (WidgetRef)
			WidgetRef->AddToViewport();
		else
			return;

		WidgetRef->Owner = this;

		for (auto Elem:MainChar->Inventory)
		{
			AStick* Stick = Cast<AStick>(Elem);
			if (Stick)
			{
				WidgetRef->AddItems(Stick, StickInInvUI);
			}
		}

		PC->bShowMouseCursor = true;
		UWidgetBlueprintLibrary::SetInputMode_UIOnly(PC, WidgetRef);
	}


}
