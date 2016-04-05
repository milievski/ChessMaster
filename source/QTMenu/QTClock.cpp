#include "QTClock.h"
#include <iostream>
QTClock::QTClock(bool timeTracker, int miliseconds, QWidget *parent): QWidget(parent)
{


	timer = new QTimer();
	
	if(miliseconds > 0)
	{
		connect(timer, SIGNAL(timeout()), this, SLOT(ClockLoop()));
		iterationTime = miliseconds;
		timer->start(miliseconds);
	}
	else
	{
		connect(timer, SIGNAL(timeout()), this, SLOT(singleSendInfo()));
		iterationTime = 1000;
	}
	count = 1;
	
	keepTrack = timeTracker;

}
QTClock::~QTClock()
{
	
	delete timer;
	
}
void QTClock::ClockLoop()
{
	
	timer->start(iterationTime);
	if (keepTrack)
		count++;
	emit tick(count);
}
void QTClock::SingleClockLoop()
{
	timer->start(iterationTime);
}

void QTClock::singleSendInfo()
{
	emit tick(count);
}

void QTClock::reset()
{
	count = 0;
}
