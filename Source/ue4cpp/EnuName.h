#include "UObject/ObjectMacros.h"
UENUM(BlueprintType)
enum Status
{
	Stopped UMETA(DisplayName = "Stopped"),
	Moving UMETA(DisplayName = "Moving"),
	Attacking UMETA(DisplayName = "Attacking"),
};

