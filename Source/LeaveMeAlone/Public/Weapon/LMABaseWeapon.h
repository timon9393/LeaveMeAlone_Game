// LeaveMeAlone Game by Artem G. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMABaseWeapon.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnEmptyClipSignature);

USTRUCT(BlueprintType)
struct FAmmoWeapon
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Bullets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Clips;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool Infinite;
};

UCLASS()
class LEAVEMEALONE_API ALMABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALMABaseWeapon();

	void Fire();

	void ChangeClip();

	FOnEmptyClipSignature OnEmptyClip;

	bool IsCurrentClipFull() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireRate = 0.1f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh;

	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TraceDistance = 800.0f;

	void Shoot();

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName MuzzleSocket = "Muzzle";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FAmmoWeapon DefaultAmmoWeapon {30, 0, true};

	void DecrementBullets();
	bool IsCurrentClipEmpty() const;
	

	

private:
	FAmmoWeapon CurrentAmmoWeapon;
	FTimerHandle FireTimerHandle;


public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
