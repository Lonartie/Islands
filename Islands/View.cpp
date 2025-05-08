#include "View.h"
#include <QColorDialog>

static QString BackgroundColorTemplate = "background-color: rgb(%1,%2,%3);";

View::View(QWidget* parent)
   : QMainWindow(parent)
{
	m_ui.setupUi(this);

	connect(m_ui.fromSelect, &QPushButton::pressed, this, &View::selectStartColor);
	connect(m_ui.toSelect, &QPushButton::pressed, this, &View::selectEndColor);
	connect(m_ui.startButton, &QPushButton::pressed, this, &View::startPressed);
	connect(m_ui.widthSpinBox, qOverload<int>(&QSpinBox::valueChanged), this, &View::changeSize);
	connect(m_ui.heightSpinBox, qOverload<int>(&QSpinBox::valueChanged), this, &View::changeSize);
	connect(m_ui.probabilitySpinBox, qOverload<int>(&QSpinBox::valueChanged), this, &View::probabilityChanged);

	setColor(m_ui.fromColor, Qt::yellow);
	setColor(m_ui.toColor, Qt::darkMagenta);
}

QSize View::getContentSize() const
{
	return m_ui.content->size();
}

void View::setImage(QImage image)
{
	m_ui.content->setPixmap(QPixmap::fromImage(std::move(image)));
}

void View::changeSize()
{
	emit sizeChanged(QSize(m_ui.widthSpinBox->value(), m_ui.heightSpinBox->value()));
}

void View::selectStartColor()
{
	const QColor color = QColorDialog::getColor();
	if (color.isValid())
	{
		setColor(m_ui.fromColor, color);
		emit startColorSelected(color);
	}
}

void View::selectEndColor()
{
	const QColor color = QColorDialog::getColor();
	if (color.isValid())
	{
		setColor(m_ui.toColor, color);
		emit endColorSelected(color);
	}
}

void View::setColor(QLabel* label, QColor color)
{
	label->setStyleSheet(BackgroundColorTemplate.arg(color.red()).arg(color.green()).arg(color.blue()));
}
