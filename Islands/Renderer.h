#pragma once

#include "Island.h"

#include <QImage>

namespace Renderer
{
	/// @brief Renders the colored islands of the grid into a QImage which is then returned
	/// @param gridSize The size of the grid the islands have been found in
	/// @param imageSize The size of the resulting QImage
	/// @param islands The colored islands
	QImage render(const QSize& gridSize, const QSize& imageSize, const std::vector<ColoredIsland>& islands);
}
