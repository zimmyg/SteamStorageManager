#ifndef SSM_H
#define SSM_H

#include <QtWidgets/QMainWindow>
#include "ui_ssm.h"
#include "qstringlistmodel.h"

class ssm : public QMainWindow
{
	Q_OBJECT

public:
	ssm(QWidget *parent = 0);
	~ssm();

private slots:
	void on_moveToFastButton_clicked();
	void on_moveToMassButton_clicked();

	void on_fastStorageView_clicked();
	void on_massStorageView_clicked();

private:
	Ui::ssmClass ui;

	QStringListModel *fastViewModel;
	QStringListModel *massViewModel;
};

#endif // SSM_H
