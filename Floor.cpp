
#include "Floor.h"
#include "Components/StaticMeshComponent.h"
#include "CharacterClass.h"


AFloor::AFloor()
{

	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	Floor->SetupAttachment(RootComponent);
	
}
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	Floor->OnComponentHit.AddDynamic(this, &AFloor::OnHit);

}

void AFloor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACharacterClass* Player = Cast<ACharacterClass>(OtherActor);
	{
		if (Player)
		{
			Player->JumpingAnim = false;
			
		}
	}
}


void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

