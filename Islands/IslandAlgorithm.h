#pragma once

#include "Grid.h"
#include "Island.h"

#include <vector>
#include <QColor>

namespace Algorithm
{
	/// @brief Searches all available islands in the given grid
	std::vector<Island> searchIslands(const Grid& grid);

	/// @brief Colors the \a islands by interpolating between \a from and \a to
	std::vector<ColoredIsland> colorIslands(
		std::vector<Island> islands, 
		const QColor& from = Qt::yellow, 
		const QColor& to = Qt::darkMagenta
	);
	
} // namespace Algorithm
