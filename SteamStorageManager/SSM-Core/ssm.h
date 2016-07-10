#ifndef SSM_H
#define SSM_H

#include <QtWidgets/QMainWindow>
#include "ui_ssm.h"

class ssm : public QMainWindow
{
	Q_OBJECT

public:
	ssm(QWidget *parent = 0);
	~ssm();

private:
	Ui::ssmClass ui;
};

#endif // SSM_H
