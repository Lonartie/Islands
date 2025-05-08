#include "Presenter.h"
#include "IslandAlgorithm.h"
#include "Renderer.h"
#include <chrono>
#include <algorithm>

Presenter::Presenter(View& view)
   : m_view(view)
   , generator(device())
{
	connect(&view, &View::startPressed, this, &Presenter::start);
	connect(&view, &View::sizeChanged, this, &Presenter::resize);
	connect(&view, &View::startColorSelected, this, &Presenter::setFromColor);
	connect(&view, &View::endColorSelected, this, &Presenter::setToColor);
	connect(&view, &View::probabilityChanged, this, &Presenter::setProbability);
	m_grid.resize(QSize(5, 5));
}

void Presenter::start()
{
	m_grid.fillRandom(m_probability / 100.0f);

	const auto begin = std::chrono::high_resolution_clock::now();
	auto islands = Algorithm::searchIslands(m_grid);
	std::shuffle(islands.begin(), islands.end(), generator);
	const auto coloredIslands = Algorithm::colorIslands(std::move(islands), m_from, m_to);
	const auto end = std::chrono::high_resolution_clock::now();

	const auto delta = end - begin;
	const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(delta).count();
	m_view.setWindowTitle(QString("calculation took: %1 ms").arg(milliseconds));

	auto image = Renderer::render(m_grid.size(), m_view.getContentSize(), coloredIslands);
	m_view.setImage(std::move(image));
}

void Presenter::resize(QSize size)
{
	m_grid.resize(size);
}

void Presenter::setFromColor(QColor color)
{
	m_from = std::move(color);
}

void Presenter::setToColor(QColor color)
{
	m_to = std::move(color);
}

void Presenter::setProbability(int probability)
{
	m_probability = probability;
}
