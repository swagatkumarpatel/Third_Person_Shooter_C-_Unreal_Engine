
#include "CharacterClass.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharacterClass::ACharacterClass()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	JumpingAnim = false;
	CombatMode = false;
}

void ACharacterClass::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{
		if (CombatMode)
		{ 
			CameraRotationYaw=GetActorRotation();
			CameraRotationYaw.Yaw=Camera->GetComponentRotation().Yaw;
			SetActorRotation(CameraRotationYaw);
		}
	}
}

void ACharacterClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterClass::Jumping);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterClass::StopJumping);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ACharacterClass::RunSpeed);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ACharacterClass::WalkSpeed);
  
	PlayerInputComponent->BindAxis("Forward_Backward", this, &ACharacterClass::Forward_Backward);
	PlayerInputComponent->BindAxis("Left_Right", this, &ACharacterClass::Left_Right);
	//PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);

}

void ACharacterClass::Forward_Backward(float Value)
{
	const FRotator RotationYaw = FRotator(0, Camera->GetComponentRotation().Yaw, 0);
	const FVector Direction = RotationYaw.Vector();
	AddMovementInput(Direction, Value);
}

void ACharacterClass::Left_Right(float Value)
{
	const FRotator RotationYaw = FRotator(0, Camera->GetComponentRotation().Yaw+90, 0);
	const FVector Direction = RotationYaw.Vector();
	AddMovementInput(Direction, Value);
}
void ACharacterClass::RunSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = 600;
}
		
void ACharacterClass::WalkSpeed()											
{
	GetCharacterMovement()->MaxWalkSpeed = 300;
}

void ACharacterClass::Jumping()
{
	BP_Jump();
}

void ACharacterClass::Stop_Jumping()
{
	ACharacter::StopJumping();
}

void ACharacterClass::BP_Jump_Implementation()
{
	if (!CombatMode)
	{
		JumpingAnim = true;
	}
}
