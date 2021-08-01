
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterClass.generated.h"

UCLASS()
class MYPROJECT_API ACharacterClass : public ACharacter
{
  GENERATED_BODY()

public:
	ACharacterClass();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	class UCameraComponent* Camera;
	
	UFUNCTION(BlueprintNativeEvent)
	void BP_Jump();
	void BP_Jump_Implementation();

	void Forward_Backward(float Value);
	void Left_Right(float Value);
	void RunSpeed();
	void WalkSpeed();
	void Jumping();
	void Stop_Jumping();
	FRotator CameraRotationYaw;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Default")
	bool JumpingAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	bool CombatMode;
};
