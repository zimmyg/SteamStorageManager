#include "ssm.h"
#include "qdebug.h"

ssm::ssm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	fastViewModel = new QStringListModel( this );
	massViewModel = new QStringListModel( this );

	fastViewModel->setStringList( QStringList( { "A", "B", "C" } ) );
	massViewModel->setStringList( QStringList( { "D", "E", "F" } ) );

	ui.fastStorageView->setModel( fastViewModel );
	ui.massStorageView->setModel( massViewModel );

	ui.moveToFastButton->setEnabled( false );
	ui.moveToMassButton->setEnabled( false );
}

ssm::~ssm()
{
	delete fastViewModel;
	delete massViewModel;
}

void ssm::on_moveToFastButton_clicked()
{
	qDebug() << "Move to Fast Clicked!";

	QModelIndexList indices = ui.massStorageView->selectionModel()->selectedIndexes();
	while( indices.size() ) {
		QModelIndex toRemove = indices.first();
		int newRow = fastViewModel->rowCount();

		fastViewModel->insertRow( newRow );
		fastViewModel->setData( fastViewModel->index( newRow ), toRemove.data() );
		
		massViewModel->removeRow( toRemove.row() );

		indices = ui.massStorageView->selectionModel()->selectedIndexes();
	}
}

void ssm::on_moveToMassButton_clicked()
{
	qDebug() << "Move to Mass Clicked!";

	QModelIndexList indices = ui.fastStorageView->selectionModel()->selectedIndexes();
	while( indices.size() ) {
		QModelIndex toRemove = indices.first();
		int newRow = massViewModel->rowCount();

		massViewModel->insertRow( newRow );
		massViewModel->setData( massViewModel->index( newRow ), toRemove.data() );

		fastViewModel->removeRow( toRemove.row() );

		indices = ui.fastStorageView->selectionModel()->selectedIndexes();
	}
}

void ssm::on_fastStorageView_clicked()
{
	ui.moveToFastButton->setEnabled( false );
	ui.moveToMassButton->setEnabled( true );
}

void ssm::on_massStorageView_clicked()
{
	ui.moveToFastButton->setEnabled( true );
	ui.moveToMassButton->setEnabled( false );
}