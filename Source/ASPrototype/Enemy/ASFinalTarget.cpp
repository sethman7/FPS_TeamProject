// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/ASFinalTarget.h"
#include "Game/ASGameMode.h"
#include "Animation/ASAIAnimInstance.h"
AASFinalTarget::AASFinalTarget()
{

}

void AASFinalTarget::SetDead()
{

	const float DelayTime = PlayAnimMontage(BossDeathMontage);
	if (CurGameMode)
	{
		CurGameMode->IsEscape = true;
		CurGameMode->EscapeTimerStart();
	}
	Destroy();
	//FTimerHandle myTimerHandle;
	//GetWorld()->GetTimerManager().SetTimer(myTimerHandle, FTimerDelegate::CreateLambda([&]()
	//	{
	//	}), DelayTime - 0.5, false);
	//Super::SetDead();
}

void AASFinalTarget::BeginPlay()
{
	Super::BeginPlay();
	CurGameMode = Cast<AASGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}
