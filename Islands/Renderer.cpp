#include "Renderer.h"

#include <QPainter>

namespace Renderer
{
	QImage render(const QSize& gridSize, const QSize& imageSize, const std::vector<ColoredIsland>& islands)
	{
		QImage image(imageSize, QImage::Format_RGB888);
		image.fill(Qt::white);

		const float cellWidth = static_cast<float>((imageSize.width())) / gridSize.width();
		const float cellHeight = static_cast<float>((imageSize.height())) / gridSize.height();
		const QSizeF cellSize(cellWidth, cellHeight);

		QPainter painter(&image);

		for (auto& [island, color] : islands)
		{
			painter.setBrush(QBrush(color));
			for (auto& position : island.positions)
			{
				QPointF cellPosition(position.x() * cellSize.toSize().width(), position.y() * cellSize.toSize().height());
				painter.drawRect(QRect(cellPosition.toPoint(), cellSize.toSize()));
			}
		}

		return image;
	}
} // namespace Renderer
