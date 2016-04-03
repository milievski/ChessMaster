/*
	Authors: Michael Wilson, Marko Ilievski
	class: Human Computer Interaction
	file: 
	prof: Wendy Osborn
*/
	
#pragma once
#include <string>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <string>
#include <QMouseEvent>
#include <QImage>

class QTimer;


class QTClock: public QWidget
{
	Q_OBJECT// makes this item a QOBJECT
public:

	/*
		QTClock(bool timeTracker = false, int miliseconds = 1000, QWidget *parent = 0);
		constructor that sets up the clock
		timetracker determines if the time should be tracked
		miliseconds is the refresh rate on the clock
	*/
	QTClock(bool timeTracker = false, int miliseconds = 1000, QWidget *parent = 0);
	/*
		~QTClock();
		destructor
	*/
	~QTClock();
	public slots:
	/*
		void SingleClockLoop();
		connects the clock to a slot so we can loop the timer
	*/
	void SingleClockLoop();
	/*
		void singleSendInfo();
		this emits the clock info to the window that is connected to it

	*/
	void singleSendInfo();
	/*
		void reset();
		resets the timer tracker "count" (how long the clock has been on for)
	*/
	void reset();

	private slots:
	/*
		void ClockLoop();
		connected to the timer and creates a loop
	*/
	void ClockLoop();

	signals:
	/*
		void tick(const int &info);
		tick is the signal that gets emitted with the "count" (how many seconds has past since the timer started)

	*/
	void tick(const int &info);

private:

	//timer for the clock base
QTimer *timer;
// count is the amount of loops that this clock has gone through
int count;
// iterationTime is the amount of time between each tick. how fast the clock will loop
int iterationTime;
// keepTrack will determine whether the program wants to keep track of the amout of loops that have occured
bool keepTrack;



};