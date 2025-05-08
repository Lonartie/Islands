#pragma once
#include "Grid.h"
#include "View.h"

#include <random>

class Presenter : public QObject
{
	Q_OBJECT

public:
	Presenter(View& view);

private slots:
	/// @brief Fills the grid with random values, searches for islands and renders the
	/// resulting image to the view
	void start();

	/// @brief Resizes the internal grid
	void resize(QSize size);

	/// @brief Sets the start color for interpolating islands colors
	void setFromColor(QColor color);
	
	/// @brief Sets the end color for interpolating islands colors
	void setToColor(QColor color);

	/// @brief Sets the probability of '1' or 'true' being generated when
	/// filling the grid with random values
	void setProbability(int probability);

private:
	View& m_view;
	Grid m_grid;
	QColor m_from = Qt::yellow;
	QColor m_to = Qt::darkMagenta;
	int m_probability = 50;
	std::random_device device;
	std::mt19937 generator;
};
