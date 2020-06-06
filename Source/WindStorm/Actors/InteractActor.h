

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractActor.generated.h"

UCLASS()
class WINDSTORM_API AInteractActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractActor();

	virtual void ActionOnInteract() {};

protected:

	class UBoxComponent* BoxComp;

	class AHeroCharacter* MainChar;

	UPROPERTY(EditDefaultsOnly)
		FVector BoxEx = FVector(20, 20, 20);

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;


	UFUNCTION()
		virtual	void OnBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		virtual void OnEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);

	virtual  void OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
