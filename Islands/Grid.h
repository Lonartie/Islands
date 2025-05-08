#pragma once

#include <QPoint>
#include <vector>
#include <QSize>

class Grid
{
public:
	Grid() = default;
	Grid(QSize size);

	/// @brief Resizes the grid to the new \a size
	void resize(QSize size);

	/// @brief Returns the size of the grid 
	QSize size() const;

	/// @brief Fills the grid with random values (true / false)
	/// @param probability The probability of 'true' values
	void fillRandom(float probability = 0.5f);

	/// @brief Retrieves the value at the specified \a position 
	bool get(QPoint position) const;

	/// @brief Sets the \a value at the specified \a position
	void set(QPoint position, bool value);

private:
	std::vector<bool> m_data;
	QSize m_size;
};
