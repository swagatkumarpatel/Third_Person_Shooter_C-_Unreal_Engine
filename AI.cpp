#include "AI.h"

AAI::AAI()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	
}

void AAI::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

