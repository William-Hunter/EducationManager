#include "stdafx.h"
#include "ExChange.h"


ExChange::ExChange(void)
{
}


ExChange::~ExChange(void)
{
}

void ExChange::Clean(void)
{
	borad=0;
	computer=0;
	ID=0;
	project=0;
	seat=0;
	FLAG=FALSE;
}

void ExChange::Set(long theID,long theseat,long thecomputer,long theborad,long theproject)
{
	ID=theID;
	seat=theseat;
	computer=thecomputer;
	borad=theborad;
	project=theproject;
}




