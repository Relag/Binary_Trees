#include "Item.h"

bool Item::operator==(Item& pickUp) {
	
	 return pickUp.GetName() == m_sName;
}