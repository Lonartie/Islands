#pragma once
#include <QPoint>
#include <QColor>
#include <unordered_set>

/// @brief Helper class for `std::unordered_set` to work with `QPoint`
template<>
struct std::hash<QPoint>
{
	uint64_t operator()(const QPoint& point) const noexcept;
};

/// @brief An Island is a list of neighboured positions.
struct Island
{
	/// @brief Stores all the associated positions the island is made of
	std::unordered_set<QPoint> positions;
};

/// @brief A helper struct to associate an island with a color
struct ColoredIsland
{
	/// @brief The island itself
	Island island;
	
	/// @brief The associated color for the island
	QColor color;
};
