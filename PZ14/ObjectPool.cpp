#include "stdafx.h"
#include "ObjectPool.h"
#include "Item.h"
#include <list>
#include <iostream>

std::list<Item*> ObjectPool::_items = std::list<Item *>();

ObjectPool::~ObjectPool()
{
	for (Item* item : _items)
		delete item;
}

ObjectPool& ObjectPool::GetInstance()
{
	static ObjectPool instance;
	return instance;
}

Item* ObjectPool::AcquireItem()
{
	Item* item;
	if (!_items.empty())
	{
		 item = _items.front();
		_items.pop_front();
	}
	else
	{
		item = new Item;
	}
	return item;
}

void ObjectPool::ReleaseItem(Item* item)
{
	_items.push_back(item);
}

void ObjectPool::GetStatus()
{
	std::cout << "There is(are) " << _items.size() << " item(s) in pool.\n";
}
