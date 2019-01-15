#pragma once

#include <QTimer>
#include <QPushButton>
#include <QHBoxLayout>

#include <atomic>
#include <chrono>
#include <random>
#include <exception>


class Dice : public QWidget
{
Q_OBJECT

public:
	explicit Dice(size_t face_nb = 6, size_t dice_nb = 2, QWidget * parent = nullptr)
		: QWidget(parent)
		, m_FaceCount(face_nb)
		, m_Timer(this)
		, m_RollTime()
		, m_Generator(std::random_device{}())
	{
		if (!face_nb)
		{
			throw std::runtime_error("Dice constructed with no face.");
		}

		QWidget::setLayout(new QHBoxLayout(this));
		QWidget::layout()->setContentsMargins(0,0,0,0);

		connect(&m_Timer, SIGNAL(timeout()), this, SLOT(update()));

		for (size_t i = 0; i < dice_nb; ++i)
		{
			QPushButton * btn = new QPushButton(QString::number(face_nb));
			btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

			connect(btn, SIGNAL(clicked()), this, SLOT(roll()));
			m_Dices.push_back(btn);
			QWidget::layout()->addWidget(btn);
		}

	}

	explicit Dice(std::vector<QString> faces, size_t dice_nb = 1, QWidget * parent = nullptr)
		: Dice(faces.size(), dice_nb, parent)
	{
		m_FaceLabels = faces;
		for ( QPushButton * btn : m_Dices )
		{
			btn->setText(faces.back());
		}
	}

	bool isRunning() const
	{
		return m_Timer.isActive();
	}

private:
	size_t m_FaceCount;
	std::vector<QString> m_FaceLabels;
	std::vector<QPushButton*> m_Dices;

	QTimer m_Timer;
	std::atomic<size_t> m_RollTime;
	std::default_random_engine m_Generator;


signals:

public slots:

	void roll()
	{
		m_RollTime = 10;
		for ( QPushButton * btn : m_Dices )
		{
			btn->setEnabled(false);
		}
		setRandom();

		using namespace std::literals::chrono_literals;
		m_Timer.start(100ms);
	}

	void update()
	{
		if (m_RollTime==0)
		{
			m_Timer.stop();
			for ( QPushButton * btn : m_Dices )
			{
				btn->setEnabled(true);
				btn->setFocus();
			}
		}
		else
		{
			m_RollTime--;
		}
		setRandom();
	}

	void setRandom()
	{
		std::uniform_int_distribution<int> distribution(1,m_FaceCount);

		for ( QPushButton * btn : m_Dices )
		{
			int value = distribution(m_Generator);
			if ( m_FaceLabels.empty() )
			{
				btn->setText( QString::number(value) );
			}
			else
			{
				btn->setText( m_FaceLabels.at(value-1) );
			}
		}
	}

};

