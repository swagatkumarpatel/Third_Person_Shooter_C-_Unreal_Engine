

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class MYPROJECT_API AFloor : public AActor
{
	GENERATED_BODY()

protected:
	 AFloor();
	 virtual void Tick(float DeltaTime) override;
	 virtual void BeginPlay() override;
 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	class UStaticMeshComponent* Floor;

	UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
  

};
