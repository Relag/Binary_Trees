#include "Item.h"

bool Item::operator==(Item& pickup) {
	return pickup.GetName() == m_Name;
}
