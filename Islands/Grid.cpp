#include "Grid.h"

Grid::Grid(const QSize size)
{
	m_size = size;
	m_data.resize(m_size.width() * m_size.height());
}

void Grid::resize(const QSize size)
{
	m_size = size;
	m_data.resize(m_size.width() * m_size.height());
}

QSize Grid::size() const
{
	return m_size;
}

void Grid::fillRandom(const float probability)
{
	for (int i = 0; i < m_size.width() * m_size.height(); i++)
	{
		const float randomValue = std::rand() / static_cast<float>(RAND_MAX);
		m_data[i] = (randomValue <= probability);
	}
}

bool Grid::get(const QPoint position) const
{
	return m_data[position.y() * m_size.width() + position.x()];
}

void Grid::set(const QPoint position, const bool value)
{
	m_data[position.y() * m_size.width() + position.x()] = value;
}
