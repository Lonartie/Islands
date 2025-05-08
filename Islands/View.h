#pragma once

#include <QMainWindow>
#include "ui_View.h"

class View : public QMainWindow
{
	Q_OBJECT

public:
	View(QWidget* parent = nullptr);

	/// @brief Returns the size of the content label
	QSize getContentSize() const;
	
public slots:
	/// @brief Sets the \a image into the content label
	void setImage(QImage image);

signals:
	/// @brief Emitted when the start button was pressed
	void startPressed() const;

	/// @brief Emitted when the start color has been changed
	void startColorSelected(QColor color) const;
	
	/// @brief Emitted when the end color has been changed
	void endColorSelected(QColor color) const;

	/// @brief Emitted when the size has been changed
	void sizeChanged(QSize size) const;

	/// @brief Emitted when the probability value has been changed
	void probabilityChanged(int probability) const;

private:
	void changeSize();
	void selectStartColor();
	void selectEndColor();
	void setColor(QLabel* label, QColor color);

private:
	Ui::View m_ui;
};
