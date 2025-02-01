// LeaveMeAlone Game by Artem G. All Rights Reserved.


#include "Animations/LMAReloadFinishedAnimNotify.h"

void ULMAReloadFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) 
{
	OnNotifyReloadFinished.Broadcast(MeshComp);
	Super::Notify(MeshComp, Animation);
}
