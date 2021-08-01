

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI.generated.h"

UCLASS()
class MYPROJECT_API AAI : public ACharacter
{
	GENERATED_BODY()

public:
	AAI();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
};
