// LeaveMeAlone Game by Artem G. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Delegates/DelegateCombinations.h"
#include "LMAHealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEAVEMEALONE_API ULMAHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULMAHealthComponent();

	UFUNCTION(BlueprintCallable)
	float GetHealth() { return Health; }

	UFUNCTION(BlueprintCallable)
	bool IsDead() const;

	UPROPERTY(BlueprintAssignable)
	FOnDeathSignature OnDeath;

	FOnHealthChangedSignature OnHealthChanged;

	bool AddHealth(float NewHealth);
	bool IsHealthFull() const;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth = 100.0f;


private:
	float Health = 0.0f;

	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	
		
};
