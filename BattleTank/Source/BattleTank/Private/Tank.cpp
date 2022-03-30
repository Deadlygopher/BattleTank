 // Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{

	auto DamageToApply = FMath::Clamp<float>(DamageAmount, 0, CurrentHealth);
	
	CurrentHealth -= DamageToApply;
	if (CurrentHealth<=0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank DESTROYED !!!"));
	}
	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return CurrentHealth / StartingHealth;
}

/*
*
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	//Super::BeginPlay();
}
*/
