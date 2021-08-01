

#pragma once

#include "CoreMinimal.h"
#include "CharacterClass.h"
#include "Gun.generated.h"

UCLASS()
class MYPROJECT_API AGun : public AActor
{
	GENERATED_BODY()
public:
	AGun();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	class UStaticMeshComponent* GunMesh;

	UFUNCTION(BlueprintCallable,Category="Default")
	void Fire();
	
	AActor* PlayerClass;
	ACharacterClass* MyCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	FName EffectSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Default")
	class UParticleSystem* Effect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Default")
	class UParticleSystem* ImpactEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	TSubclassOf<UDamageType>DamageType;

};












