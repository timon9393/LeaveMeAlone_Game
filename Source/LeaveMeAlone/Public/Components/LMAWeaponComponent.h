// LeaveMeAlone Game by Artem G. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon/LMABaseWeapon.h"
#include "LMAWeaponComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEAVEMEALONE_API ULMAWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULMAWeaponComponent();

	void Fire();
	void Reload();
	void StopFire();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ALMABaseWeapon> WeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName WeaponSocket = "r_Weapon_Socket";

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	UAnimMontage* ReloadMontage;

private:
	UPROPERTY()
	ALMABaseWeapon* Weapon = nullptr;

	void SpawnWeapon();

	bool AnimReloading = false;
	void InitAnimNotify();
	void OnNotifyRealoadFinished(USkeletalMeshComponent* SkeletalMesh);
	bool CanReaload() const;

	void OnCurrentClipEmpty();

	FTimerHandle FireTimerHandle;

//public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
