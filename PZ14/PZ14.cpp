// PZ14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ObjectPool.h"


int main()
{
	ObjectPool& op = ObjectPool::GetInstance();
	Item *i1, *i2;
	i1 = op.AcquireItem();
	i2 = op.AcquireItem();

	op.ReleaseItem(i2);
	op.GetStatus();

	op.ReleaseItem(i1);
	op.GetStatus();
    return 0;
}

