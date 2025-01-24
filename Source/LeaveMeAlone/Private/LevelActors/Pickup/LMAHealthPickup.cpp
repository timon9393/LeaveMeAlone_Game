// LeaveMeAlone Game by Artem G. All Rights Reserved.


#include "LevelActors/Pickup/LMAHealthPickup.h"
#include "Player/LMADefaultCharacter.h"
#include "Components/LMAHealthComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ALMAHealthPickup::ALMAHealthPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	//
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetRootComponent(SphereComponent);

}

// Called when the game starts or when spawned
void ALMAHealthPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALMAHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ALMAHealthPickup::GivePickup(ALMADefaultCharacter* Character)
{
	const auto HealthComponent = Character->GetHealthComponent();

	if (!HealthComponent)
		return false;
	
	return HealthComponent->AddHealth(HealthFromPickup);
}

void ALMAHealthPickup::PickupWasTaken()
{
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetRootComponent()->SetVisibility(false, true);

	FTimerHandle RespawnTimerHandle;
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ALMAHealthPickup::RespawnPickup, RespawnTime);
}

void ALMAHealthPickup::RespawnPickup() 
{
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	GetRootComponent()->SetVisibility(true, true);
}

void ALMAHealthPickup::NotifyActorBeginOverlap(AActor* OtherActor) 
{
	Super::NotifyActorBeginOverlap(OtherActor);
	const auto Character = Cast<ALMADefaultCharacter>(OtherActor);
	if (GivePickup(Character))
	{
		PickupWasTaken();
	}
}
