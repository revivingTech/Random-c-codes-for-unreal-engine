// ---------------------------------------CODE STARTS HERE-----------------------------------------

#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Door.h"



ADoor::ADoor()
{
 	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
    Door->SetupAttachment(Root);

}


void ADoor::BeginPlay()
{
	Super::BeginPlay();
    GetWorldTimerManager().SetTimer(ActionTimerHandle, this, &ADoor::DoorAction, 0.05f, true);	
}

void ADoor::DoorAction()
{
    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (PlayerPawn == nullptr) return;

    FVector TargetLoc = PlayerPawn->GetActorLocation();

    float DetectionDistance = 40; 
	 
    if (FVector::DistSquared(GetActorLocation(), TargetLoc) <= (DetectionDistance * DetectionDistance)) 
             

    {
        Door->SetRelativeLocation(FMath::VInterpTo(Door->GetRelativeLocation(), Location, GetWorld()->GetDeltaSeconds(), Rate));
        Door->SetRelativeRotation(FMath::RInterpTo(Door->GetRelativeRotation(), Rotation, GetWorld()->GetDeltaSeconds(), Rate));

        return;
    
    }

    else
    {
        Door->SetRelativeLocation(FMath::VInterpTo(Door->GetRelativeLocation(), FVector(0.0f, 0.0f, 0.0f), GetWorld()->GetDeltaSeconds(), Rate));
        Door->SetRelativeRotation(FMath::RInterpTo(Door->GetRelativeRotation(), FRotator(0.0f, 0.0f, 0.0f), GetWorld()->GetDeltaSeconds(), Rate));
    }


}
// ---------------------------------------CODE ENDS HERE-----------------------------------------
