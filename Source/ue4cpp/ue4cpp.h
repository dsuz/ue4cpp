// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#define LOCTEXT_NAMESPACE "TestNamespace"
#define FTEXT(x) LOCTEXT(x, x)
extern FName LoggerName;
DECLARE_LOG_CATEGORY_EXTERN(LogCh11, Log, All)
void CreateLog(FName LogName);