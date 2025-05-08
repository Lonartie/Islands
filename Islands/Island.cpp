#include "Island.h"

uint64_t std::hash<QPoint>::operator()(const QPoint& point) const noexcept
{
	// since two int fit inside one uint64_t we shift the x value 32 bits to the left
	// and put the y value to the right side
	return static_cast<uint64_t>(point.x()) << sizeof(int) * 8 | point.y();
}
