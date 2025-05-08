#include "IslandAlgorithm.h"

#include <deque>

#define USE_RECURSION false

static Island searchIslandRecursive(const QPoint position, const Grid& grid, Island visited = {})
{
	// return if invalid position
	if (position.x() < 0 || position.y() < 0 || position.x() >= grid.size().width() ||
	    position.y() >= grid.size().height())
	{
		return visited;
	}

	// return if field value is false
	if (grid.get(position) == false)
	{
		return visited;
	}

	// return if already visited
	if (visited.positions.find(position) != visited.positions.end())
	{
		return visited;
	}

	visited.positions.emplace(position);

	visited = searchIslandRecursive(position + QPoint(1, 0), grid, visited);
	visited = searchIslandRecursive(position + QPoint(-1, 0), grid, visited);
	visited = searchIslandRecursive(position + QPoint(0, 1), grid, visited);
	visited = searchIslandRecursive(position + QPoint(0, -1), grid, visited);

	return visited;
}

static Island searchIslandLoop(const QPoint position, const Grid& grid)
{
	std::deque toVisit { position };
	Island visited;

	while (!toVisit.empty())
	{
		const QPoint nextPos = toVisit.front();
		toVisit.pop_front();

		if (nextPos.x() < 0 || nextPos.y() < 0 || nextPos.x() >= grid.size().width() || nextPos.y() >= grid.size().height())
		{
			continue;
		}
		if (grid.get(nextPos) == false)
		{
			continue;
		}
		if (visited.positions.find(nextPos) != visited.positions.end())
		{
			continue;
		}

		visited.positions.emplace(nextPos);
		
		toVisit.push_back(nextPos + QPoint(-1, 0));
		toVisit.push_back(nextPos + QPoint(1, 0));
		toVisit.push_back(nextPos + QPoint(0, 1));
		toVisit.push_back(nextPos + QPoint(0, -1));
	}

	return visited;
}

std::vector<Island> Algorithm::searchIslands(const Grid& grid)
{
	std::unordered_set<QPoint> visited;
	std::vector<Island> islands;

	for (int x = 0; x < grid.size().width(); x++)
	{
		for (int y = 0; y < grid.size().height(); y++)
		{
			QPoint position(x, y);

			if (grid.get(position) == false)
			{
				// skip false values
				continue;
			}

			if (visited.find(position) != visited.end())
			{
				// this point has already been identified as part of an island
				continue;
			}

#if USE_RECURSION
			Island island = searchIslandRecursive(QPoint(x, y), grid);
#else
			Island island = searchIslandLoop(QPoint(x, y), grid);
#endif
			visited.insert(island.positions.begin(), island.positions.end());
			islands.push_back(island);
		}
	}

	return islands;
}

QColor interpolate(const QColor& from, const QColor& to, const float percentage)
{
	return QColor(from.red() + (to.red() - from.red()) * percentage,
	   from.green() + (to.green() - from.green()) * percentage, from.blue() + (to.blue() - from.blue()) * percentage);
}

std::vector<ColoredIsland> Algorithm::colorIslands(std::vector<Island> islands, const QColor& from, const QColor& to)
{
	std::vector<ColoredIsland> coloredIslands;
	coloredIslands.reserve(islands.size());

	for (int i = 0; i < islands.size(); i++)
	{
		const float percentage = i / static_cast<float>(islands.size());
		QColor color = interpolate(from, to, percentage);
		coloredIslands.push_back(ColoredIsland{ std::move(islands[i]), std::move(color) });
	}

	return coloredIslands;
}
