


#include "InteractActor.h"
#include "Kismet\GameplayStatics.h"
#include "WindStorm\HeroCharacter.h"
#include "Components\BoxComponent.h"
#include "Components\StaticMeshComponent.h"

// Sets default values
AInteractActor::AInteractActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>(FName("BoxComp"));
	BoxComp->SetupAttachment(GetRootComponent());
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComp"));
	StaticMesh->SetupAttachment(BoxComp);
}

void AInteractActor::OnBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	this->OnBeginOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AInteractActor::OnEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	this->OnEndOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}

void AInteractActor::OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AHeroCharacter * Char = Cast<AHeroCharacter>(OtherActor);
	if (Char)
	{
		Char->InteractActor = this;
	}
}

void AInteractActor::OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	AHeroCharacter * Char = Cast<AHeroCharacter>(OtherActor);
	if (Char)
	{
		Char->InteractActor = nullptr;
	}
}

// Called when the game starts or when spawned
void AInteractActor::BeginPlay()
{
	Super::BeginPlay();
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AInteractActor::OnBegin);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AInteractActor::OnEnd);
	MainChar = Cast<AHeroCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

